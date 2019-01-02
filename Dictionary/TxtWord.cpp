//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#include "TxtWord.h"

/**
 * A constructor of {@link TxtWord} class which takes a String name as an input and calls its super class {@link Word}
 * with given name. Then, creates a new {@link vector} as flags.
 *
 * @param name String name.
 */
TxtWord::TxtWord(string name) {
    this->name = move(name);
}

/**
 * The addFlag method takes a String flag as an input and adds given flag to the flags {@link vector}.
 *
 * @param flag String input to add.
 */
void TxtWord::addFlag(string flag) {
    flags.push_back(flag);
}

/**
 * Another constructor of {@link TxtWord} class which takes a String name and a flag as inputs and calls its super class {@link Word}
 * with given name. Then, creates a new {@link vector} as flags and calls addFlag method with given flag.
 *
 * @param name String input.
 * @param flag String input.
 */
TxtWord::TxtWord(string name, string flag) {
    this->name = move(name);
    addFlag(move(flag));
}

/**
 * The clone method creates {@link TxtWord} type copy with name and add items of flags {@link vector}  to the copy.
 *
 * @return TxtWord type copy.
 */
TxtWord TxtWord::clone() {
    unsigned long i;
    TxtWord copy = TxtWord(name);
    for (i = 0; i < flags.size(); i++) {
        copy.addFlag(flags.at(i));
    }
    return copy;
}

/**
 * The removeFlag method takes a String flag as an input and removes given flag from the flags {@link ArrayList}.
 *
 * @param flag String input to remove.
 */
void TxtWord::removeFlag(string flag) {
    flags
}
