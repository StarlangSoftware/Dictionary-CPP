//
// Created by Olcay Taner Yıldız on 4.01.2019.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "TxtDictionary.h"
#include "TxtWord.h"

/**
 * Another constructor of {@link TxtDictionary} class which takes a String filename and a {@link WordComparator} as inputs.
 * And calls its super class {@link Dictionary} with given {@link WordComparator}, assigns given filename input to the
 * filename variable. Then, it calls loadFromText method with given filename.
 *
 * @param filename   String input.
 * @param comparator {@link WordComparator} input.
 */
TxtDictionary::TxtDictionary(string filename, Comparator comparator) : Dictionary(comparator) {
    loadFromText(filename);
    this->filename = move(filename);
}

/**
 * The clone method which creates new {@link TxtDictionary} object with filename and comparator variables.
 *
 * @return new {@link TxtDictionary} object.
 */
TxtDictionary TxtDictionary::clone() {
    return TxtDictionary(filename, comparator);
}

/**
 * The addNumber method takes a String name and calls addWithFlag method with given name and IS_SAYI flag.
 *
 * @param name String input.
 */
void TxtDictionary::addNumber(string name) {
    addWithFlag(move(name), "IS_SAYI");
}

/**
 * The addWithFlag method takes a String name and a flag as inputs. First it creates a {@link TxtWord} word, then if
 * given name is not in words {@link vector} it creates new {@link TxtWord} with given name and assigns it to
 * the word and adds given flag to the word, it also add newly created word to the words {@link vector}'s index
 * found by performing a binary search and return true at the end. If given name is in words {@link java.util.ArrayList},
 * it adds it the given flag to the word.
 *
 * @param name String input.
 * @param flag String flag.
 * @return true if given name is in words {@link java.util.ArrayList}, false otherwise.
 */
bool TxtDictionary::addWithFlag(string name, string flag) {
    return false;
}

/**
 * The addRealNumber method takes a String name and calls addWithFlag method with given name and IS_REELSAYI flag.
 *
 * @param name String input.
 */
void TxtDictionary::addRealNumber(string name) {
    addWithFlag(move(name), "IS_REELSAYI");
}

/**
 * The addFraction method takes a String name and calls addWithFlag method with given name and IS_KESIR flag.
 *
 * @param name String input.
 */
void TxtDictionary::addFraction(string name) {
    addWithFlag(move(name), "IS_KESIR");
}

/**
* The addTime method takes a String name and calls addWithFlag method with given name and IS_ZAMAN flag.
*
* @param name String input.
*/
void TxtDictionary::addTime(string name) {
    addWithFlag(move(name), "IS_ZAMAN");
}

/**
 * The addProperNoun method takes a String name and calls addWithFlag method with given name and IS_OA flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addProperNoun(string name) {
    return addWithFlag(move(name), "IS_OA");
}

/**
 * The addNoun method takes a String name and calls addWithFlag method with given name and CL_ISIM flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addNoun(string name) {
    return addWithFlag(move(name), "CL_ISIM");
}

/**
 * The addVerb method takes a String name and calls addWithFlag method with given name and CL_FIIL flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addVerb(string name) {
    return addWithFlag(move(name), "CL_FIIL");
}

/**
 * The addAdjective method takes a String name and calls addWithFlag method with given name and IS_ADJ flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addAdjective(string name) {
    return addWithFlag(move(name), "IS_ADJ");
}

/**
 * The addAdverb method takes a String name and calls addWithFlag method with given name and IS_ADVERB flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addAdverb(string name) {
    return addWithFlag(move(name), "IS_ADVERB");
}

/**
 * The addPronoun method takes a String name and calls addWithFlag method with given name and IS_ZM flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addPronoun(string name) {
    return addWithFlag(move(name), "IS_ZM");
}

/**
 * The mergeDictionary method takes a String inputs; secondFilename and mergedFilename. It reads given files line by
 * line and splits them according to spaces and write each word to file whichever comes first lexicographically and
 * continue to read files till the end.
 *
 * @param secondFilename String input.
 * @param mergedFilename String input.
 */
void TxtDictionary::mergeDictionary(string secondFilename, string mergedFilename) {
    ifstream firstfile, secondfile;
    ofstream outfile;
    string st1, st2;
    string word1, word2, flag;
    firstfile.open(filename, ifstream :: in);
    secondfile.open(secondFilename, ifstream :: in);
    outfile.open(mergedFilename, ofstream :: out);
    getline(firstfile, st1);
    getline(secondfile, st2);
    while (firstfile.good() && secondfile.good()) {
        word1 = st1.substr(0, st1.find(' '));
        word2 = st2.substr(0, st2.find(' '));
        if (word1 < word2) {
            outfile << st1 + "\n";
            getline(firstfile, st1);
        } else {
            if (word1 > word2) {
                outfile << st2 + "\n";
                getline(secondfile, st2);
            } else {
                flag = st2.substr(st2.find(' ') + 1, st2.find(' ', st2.find(' ') + 1));
                if (st1.find_first_of(flag) != -1) {
                    outfile << st1 + "\n";
                } else {
                    outfile << st1 + " " + flag + "\n";
                }
                getline(firstfile, st1);
                getline(secondfile, st2);
            }
        }
    }
    if (!firstfile.good() && secondfile.good()) {
        while (secondfile.good()) {
            getline(secondfile, st2);
            outfile << st2 + "\n";
        }
    }
    firstfile.close();
    secondfile.close();
    outfile.close();
}

/**
 * The loadFromText method takes a String filename as an input. It reads given file line by line and splits according to space
 * and assigns each word to the String array. Then, adds these word with their flags tot he words {@link java.util.ArrayList}.
 * At the end it sorts the words {@link java.util.ArrayList}.
 *
 * @param filename File input.
 */
void TxtDictionary::loadFromText(string filename) {
    int i;
    string line;
    ifstream inputFile;
    TxtWord* currentWord = new TxtWord("");
    inputFile.open(filename, ifstream :: in);
    while (inputFile.good()) {
        getline(inputFile, line);
        vector<string> tokens = Word::split(line);
        if (!tokens.empty()) {
            currentWord = new TxtWord(tokens[0]);
            for (i = 1; i < tokens.size(); i++) {
                currentWord->addFlag(tokens[i]);
            }
            words.emplace_back(currentWord);
        }
    }
    inputFile.close();
    sort();
}

/**
 * The saveAsTxt method takes a filename as an input and prints out the items of words {@link unordered_set}.
 *
 * @param filename String input.
 */
void TxtDictionary::saveAsTxt(string filename) {
    ofstream outfile;
    int i;
    outfile.open(filename, ofstream :: out);
    for (i = 0; i < words.size(); i++) {
        outfile << words.at(i)->to_string() + "\n";
    }
    outfile.close();
}
