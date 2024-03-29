//
// Created by olcay on 20.02.2019.
//

#ifndef DICTIONARY_VECTORIZEDDICTIONARY_H
#define DICTIONARY_VECTORIZEDDICTIONARY_H


#include "Dictionary.h"
#include "VectorizedWord.h"

class VectorizedDictionary : public Dictionary {
public:
    explicit VectorizedDictionary();
    VectorizedDictionary(const string& fileName);
    void addWord(VectorizedWord* word);
    VectorizedWord* mostSimilarWord(const string& name);
    vector<Word*>* kMeansClustering(int iteration, int k) const;
    vector<VectorizedWord*> mostSimilarKWords(const string& name, int k);
};


#endif //DICTIONARY_VECTORIZEDDICTIONARY_H
