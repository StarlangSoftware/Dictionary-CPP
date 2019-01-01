//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "Syllable.h"

/**
 * A constructor of {@link Syllable} class which takes a String as an input and initializes syllable variable with given input.
 *
 * @param syllable String input.
 */
Syllable::Syllable(string syllable) {
    this->syllable = move(syllable);
}

/**
 * Getter for the syllable variable.
 *
 * @return the syllable variable.
 */
string Syllable::getText() {
    return syllable;
}
