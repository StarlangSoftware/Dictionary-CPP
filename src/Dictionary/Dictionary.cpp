//
// Created by Olcay Taner Yıldız on 2.01.2019.
//
#include <locale>
#include <map>
#include "Dictionary.h"

bool compareWord(Word* wordA, Word* wordB)
{
    return wordA->getName() < wordB->getName();
}

/**
 * An empty constructor of {@link Dictionary} class.
 */
Dictionary::Dictionary() = default;

/**
 * Another constructor of {@link Dictionary} class which takes a {@link comparator} as an input and initializes
 * comparator variable with given input and also creates a new words {@link vector}.
 *
 * @param comparator {@link Compare} type input.
 */
Dictionary::Dictionary(Comparator comparator) {
    this->comparator = comparator;
    switch (comparator){
        case Comparator::TURKISH:
            comparatorMap = Dictionary::turkishComparatorMap;
            break;
        case Comparator ::TURKISH_NO_CASE:
            comparatorMap = Dictionary::turkishIgnoreCaseComparatorMap;
            break;
        case Comparator ::ENGLISH:
            break;
    }
    turkishComparator = turkishWordComparator(comparatorMap);
}


/**
 * The getWord method takes a String name as an input and performs binary search within words {@link vector} and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the item at index middle of words {@link vector}, null otherwise.
 *
 * @param name String input.
 * @return the item at found index of words {@link vector}, null if cannot be found.
 */
Word* Dictionary::getWord(string name) {
    if (wordExists(name)){
        vector<Word*>::iterator middle;
        switch (comparator){
            case Comparator::ENGLISH:
                middle = lower_bound(words.begin(), words.end(), new Word(name), compareWord);
                break;
            case Comparator::TURKISH:
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishComparator);
        }
        return *middle;
    }
    return nullptr;
}

/**
 * RemoveWord removes a word with the given name
 * @param name Name of the word to be removed.
 */
void Dictionary::removeWord(string name) {
    if (wordExists(name)){
        vector<Word*>::iterator middle;
        switch (comparator){
            case Comparator::ENGLISH:
                middle = lower_bound(words.begin(), words.end(), new Word(name), compareWord);
                words.erase(middle);
                break;
            case Comparator::TURKISH:
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishWordComparator(comparatorMap));
                words.erase(middle);
        }
    }
}

bool Dictionary::wordExists(string name) {
    bool result;
    switch (comparator){
        case Comparator::ENGLISH:
            result = binary_search(words.begin(), words.end(), new Word(name), compareWord);
            break;
        case Comparator::TURKISH:
        case Comparator::TURKISH_NO_CASE:
            result = binary_search(words.begin(), words.end(), new Word(name), turkishWordComparator(comparatorMap));
            break;
    }
    return result;
}

/**
 * The getWordIndex method takes a String name as an input and performs binary search within words {@link vector} and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -1 otherwise.
 *
 * @param name String input.
 * @return found index of words {@link vector}, -1 if cannot be found.
 */
int Dictionary::getWordIndex(string name) {
    if (wordExists(name)){
        vector<Word*>::iterator middle;
        switch (comparator){
            case Comparator::ENGLISH:
                middle = lower_bound(words.begin(), words.end(), new Word(name), compareWord);
                break;
            case Comparator::TURKISH:
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishComparator);
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
Word* Dictionary::getWord(unsigned long index) {
    return words.at(index);
}

/**
 * The longestWordSize method loops through the words {@link vector} and returns the item with the maximum word length.
 *
 * @return the item with the maximum word length.
 */
unsigned long Dictionary::longestWordSize() {
    unsigned long max = 0;
    for (Word* word : words) {
        if (Word::size(word->getName()) > max) {
            max = Word::size(word->getName());
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
    vector<Word*>::iterator middle;
    switch (comparator){
        case Comparator::ENGLISH:
            middle = lower_bound(words.begin(), words.end(), new Word(hash), compareWord);
            break;
        case Comparator::TURKISH:
        case Comparator::TURKISH_NO_CASE:
            middle = lower_bound(words.begin(), words.end(), new Word(hash), turkishComparator);
            break;
    }
    return middle - words.begin();
}

void Dictionary::sort() {
    switch (comparator){
        case Comparator::ENGLISH:
            std::sort(words.begin(), words.end(), compareWord);
            break;
        case Comparator::TURKISH:
        case Comparator::TURKISH_NO_CASE:
            std::sort(words.begin(), words.end(), turkishWordComparator(comparatorMap));
            break;
    }
}
