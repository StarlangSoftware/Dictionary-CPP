//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#ifndef DICTIONARY_LANGUAGE_H
#define DICTIONARY_LANGUAGE_H

#include <string>
using namespace std;

class Language {
/**
 * Digits : 0123456789
 * Arithmetic Characters : +-/=\*
 * Extended Language Characters
 */
public:
    static const string DIGITS;
    static const string ARITHMETIC_CHARACTERS;
    static const string EXTENDED_LANGUAGE_CHARACTERS;
};

const string Language::DIGITS = "0123456789";
const string Language::ARITHMETIC_CHARACTERS = "+-*/=";
const string Language::EXTENDED_LANGUAGE_CHARACTERS = "âàáäãèéêëíîòóôûúqwxÂÈÉÊËÌÒÛQWX";

#endif //DICTIONARY_LANGUAGE_H
