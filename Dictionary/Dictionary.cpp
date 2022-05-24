//
// Created by Olcay Taner Yıldız on 2.01.2019.
//
#include<clocale>
#include <locale>
#include <iostream>
#include <map>
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
    switch (comparator){
        case Comparator::TURKISH:
            comparatorMap.emplace("a", 0);comparatorMap.emplace("â", 0);comparatorMap.emplace("á", 0);comparatorMap.emplace("å", 0);comparatorMap.emplace("ã", 0);comparatorMap.emplace("ä", 0);comparatorMap.emplace("b", 1);
            comparatorMap.emplace("c", 2);comparatorMap.emplace("ç", 3);comparatorMap.emplace("d", 4);
            comparatorMap.emplace("e", 5);comparatorMap.emplace("é", 5);comparatorMap.emplace("æ", 5);comparatorMap.emplace("f", 6);comparatorMap.emplace("g", 7);
            comparatorMap.emplace("ğ", 8);comparatorMap.emplace("h", 9);comparatorMap.emplace("ı", 10);comparatorMap.emplace("í", 10);
            comparatorMap.emplace("i", 11);comparatorMap.emplace("î", 11);comparatorMap.emplace("ï", 11);comparatorMap.emplace("j", 12);
            comparatorMap.emplace("k", 13);comparatorMap.emplace("l", 14);comparatorMap.emplace("m", 15);
            comparatorMap.emplace("n", 16);comparatorMap.emplace("o", 17);comparatorMap.emplace("ó", 17);comparatorMap.emplace("ö", 18);
            comparatorMap.emplace("p", 19);comparatorMap.emplace("q", 20);comparatorMap.emplace("r", 21);
            comparatorMap.emplace("s", 22);comparatorMap.emplace("ş", 23);comparatorMap.emplace("t", 24);
            comparatorMap.emplace("u", 25);comparatorMap.emplace("ú", 25);comparatorMap.emplace("ü", 26);comparatorMap.emplace("û", 26);
            comparatorMap.emplace("v", 27);comparatorMap.emplace("w", 28);comparatorMap.emplace("x", 29);
            comparatorMap.emplace("y", 30);comparatorMap.emplace("z", 31);comparatorMap.emplace("A", 32);
            comparatorMap.emplace("B", 33);comparatorMap.emplace("C", 34);comparatorMap.emplace("Ç", 35);
            comparatorMap.emplace("D", 36);comparatorMap.emplace("E", 37);comparatorMap.emplace("F", 38);
            comparatorMap.emplace("G", 39);comparatorMap.emplace("Ğ", 40);comparatorMap.emplace("H", 41);
            comparatorMap.emplace("I", 42);comparatorMap.emplace("İ", 43);comparatorMap.emplace("J", 44);
            comparatorMap.emplace("K", 45);comparatorMap.emplace("L", 46);comparatorMap.emplace("M", 47);
            comparatorMap.emplace("N", 48);comparatorMap.emplace("O", 49);comparatorMap.emplace("Ö", 50);
            comparatorMap.emplace("P", 51);comparatorMap.emplace("Q", 52);comparatorMap.emplace("R", 53);
            comparatorMap.emplace("S", 54);comparatorMap.emplace("Ş", 55);comparatorMap.emplace("T", 56);
            comparatorMap.emplace("U", 57);comparatorMap.emplace("Ü", 58);comparatorMap.emplace("V", 59);
            comparatorMap.emplace("W", 60);comparatorMap.emplace("X", 61);comparatorMap.emplace("Y", 62);
            comparatorMap.emplace("Z", 63);
            comparatorMap.emplace("-", 64);comparatorMap.emplace("&", 64);comparatorMap.emplace("'", 64);comparatorMap.emplace("’", 64);comparatorMap.emplace(".", 64);comparatorMap.emplace("(", 64);comparatorMap.emplace(")", 64);
            comparatorMap.emplace("0", 65);comparatorMap.emplace("1", 65);comparatorMap.emplace("2", 65);
            comparatorMap.emplace("3", 65);comparatorMap.emplace("4", 65);comparatorMap.emplace("5", 65);
            comparatorMap.emplace("6", 65);comparatorMap.emplace("7", 65);comparatorMap.emplace("8", 65);comparatorMap.emplace("9", 65);
            comparatorMap.emplace("<", 66);comparatorMap.emplace(">", 66);comparatorMap.emplace("/", 66);
            break;
        case Comparator ::TURKISH_NO_CASE:
            comparatorMap.emplace("a", 0);comparatorMap.emplace("â", 0);comparatorMap.emplace("á", 0);comparatorMap.emplace("å", 0);comparatorMap.emplace("ã", 0);comparatorMap.emplace("ä", 0);comparatorMap.emplace("A", 0);comparatorMap.emplace("Â", 0);
            comparatorMap.emplace("b", 1);comparatorMap.emplace("B", 1);
            comparatorMap.emplace("c", 2);comparatorMap.emplace("C", 2);
            comparatorMap.emplace("ç", 3);comparatorMap.emplace("Ç", 3);
            comparatorMap.emplace("d", 4);comparatorMap.emplace("D", 4);
            comparatorMap.emplace("e", 5);comparatorMap.emplace("é", 5);comparatorMap.emplace("æ", 5);comparatorMap.emplace("E", 5);
            comparatorMap.emplace("f", 6);comparatorMap.emplace("F", 6);
            comparatorMap.emplace("g", 7);comparatorMap.emplace("G", 7);
            comparatorMap.emplace("ğ", 8);comparatorMap.emplace("Ğ", 8);
            comparatorMap.emplace("h", 9);comparatorMap.emplace("H", 9);
            comparatorMap.emplace("ı", 10);comparatorMap.emplace("í", 10);comparatorMap.emplace("I", 10);
            comparatorMap.emplace("i", 11);comparatorMap.emplace("î", 11);comparatorMap.emplace("ï", 11);comparatorMap.emplace("İ", 11);comparatorMap.emplace("Î", 11);
            comparatorMap.emplace("j", 12);comparatorMap.emplace("J", 12);
            comparatorMap.emplace("k", 13);comparatorMap.emplace("K", 13);
            comparatorMap.emplace("l", 14);comparatorMap.emplace("L", 14);
            comparatorMap.emplace("m", 15);comparatorMap.emplace("M", 15);
            comparatorMap.emplace("n", 16);comparatorMap.emplace("N", 16);
            comparatorMap.emplace("o", 17);comparatorMap.emplace("O", 17);comparatorMap.emplace("ó", 17);
            comparatorMap.emplace("ö", 18);comparatorMap.emplace("Ö", 18);
            comparatorMap.emplace("p", 19);comparatorMap.emplace("P", 19);
            comparatorMap.emplace("q", 20);comparatorMap.emplace("Q", 20);
            comparatorMap.emplace("r", 21);comparatorMap.emplace("R", 21);
            comparatorMap.emplace("s", 22);comparatorMap.emplace("S", 22);
            comparatorMap.emplace("ş", 23);comparatorMap.emplace("Ş", 23);
            comparatorMap.emplace("t", 24);comparatorMap.emplace("T", 24);
            comparatorMap.emplace("u", 25);comparatorMap.emplace("ú", 25);comparatorMap.emplace("U", 25);
            comparatorMap.emplace("ü", 26);comparatorMap.emplace("û", 26);comparatorMap.emplace("Ü", 26);comparatorMap.emplace("Û", 26);
            comparatorMap.emplace("v", 27);comparatorMap.emplace("V", 27);
            comparatorMap.emplace("w", 28);comparatorMap.emplace("W", 28);
            comparatorMap.emplace("x", 29);comparatorMap.emplace("X", 29);
            comparatorMap.emplace("y", 30);comparatorMap.emplace("Y", 30);
            comparatorMap.emplace("z", 31);comparatorMap.emplace("Z", 31);
            comparatorMap.emplace("-", 32);comparatorMap.emplace("&", 32);comparatorMap.emplace("'", 32);comparatorMap.emplace("’", 32);comparatorMap.emplace(".", 32);comparatorMap.emplace("(", 32);comparatorMap.emplace(")", 32);
            comparatorMap.emplace("0", 32);comparatorMap.emplace("1", 32);comparatorMap.emplace("2", 32);
            comparatorMap.emplace("3", 32);comparatorMap.emplace("4", 32);comparatorMap.emplace("5", 32);
            comparatorMap.emplace("6", 32);comparatorMap.emplace("7", 32);comparatorMap.emplace("8", 32);comparatorMap.emplace("9", 32);
            comparatorMap.emplace("<", 33);comparatorMap.emplace(">", 33);comparatorMap.emplace("/", 33);
            break;
        case Comparator ::ENGLISH:
            break;
    }
}

struct turkishWordComparator{
    map<string, int> comparatorMap;
/**
 * The wordComparator takes two {@link Word}s as inputs; wordA and wordB and compares their names. Returns the result of this comparison.
 *
 * @param wordA Word type input.
 * @param wordB Word type input.
 * @return the value {@code 0} if the wordA is equal to the wordB; a value less than {@code 0} if this wordA is
 * lexicographically less than wordB; and a value greater than {@code 0} if this wordA is lexicographically greater
 * than wordB.
 */
    turkishWordComparator(map<string, int> comparatorMap){
        this->comparatorMap = comparatorMap;
    }

    bool operator() (Word* wordA, Word* wordB){
        const char* charPtr1 = wordA->getName().c_str();
        const char* charPtr2 = wordB->getName().c_str();
        while (*charPtr1 && *charPtr2){
            string char1;
            if ((*charPtr1 & 0xC0) != 0x80){
                do{
                    char1 += *charPtr1;
                    charPtr1++;
                } while ((*charPtr1 & 0xC0) == 0x80);
            }
            string char2;
            if ((*charPtr2 & 0xC0) != 0x80){
                do{
                    char2 += *charPtr2;
                    charPtr2++;
                } while ((*charPtr2 & 0xC0) == 0x80);
            }
            if (comparatorMap.contains(char1) && comparatorMap.contains(char2)){
                int index1 = comparatorMap.at(char1), index2 = comparatorMap.at(char2);
                if (index1 < index2){
                    return true;
                } else {
                    if (index1 > index2){
                        return false;
                    }
                }
            } else {
                return true;
            }
        }
        return *charPtr2;
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
                middle = lower_bound(words.begin(), words.end(), new Word(name));
                break;
            case Comparator::TURKISH:
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishWordComparator(comparatorMap));
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
                middle = lower_bound(words.begin(), words.end(), new Word(name));
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
            result = binary_search(words.begin(), words.end(), new Word(name));
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
                middle = lower_bound(words.begin(), words.end(), new Word(name));
                break;
            case Comparator::TURKISH:
            case Comparator::TURKISH_NO_CASE:
                middle = lower_bound(words.begin(), words.end(), new Word(name), turkishWordComparator(comparatorMap));
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
            middle = lower_bound(words.begin(), words.end(), new Word(hash));
            break;
        case Comparator::TURKISH:
        case Comparator::TURKISH_NO_CASE:
            middle = lower_bound(words.begin(), words.end(), new Word(hash), turkishWordComparator(comparatorMap));
            break;
    }
    return middle - words.begin();
}

void Dictionary::sort() {
    switch (comparator){
        case Comparator::ENGLISH:
            std::stable_sort(words.begin(), words.end());
            break;
        case Comparator::TURKISH:
        case Comparator::TURKISH_NO_CASE:
            std::stable_sort(words.begin(), words.end(), turkishWordComparator(comparatorMap));
            break;
    }
}
