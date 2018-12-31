//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#ifndef DICTIONARY_WORD_H
#define DICTIONARY_WORD_H

#include <string>
using namespace std;

class Word {
private:
    string name;
public:
    Word();
    Word(string name);
    string to_string();
    int charCount();
    Word clone();
    string getName();
    void setName(string name);
};


#endif //DICTIONARY_WORD_H
