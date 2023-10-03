//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "Syllable.h"

/**
 * A constructor of Syllable class which takes a String as an input and initializes _syllable variable with given input.
 *
 * @param _syllable String input.
 */
Syllable::Syllable(const string& _syllable) {
    this->syllable = _syllable;
}

/**
 * Getter for the syllable variable.
 *
 * @return the syllable variable.
 */
string Syllable::getText() const{
    return syllable;
}
