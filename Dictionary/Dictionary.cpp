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
            comparatorMap.emplace("a", 0);
            comparatorMap.emplace("â", 1);
            comparatorMap.emplace("á", 2);
            comparatorMap.emplace("å", 3);
            comparatorMap.emplace("ã", 4);
            comparatorMap.emplace("ä", 5);
            comparatorMap.emplace("b", 6);
            comparatorMap.emplace("c", 7);
            comparatorMap.emplace("ç", 8);
            comparatorMap.emplace("d", 9);
            comparatorMap.emplace("e", 10);
            comparatorMap.emplace("é", 11);
            comparatorMap.emplace("æ", 12);
            comparatorMap.emplace("f", 13);
            comparatorMap.emplace("g", 14);
            comparatorMap.emplace("ğ", 15);
            comparatorMap.emplace("h", 16);
            comparatorMap.emplace("ı", 17);
            comparatorMap.emplace("í", 18);
            comparatorMap.emplace("i", 19);
            comparatorMap.emplace("î", 20);
            comparatorMap.emplace("ï", 21);
            comparatorMap.emplace("j", 22);
            comparatorMap.emplace("k", 23);
            comparatorMap.emplace("l", 24);
            comparatorMap.emplace("m", 25);
            comparatorMap.emplace("n", 26);
            comparatorMap.emplace("o", 27);
            comparatorMap.emplace("ó", 28);
            comparatorMap.emplace("ö", 29);
            comparatorMap.emplace("p", 30);
            comparatorMap.emplace("q", 31);
            comparatorMap.emplace("r", 32);
            comparatorMap.emplace("s", 33);
            comparatorMap.emplace("ş", 34);
            comparatorMap.emplace("t", 35);
            comparatorMap.emplace("u", 36);
            comparatorMap.emplace("ú", 37);
            comparatorMap.emplace("ü", 38);
            comparatorMap.emplace("û", 39);
            comparatorMap.emplace("v", 40);
            comparatorMap.emplace("w", 41);
            comparatorMap.emplace("x", 42);
            comparatorMap.emplace("y", 43);
            comparatorMap.emplace("z", 44);
            comparatorMap.emplace("A", 45);
            comparatorMap.emplace("B", 46);
            comparatorMap.emplace("C", 47);
            comparatorMap.emplace("Ç", 48);
            comparatorMap.emplace("D", 49);
            comparatorMap.emplace("E", 50);
            comparatorMap.emplace("F", 51);
            comparatorMap.emplace("G", 52);
            comparatorMap.emplace("Ğ", 53);
            comparatorMap.emplace("H", 54);
            comparatorMap.emplace("I", 55);
            comparatorMap.emplace("İ", 56);
            comparatorMap.emplace("J", 57);
            comparatorMap.emplace("K", 58);
            comparatorMap.emplace("L", 59);
            comparatorMap.emplace("M", 60);
            comparatorMap.emplace("N", 61);
            comparatorMap.emplace("O", 62);
            comparatorMap.emplace("Ö", 63);
            comparatorMap.emplace("P", 64);
            comparatorMap.emplace("Q", 65);
            comparatorMap.emplace("R", 66);
            comparatorMap.emplace("S", 67);
            comparatorMap.emplace("Ş", 68);
            comparatorMap.emplace("T", 69);
            comparatorMap.emplace("U", 70);
            comparatorMap.emplace("Ü", 71);
            comparatorMap.emplace("V", 72);
            comparatorMap.emplace("W", 73);
            comparatorMap.emplace("X", 74);
            comparatorMap.emplace("Y", 75);
            comparatorMap.emplace("Z", 76);
            comparatorMap.emplace("-", 77);
            comparatorMap.emplace("&", 78);
            comparatorMap.emplace("'", 79);
            comparatorMap.emplace("’", 80);
            comparatorMap.emplace(".", 81);
            comparatorMap.emplace("(", 82);
            comparatorMap.emplace(")", 83);
            comparatorMap.emplace("0", 84);
            comparatorMap.emplace("1", 85);
            comparatorMap.emplace("2", 86);
            comparatorMap.emplace("3", 87);
            comparatorMap.emplace("4", 88);
            comparatorMap.emplace("5", 89);
            comparatorMap.emplace("6", 90);
            comparatorMap.emplace("7", 91);
            comparatorMap.emplace("8", 92);
            comparatorMap.emplace("9", 93);
            comparatorMap.emplace("<", 94);
            comparatorMap.emplace(">", 95);
            comparatorMap.emplace("/", 96);
            break;
        case Comparator ::TURKISH_NO_CASE:
            comparatorMap.emplace("a", 0);
            comparatorMap.emplace("â", 1);
            comparatorMap.emplace("á", 2);
            comparatorMap.emplace("å", 3);
            comparatorMap.emplace("ã", 4);
            comparatorMap.emplace("ä", 5);
            comparatorMap.emplace("A", 6);
            comparatorMap.emplace("Â", 7);
            comparatorMap.emplace("b", 8);
            comparatorMap.emplace("B", 9);
            comparatorMap.emplace("c", 10);
            comparatorMap.emplace("C", 11);
            comparatorMap.emplace("ç", 12);
            comparatorMap.emplace("Ç", 13);
            comparatorMap.emplace("d", 14);
            comparatorMap.emplace("D", 15);
            comparatorMap.emplace("e", 16);
            comparatorMap.emplace("é", 17);
            comparatorMap.emplace("æ", 18);
            comparatorMap.emplace("E", 19);
            comparatorMap.emplace("f", 20);
            comparatorMap.emplace("F", 21);
            comparatorMap.emplace("g", 22);
            comparatorMap.emplace("G", 23);
            comparatorMap.emplace("ğ", 24);
            comparatorMap.emplace("Ğ", 25);
            comparatorMap.emplace("h", 26);
            comparatorMap.emplace("H", 27);
            comparatorMap.emplace("ı", 28);
            comparatorMap.emplace("í", 29);
            comparatorMap.emplace("I", 30);
            comparatorMap.emplace("i", 31);
            comparatorMap.emplace("î", 32);
            comparatorMap.emplace("ï", 33);
            comparatorMap.emplace("İ", 34);
            comparatorMap.emplace("Î", 35);
            comparatorMap.emplace("j", 36);
            comparatorMap.emplace("J", 37);
            comparatorMap.emplace("k", 38);
            comparatorMap.emplace("K", 39);
            comparatorMap.emplace("l", 40);
            comparatorMap.emplace("L", 41);
            comparatorMap.emplace("m", 42);
            comparatorMap.emplace("M", 43);
            comparatorMap.emplace("n", 44);
            comparatorMap.emplace("N", 45);
            comparatorMap.emplace("o", 46);
            comparatorMap.emplace("O", 47);
            comparatorMap.emplace("ó", 48);
            comparatorMap.emplace("ö", 49);
            comparatorMap.emplace("Ö", 50);
            comparatorMap.emplace("p", 51);
            comparatorMap.emplace("P", 52);
            comparatorMap.emplace("q", 53);
            comparatorMap.emplace("Q", 54);
            comparatorMap.emplace("r", 55);
            comparatorMap.emplace("R", 56);
            comparatorMap.emplace("s", 57);
            comparatorMap.emplace("S", 58);
            comparatorMap.emplace("ş", 59);
            comparatorMap.emplace("Ş", 60);
            comparatorMap.emplace("t", 61);
            comparatorMap.emplace("T", 62);
            comparatorMap.emplace("u", 63);
            comparatorMap.emplace("ú", 64);
            comparatorMap.emplace("U", 65);
            comparatorMap.emplace("ü", 66);
            comparatorMap.emplace("û", 67);
            comparatorMap.emplace("Ü", 68);
            comparatorMap.emplace("Û", 69);
            comparatorMap.emplace("v", 70);
            comparatorMap.emplace("V", 71);
            comparatorMap.emplace("w", 72);
            comparatorMap.emplace("W", 73);
            comparatorMap.emplace("x", 74);
            comparatorMap.emplace("X", 75);
            comparatorMap.emplace("y", 76);
            comparatorMap.emplace("Y", 77);
            comparatorMap.emplace("z", 78);
            comparatorMap.emplace("Z", 79);
            comparatorMap.emplace("-", 80);
            comparatorMap.emplace("&", 81);
            comparatorMap.emplace("'", 82);
            comparatorMap.emplace("’", 83);
            comparatorMap.emplace(".", 84);
            comparatorMap.emplace("(", 85);
            comparatorMap.emplace(")", 86);
            comparatorMap.emplace("0", 87);
            comparatorMap.emplace("1", 88);
            comparatorMap.emplace("2", 89);
            comparatorMap.emplace("3", 90);
            comparatorMap.emplace("4", 91);
            comparatorMap.emplace("5", 92);
            comparatorMap.emplace("6", 93);
            comparatorMap.emplace("7", 94);
            comparatorMap.emplace("8", 95);
            comparatorMap.emplace("9", 96);
            comparatorMap.emplace("<", 97);
            comparatorMap.emplace(">", 98);
            comparatorMap.emplace("/", 99);
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
            std::sort(words.begin(), words.end());
            break;
        case Comparator::TURKISH:
        case Comparator::TURKISH_NO_CASE:
            std::sort(words.begin(), words.end(), turkishWordComparator(comparatorMap));
            break;
    }
}
