//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_TXTWORD_H
#define DICTIONARY_TXTWORD_H

#include<vector>
#include <string>
#include "Word.h"

using namespace std;

class TxtWord : public Word {
private:
    vector<string> flags;
public:
    TxtWord(string name);
    TxtWord(string name, string flag);
    void addFlag(string flag);
    TxtWord clone();
    void removeFlag(string flag);
};


#endif //DICTIONARY_TXTWORD_H
