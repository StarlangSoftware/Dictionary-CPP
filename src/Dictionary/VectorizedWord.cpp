//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#include "VectorizedWord.h"

/**
 * A constructor of  {@link VectorizedWord} class which takes a String and a {@link Vector} as inputs and calls its
 * super class {@link Word} with name and also initializes vector variable with given input.
 *
 * @param name   Strin input.
 * @param vector {@link Vector} type input.
 */
VectorizedWord::VectorizedWord(const string& name, const Vector& vector) : Word(name) {
    this->vector = vector;
}

/**
 * Getter for the vector variable.
 *
 * @return the vector variable.
 */
Vector VectorizedWord::getVector() {
    return vector;
}
