//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#ifndef DICTIONARY_SYLLABLE_H
#define DICTIONARY_SYLLABLE_H
#include<string>
using namespace std;

class Syllable {
private:
    string syllable;
public:
    explicit Syllable(const string& _syllable);
    string getText() const;
};


#endif //DICTIONARY_SYLLABLE_H
