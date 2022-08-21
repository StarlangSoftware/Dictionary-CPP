//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "ExceptionalWord.h"

/**
 * A constructor of {@link ExceptionalWord} class which takes a {@link Pos} as a  part of speech and two Strings; name
 * and root as inputs. Then, calls its super class {@link Word} with given name and initialises root and pos variables
 * with given inputs.
 *
 * @param name String input.
 * @param root String input.
 * @param pos  {@link Pos} type input.
 */
ExceptionalWord::ExceptionalWord(string name, string root, Pos pos) : Word(move(name)) {
    this->root = move(root);
    this->pos = move(pos);
}

/**
 * Getter for the root variable.
 *
 * @return root variable.
 */
string ExceptionalWord::getRoot() {
    return root;
}

/**
 * Getter for the pos variable.
 *
 * @return pos variable.
 */
Pos ExceptionalWord::getPos() {
    return pos;
}
