//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include <utility>
#include<vector>
#include<map>
#include <locale>
#include "Word.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Dictionary {
private:
    unordered_map<string, int> wordMap;
    void updateWordMap();
protected:
    vector<Word*> words;
    string filename;
public:
    static const map<string, int> turkishComparatorMap;
    static const map<string, int> turkishIgnoreCaseComparatorMap;
    Dictionary();
    Word* getWord(const string& name);
    void removeWord(const string& name);
    int binarySearch(Word* word) const;
    int getWordIndex(const string& name);
    bool wordExists(const string& name) const;
    unsigned long size() const;
    Word* getWord(int index) const;
    unsigned long longestWordSize() const;
    unsigned long getWordStartingWith(const string& hash) const;
    void sort();
};

#endif //DICTIONARY_DICTIONARY_H
