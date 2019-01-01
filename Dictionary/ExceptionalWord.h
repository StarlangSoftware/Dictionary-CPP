//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#ifndef DICTIONARY_EXCEPTIONALWORD_H
#define DICTIONARY_EXCEPTIONALWORD_H
#include<string>
#include "Pos.h"

using namespace std;

class ExceptionalWord {
private:
    string root;
    Pos pos;
public:
    ExceptionalWord(string name, string root, Pos pos);
    string getRoot();
    Pos getPos();
};


#endif //DICTIONARY_EXCEPTIONALWORD_H
