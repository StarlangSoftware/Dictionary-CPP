//
// Created by Olcay Taner Yıldız on 2.01.2019.
//
#include<clocale>
#include <locale>
#include <iostream>
#include "Dictionary.h"

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
}

struct englishWordComparator{
/**
 * The wordComparator takes two {@link Word}s as inputs; wordA and wordB and compares their names. Returns the result of this comparison.
 *
 * @param wordA Word type input.
 * @param wordB Word type input.
 * @return the value {@code 0} if the wordA is equal to the wordB; a value less than {@code 0} if this wordA is
 * lexicographically less than wordB; and a value greater than {@code 0} if this wordA is lexicographically greater
 * than wordB.
 */
    bool operator() (Word* wordA, Word* wordB){
        const auto & col = use_facet<collate<char>>(std::locale());
        string nameA = wordA->getName();
        string nameB = wordB->getName();
        return (col.compare(nameA.data(), nameA.data() + nameA.size(), nameB.data(), nameB.data() + nameB.size()) < 0);
    }
};


struct turkishWordComparator{
/**
 * The wordComparator takes two {@link Word}s as inputs; wordA and wordB and compares their names. Returns the result of this comparison.
 *
 * @param wordA Word type input.
 * @param wordB Word type input.
 * @return the value {@code 0} if the wordA is equal to the wordB; a value less than {@code 0} if this wordA is
 * lexicographically less than wordB; and a value greater than {@code 0} if this wordA is lexicographically greater
 * than wordB.
 */
    bool operator() (Word* wordA, Word* wordB){
        const auto & col = use_facet<collate<char>>(std::locale());
        string nameA = wordA->getName();
        string nameB = wordB->getName();
        return (col.compare(nameA.data(), nameA.data() + nameA.size(), nameB.data(), nameB.data() + nameB.size()) < 0);
    }
};

struct turkishIgnoreCaseWordComparator{
/**
 * The compare method takes two {@link Word}s as inputs; wordA and wordB and compares their names. First it creates
 * a {@link Locale} object which represents a specific geographical, political, or cultural region  and an instance of
 * {@link Collator} which performs locale-sensitive String comparison. Then, it returns the result of this comparison.
 *
 * @param wordA Word type input.
 * @param wordB Word type input.
 * @return the value {@code 0} if the wordA is equal to the wordB; a value less than {@code 0} if this wordA is
 * lexicographically less than wordB; and a value greater than {@code 0} if this wordA is lexicographically greater
 * than wordB.
 */
    bool operator() (Word* wordA, Word* wordB){
        const auto & col = use_facet<collate<char>>(std::locale());
        string nameA = wordA->getName();
        string nameB = wordB->getName();
        std::transform(nameA.begin(), nameA.end(), nameA.begin(), ::tolower);
        std::transform(nameB.begin(), nameB.end(), nameB.begin(), ::tolower);
        return (col.compare(nameA.data(), nameA.data() + nameA.size(), nameB.data(), nameB.data() + nameB.size()) < 0);
    }
};

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
                middle = lower_bound(words.begin(), words.end(), new Word(name), englishWordComparator());
                break;
            case Comparator::TURKISH:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishWordComparator());
                break;
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishIgnoreCaseWordComparator());
                break;
        }
        return *middle;
    }
}

bool Dictionary::wordExists(string name) {
    bool result;
    switch (comparator){
        case Comparator::ENGLISH:
            result = binary_search(words.begin(), words.end(), new Word(name), englishWordComparator());
            break;
        case Comparator::TURKISH:
            result = binary_search(words.begin(), words.end(), new Word(name), turkishWordComparator());
            break;
        case Comparator::TURKISH_NO_CASE:
            result = binary_search(words.begin(), words.end(), new Word(name), turkishIgnoreCaseWordComparator());
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
                middle = lower_bound(words.begin(), words.end(), new Word(name), englishWordComparator());
                break;
            case Comparator::TURKISH:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishWordComparator());
                break;
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishIgnoreCaseWordComparator());
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
        if (word->getName().size() > max) {
            max = word->getName().size();
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
            middle = lower_bound(words.begin(), words.end(), new Word(hash), englishWordComparator());
            break;
        case Comparator::TURKISH:
            middle = lower_bound(words.begin(), words.end(), new Word(hash), turkishWordComparator());
            break;
        case Comparator::TURKISH_NO_CASE:
            middle = lower_bound(words.begin(), words.end(), new Word(hash), turkishIgnoreCaseWordComparator());
            break;
    }
    return middle - words.begin();
}

void Dictionary::sort() {
    switch (comparator){
        case Comparator::ENGLISH:
            std::stable_sort(words.begin(), words.end(), englishWordComparator());
            break;
        case Comparator::TURKISH:
            std::stable_sort(words.begin(), words.end(), turkishWordComparator());
            break;
        case Comparator::TURKISH_NO_CASE:
            std::stable_sort(words.begin(), words.end(), turkishIgnoreCaseWordComparator());
            break;
    }
}
