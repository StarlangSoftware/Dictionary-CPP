//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#include "Dictionary.h"

/**
 * An empty constructor of {@link Dictionary} class.
 */
Dictionary::Dictionary() {
}

/**
 * Another constructor of {@link Dictionary} class which takes a {@link comparator} as an input and initializes
 * comparator variable with given input and also creates a new words {@link vector}.
 *
 * @param comparator {@link Compare} type input.
 */
Dictionary::Dictionary(Comparator comparator) {
    this->comparator = comparator;
}

/**
 * The getWord method takes a String name as an input and performs binary search within words {@link vector} and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the item at index middle of words {@link vector}, null otherwise.
 *
 * @param name String input.
 * @return the item at found index of words {@link vector}, null if cannot be found.
 */
Word Dictionary::getWord(string name) {
    if (wordExists(name)){
        vector<Word>::iterator middle;
        switch (comparator){
            case Comparator::ENGLISH:
                middle = lower_bound(words.begin(), words.end(), Word(name), EnglishWordComparator);
                break;
            case Comparator::TURKISH:
                middle = lower_bound(words.begin(), words.end(), Word(name), TurkishWordComparator);
                break;
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), Word(name), TurkishIgnoreCaseWordComparator);
                break;
        }
        return *middle;
    }
}

bool Dictionary::wordExists(string name) {
    switch (comparator){
        case Comparator::ENGLISH:
            return binary_search(words.begin(), words.end(), Word(name), EnglishWordComparator);
        case Comparator::TURKISH:
            return binary_search(words.begin(), words.end(), Word(name), TurkishWordComparator);
        case Comparator::TURKISH_NO_CASE:
            return binary_search(words.begin(), words.end(), Word(name), TurkishIgnoreCaseWordComparator);
    }
}

/**
 * The getWordIndex method takes a String name as an input and performs binary search within words {@link vector} and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -1 otherwise.
 *
 * @param name String input.
 * @return found index of words {@link vector}, -1 if cannot be found.
 */
unsigned long Dictionary::getWordIndex(string name) {
    if (wordExists(name)){
        vector<Word>::iterator middle;
        switch (comparator){
            case Comparator::ENGLISH:
                middle = lower_bound(words.begin(), words.end(), Word(name), EnglishWordComparator);
                break;
            case Comparator::TURKISH:
                middle = lower_bound(words.begin(), words.end(), Word(name), TurkishWordComparator);
                break;
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), Word(name), TurkishIgnoreCaseWordComparator);
                break;
        }
        return middle - words.begin();
    } else {
        return -1;
    }
}

/**
 * The size method returns the size of the words {@link vector}.
 *
 * @return the size of the words {@link vector}.
 */
unsigned long Dictionary::size() {
    return words.size();
}

/**
 * The getWord method which takes an index as an input and returns the value at given index of words {@link vector}.
 *
 * @param index to get the value.
 * @return the value at given index of words {@link vector}.
 */
Word Dictionary::getWord(unsigned long index) {
    return words.at(index);
}

/**
 * The longestWordSize method loops through the words {@link vector} and returns the item with the maximum word length.
 *
 * @return the item with the maximum word length.
 */
unsigned long Dictionary::longestWordSize() {
    unsigned long max = 0;
    for (const Word &word : words) {
        if (word.getName().size() > max) {
            max = word.getName().size();
        }
    }
    return max;
}

/**
 * The getWordStartingWith method takes a String hash as an input and performs binary search within words {@link ArrayList} and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -middle-1 otherwise.
 *
 * @param hash String input.
 * @return found index of words {@link vector}, -middle-1 if cannot be found.
 */
unsigned long Dictionary::getWordStartingWith(string hash) {
    vector<Word>::iterator middle;
    switch (comparator){
        case Comparator::ENGLISH:
            middle = lower_bound(words.begin(), words.end(), Word(hash), EnglishWordComparator);
            break;
        case Comparator::TURKISH:
            middle = lower_bound(words.begin(), words.end(), Word(hash), TurkishWordComparator);
            break;
        case Comparator::TURKISH_NO_CASE:
            middle = lower_bound(words.begin(), words.end(), Word(hash), TurkishIgnoreCaseWordComparator);
            break;
    }
    return middle - words.begin();
}
