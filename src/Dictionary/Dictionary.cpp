//
// Created by Olcay Taner Yıldız on 2.01.2019.
//
#include <locale>
#include "Dictionary.h"

bool compareWord(Word* wordA, Word* wordB)
{
    return wordA->getName() < wordB->getName();
}

/**
 * An empty constructor of Dictionary class.
 */
Dictionary::Dictionary() = default;

/**
 * The getWord method takes a String name as an input and performs binary search within words vector and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the item at index middle of words vector, null otherwise.
 *
 * @param name String input.
 * @return the item at found index of words vector, null if cannot be found.
 */
Word* Dictionary::getWord(const string& name){
    if (wordExists(name)){
        int index = wordMap[name];
        return words[index];
    }
    return nullptr;
}

/**
 * RemoveWord removes a word with the given name
 * @param name Name of the word to be removed.
 */
void Dictionary::removeWord(const string& name) {
    if (wordExists(name)){
        int index = wordMap[name];
        words.erase(words.begin() + index);
    }
    updateWordMap();
}

/**
 * Checks if a word in the dictionary exists for a given name.
 * @param name Input word
 * @return True, if the word exists, false otherwise.
 */
bool Dictionary::wordExists(const string& name) const{
    return wordMap.contains(name);
}

/**
 * The getWordIndex method takes a String name as an input and performs binary search within words vector and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -1 otherwise.
 *
 * @param name String input.
 * @return found index of words vector, -1 if cannot be found.
 */
int Dictionary::getWordIndex(const string& name){
    if (wordExists(name)){
        return wordMap[name];
    } else {
        return -1;
    }
}

/**
 * The size method returns the size of the words vector.
 *
 * @return the size of the words vector.
 */
unsigned long Dictionary::size() const{
    return words.size();
}

/**
 * The getWord method which takes an index as an input and returns the value at given index of words vector.
 *
 * @param index to get the value.
 * @return the value at given index of words vector.
 */
Word* Dictionary::getWord(int index) const{
    return words.at(index);
}

/**
 * The longestWordSize method loops through the words vector and returns the item with the maximum word length.
 *
 * @return the item with the maximum word length.
 */
unsigned long Dictionary::longestWordSize() const{
    unsigned long max = 0;
    for (Word* word : words) {
        if (Word::size(word->getName()) > max) {
            max = Word::size(word->getName());
        }
    }
    return max;
}

/**
 * The getWordStartingWith method takes a String hash as an input and performs binary search within words ArrayList and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -middle-1 otherwise.
 *
 * @param hash String input.
 * @return found index of words vector, -middle-1 if cannot be found.
 */
unsigned long Dictionary::getWordStartingWith(const string& hash) const{
    return binarySearch(new Word(hash));
}

/**
 * Sorts the words array according to the comparator function.
 */
void Dictionary::sort() {
    std::sort(words.begin(), words.end(), compareWord);
    updateWordMap();
}

/**
 * Checks if a given word exists in the dictionary by performing a binary search on the words array.
 * @param word Searched word
 * @return the index of the search word, if it is contained in the words array; otherwise, (-(insertion point) - 1). The
 * insertion point is defined as the point at which the word would be inserted into the words array.
 */
int Dictionary::binarySearch(Word *word) const {
    int lo = 0;
    int hi = words.size() - 1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (words[mid]->getName() == word->getName()){
            return mid;
        }
        if (compareWord(words[mid], word)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -(lo + 1);
}

/**
 * Updates word map so that word index at i is in the hash map with key word and value i.
 */
void Dictionary::updateWordMap() {
    for (int i = 0; i < words.size(); i++){
        wordMap[words[i]->getName()] = i;
    }
}
