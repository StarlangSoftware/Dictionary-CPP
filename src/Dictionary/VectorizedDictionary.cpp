//
// Created by olcay on 20.02.2019.
//

#include <cfloat>
#include <cmath>
#include <fstream>
#include "VectorSizeMismatch.h"
#include "VectorizedDictionary.h"
#include <StringUtils.h>

/**
 * A constructor of VectorizedDictionary class that calls its super class Dictionary.
 */
VectorizedDictionary::VectorizedDictionary() : Dictionary() {
}

/**
 * Another constructor of {@link VectorizedDictionary} class that takes an input file
 * containing the word vectors as input. Line j contains an array of numbers that represent the word vector for
 * that corresponding word at index j.
 * @param fileName Name of the input file that contains the word vectors
 */
VectorizedDictionary::VectorizedDictionary(const string &fileName) : Dictionary() {
    ifstream inputFile;
    string line;
    inputFile.open(fileName, ifstream :: in);
    while (inputFile.good()) {
        getline(inputFile, line);
        vector<string> tokens = StringUtils::split(line);
        if (!tokens.empty()) {
            VectorizedWord* currentWord;
            Vector vector = Vector((long) 0, 0);
            for (int i = 1; i < tokens.size(); i++){
                vector.add(stof(tokens[i]));
            }
            currentWord = new VectorizedWord(tokens[0], vector);
            words.emplace_back(currentWord);
        }
    }
    inputFile.close();
    sort();
}

/**
 * The addWord method takes a VectorizedWord as an input and adds it to the words ArrayList.
 *
 * @param word VectorizedWord input.
 */
void VectorizedDictionary::addWord(VectorizedWord *word) {
    words.emplace_back(word);
}

/**
 * The mostSimilarWord method takes a String name as an input, declares a maxDistance as -MAX_VALUE and creates a
 * VectorizedWord word by getting the given name from words ArrayList. Then, it loops through the
 * words ArrayList and if the current word is not equal to given input it calculates the distance between current
 * word and given word by using dot product and updates the maximum distance. It then returns the result VectorizedWord
 * which holds the most similar word to the given word.
 *
 * @param name String input.
 * @return VectorizedWord type result which holds the most similar word to the given word.
 */
VectorizedWord* VectorizedDictionary::mostSimilarWord(const string& name){
    double maxDistance = -DBL_MAX;
    VectorizedWord* result = nullptr;
    auto* word = (VectorizedWord*) getWord(name);
    if (word == nullptr) {
        return nullptr;
    }
    for (Word* currentWord : words) {
        auto* current = (VectorizedWord*) currentWord;
        if (current->getName() != word->getName()) {
            double distance = 0;
            try {
                distance = word->getVector().dotProduct(current->getVector());
            } catch (VectorSizeMismatch& vectorSizeMismatch) {
            }
            if (distance > maxDistance) {
                maxDistance = distance;
                result = current;
            }
        }
    }
    return result;
}

/**
 * The kMeansClustering method takes an integer iteration and k as inputs. K-means clustering aims to partition n observations
 * into k clusters in which each observation belongs to the cluster with the nearest mean.
 *
 * @param iteration Integer input.
 * @param k         Integer input.
 * @return ArrayList result which holds the k-means clustered words.
 */
vector<Word*>*VectorizedDictionary::kMeansClustering(int iteration, int k) const{
    auto* result = new vector<Word*>[k];
    vector<Vector> means;
    int vectorSize = ((VectorizedWord*) words.at(0))->getVector().getSize();
    for (int i = 0; i < k; i++) {
        means.emplace_back(vectorSize, 0);
    }
    for (int i = 0; i < words.size(); i++) {
        result[i % k].emplace_back(words.at(i));
        try {
            means[i % k].add(((VectorizedWord*) words.at(i))->getVector());
        } catch (VectorSizeMismatch vectorSizeMismatch) {
        }
    }
    for (int i = 0; i < k; i++) {
        means[i].divide(result[i].size());
        means[i].divide(sqrt(means[i].dotProduct()));
    }
    for (int i = 0; i < iteration; i++) {
        for (int j = 0; j < k; j++) {
            result[j].clear();
        }
        for (Word* word : words) {
            auto* vectorizedWord = (VectorizedWord*) word;
            double maxClusterDistance = 0;
            try {
                maxClusterDistance = means[0].dotProduct(vectorizedWord->getVector());
            } catch (VectorSizeMismatch vectorSizeMismatch) {
            }
            int maxClusterIndex = 0;
            for (int j = 1; j < k; j++) {
                double clusterDistance = 0;
                try {
                    clusterDistance = means[j].dotProduct(vectorizedWord->getVector());
                } catch (VectorSizeMismatch& vectorSizeMismatch) {
                }
                if (clusterDistance > maxClusterDistance) {
                    maxClusterDistance = clusterDistance;
                    maxClusterIndex = j;
                }
            }
            result[maxClusterIndex].emplace_back(word);
        }
        for (int j = 0; j < k; j++) {
            means[j].clear();
            for (Word* word : result[j]) {
                try {
                    means[j].add(((VectorizedWord*) (word))->getVector());
                } catch (VectorSizeMismatch& vectorSizeMismatch) {
                }
            }
            means[j].divide(result[j].size());
            means[j].divide(sqrt(means[j].dotProduct()));
        }
    }
    return result;
}

struct vectorizedWordComparator{
    VectorizedWord* comparedWord = nullptr;

    vectorizedWordComparator(VectorizedWord* comparedWord){
        this->comparedWord = comparedWord;
    }
    /**
     * The compare method takes two VectorizedWords as inputs and finds out the dot products as result1
     * and result2, then it calls the compare method wirth result1 and result2. It returns the value {@code 0}
     * if result1 is  numerically equal to result2; a value less than {@code 0} if result1 is numerically less than
     * result2; and a value greater than {@code 0} if result1 is numerically greater than result2.
     *
     * @param wordA VectorizedWord type input.
     * @param wordB VectorizedWord type input.
     * @return the value {@code 0} if result1 is  numerically equal to result2; a value less than {@code 0} if
     * result1 is numerically less than result2; and a value greater than {@code 0} if result1 is numerically
     * greater than result2.
     */
    bool operator() (VectorizedWord* wordA, VectorizedWord* wordB) const {
        Vector v = comparedWord->getVector(), vA = wordA->getVector(), vB = wordB->getVector();
        double result1 = 0, result2 = 0;
        try {
            result1 = v.dotProduct(vB) / sqrt(v.dotProduct() * vB.dotProduct());
            result2 = v.dotProduct(vA) / sqrt(v.dotProduct() * vA.dotProduct());
        } catch (VectorSizeMismatch& vectorSizeMismatch) {
        }
        return result1 < result2;
    }
};

/**
 * The mostSimilarKWords method takes a String name and an integer k as inputs, and creates an vector resultWords
 * of type VectorizedWord and a VectorizedWord word by getting the given name from words vector.
 * Then, it loops through the words vector and adds current word to the resultWords. It then sort resultWords vector
 * and if the size of the vector is greater than given input k, it removes items from the ending. Then, it returns
 * resultWords vector.
 *
 * @param name String input.
 * @param k Integer input.
 * @return ArrayList result.
 */
vector<VectorizedWord *> VectorizedDictionary::mostSimilarKWords(const string& name, int k){
    vector<VectorizedWord*> resultWords;
    auto* word = (VectorizedWord*) getWord(name);
    if (word == nullptr) {
        return resultWords;
    }
    for (Word* currentWord : words) {
        resultWords.emplace_back((VectorizedWord*) currentWord);
    }
    stable_sort(resultWords.begin(), resultWords.end(), vectorizedWordComparator(word));
    resultWords.resize(k);
    return resultWords;
}
