//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include<vector>
#include<map>
#include <locale>
#include "Word.h"

using namespace std;

enum class Comparator{
    ENGLISH, TURKISH, TURKISH_NO_CASE
};

class Dictionary {
private:
    map<string, int> comparatorMap;
protected:
    vector<Word*> words;
    string filename;
    Comparator comparator = Comparator::ENGLISH;
    void sort();
public:
    Dictionary();
    explicit Dictionary(Comparator comparator);
    Word* getWord(string name);
    void removeWord(string name);
    int getWordIndex(string name);
    bool wordExists(string name);
    unsigned long size();
    Word* getWord(unsigned long index);
    unsigned long longestWordSize();
    unsigned long getWordStartingWith(string hash);
};

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
        if (wordA->getName() == wordB->getName()){
            return false;
        }
        if (wordB->getName().starts_with(wordA->getName())){
            return true;
        }
        if (wordA->getName().starts_with(wordB->getName())){
            return false;
        }
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
    }
};

#endif //DICTIONARY_DICTIONARY_H
