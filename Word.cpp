//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#include "Word.h"

/**
 * An empty constructor of {@link Word} class.
 */
Word::Word() {
}

/**
 * A constructor of {@link Word} class which gets a String name as an input and assigns to the name variable.
 *
 * @param name String input.
 */
Word::Word(string name) {
    this->name = move(name);
}

/**
 * The overridden to_string method returns the name variable.
 *
 * @return the name variable.
 */
string Word::to_string() {
    return name;
}

/**
 * The charCount method returns the length of name variable.
 *
 * @return the length of name variable.
 */
int Word::charCount() {
    return name.size();
}

/**
 * The clone method returns new {@link Word} as name.
 *
 * @return new {@link Word} as name.
 */
Word Word::clone() {
    return Word(name);
}

/**
 * Getter for the name variable.
 *
 * @return name variable.
 */
string Word::getName() {
    return name;
}

/**
 * Setter for the name variable.
 *
 * @param name String input.
 */
void Word::setName(string name) {
    this->name = move(name);
}
