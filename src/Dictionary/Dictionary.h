//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include<vector>
#include "Word.h"
#include <unordered_map>

using namespace std;

class Dictionary {
private:
    unordered_map<string, int> wordMap;
protected:
    vector<Word*> words;
    string filename;
public:
    Dictionary();
    Word* getWord(const string& name);
    void removeWord(const string& name);
    int binarySearch(const Word* word) const;
    int getWordIndex(const string& name);
    [[nodiscard]] bool wordExists(const string& name) const;
    [[nodiscard]] unsigned long size() const;
    [[nodiscard]] Word* getWord(int index) const;
    [[nodiscard]] unsigned long longestWordSize() const;
    [[nodiscard]] unsigned long getWordStartingWith(const string& hash) const;
    void sort();
    void updateWordMap();
};

#endif //DICTIONARY_DICTIONARY_H
