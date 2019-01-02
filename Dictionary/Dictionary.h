//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include<vector>
#include "Word.h"
#include "Compare.h"

using namespace std;

class Dictionary {
protected:
    vector<Word> words;
    string filename;
    Comparator comparator;
public:
    Dictionary();
    Dictionary(Comparator comparator);
    Word getWord(string name);
    unsigned long getWordIndex(string name);
    bool wordExists(string name);
    unsigned long size();
    Word getWord(unsigned long index);
    unsigned long longestWordSize();
    unsigned long getWordStartingWith(string hash);
};


#endif //DICTIONARY_DICTIONARY_H
