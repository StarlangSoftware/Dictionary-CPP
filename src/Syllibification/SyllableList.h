//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#ifndef DICTIONARY_SYLLABLELIST_H
#define DICTIONARY_SYLLABLELIST_H

#include<vector>
#include "Syllable.h"

class SyllableList {
private:
    vector<Syllable> syllables;
public:
    explicit SyllableList(const string& word);
    vector<string> getSyllables();
};


#endif //DICTIONARY_SYLLABLELIST_H
