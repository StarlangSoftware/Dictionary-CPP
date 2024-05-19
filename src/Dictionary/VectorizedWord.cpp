//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#include "VectorizedWord.h"

/**
 * A constructor of  VectorizedWord class which takes a String and a Vector as inputs and calls its
 * super class Word with name and also initializes vector variable with given input.
 *
 * @param name   String input.
 * @param vector Vector type input.
 */
VectorizedWord::VectorizedWord(const string& name, const Vector& vector) : Word(name) {
    this->vector = vector;
}

/**
 * Getter for the vector variable.
 *
 * @return the vector variable.
 */
Vector VectorizedWord::getVector() const{
    return vector;
}
