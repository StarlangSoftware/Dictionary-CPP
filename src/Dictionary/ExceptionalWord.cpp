//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "ExceptionalWord.h"

/**
 * A constructor of ExceptionalWord class which takes a Pos as a  part of speech and two Strings; name
 * and root as inputs. Then, calls its super class Word with given name and initialises root and pos variables
 * with given inputs.
 *
 * @param name String input.
 * @param root String input.
 * @param pos  Pos type input.
 */
ExceptionalWord::ExceptionalWord(const string& name, const string& root, Pos pos) : Word(name) {
    this->root = root;
    this->pos = pos;
}

/**
 * Getter for the root variable.
 *
 * @return root variable.
 */
string ExceptionalWord::getRoot() const{
    return root;
}

/**
 * Getter for the pos variable.
 *
 * @return pos variable.
 */
Pos ExceptionalWord::getPos() const{
    return pos;
}
