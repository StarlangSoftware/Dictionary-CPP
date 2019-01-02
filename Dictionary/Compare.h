//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_COMPARE_H
#define DICTIONARY_COMPARE_H

#include <clocale>
#include "Word.h"

enum class Comparator{
    ENGLISH, TURKISH, TURKISH_NO_CASE
};

/**
 * The EnglishWordComparator takes two {@link Word}s as inputs; wordA and wordB and compares their names. Returns the result of this comparison.
 *
 * @param wordA Word type input.
 * @param wordB Word type input.
 * @return the value {@code 0} if the wordA is equal to the wordB; a value less than {@code 0} if this wordA is
 * lexicographically less than wordB; and a value greater than {@code 0} if this wordA is lexicographically greater
 * than wordB.
 */
struct
{
    bool operator ()(const Word& wordA, const Word& wordB)
    {
        if (wordA.getName() == wordB.getName())
            return true;
        return wordA.getName() < wordB.getName();
    }
} EnglishWordComparator;

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
struct
{
    bool operator ()(const Word& wordA, const Word& wordB)
    {
        bool result;
        setlocale(LC_ALL, "Turkish");
        if (wordA.getName() == wordB.getName()){
            result = true;
        } else {
            result = wordA.getName() < wordB.getName();
        }
        setlocale(LC_ALL, "English");
        return result;
    }
} TurkishWordComparator;


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
struct
{
    bool operator ()(const Word& wordA, const Word& wordB)
    {
        bool result;
        setlocale(LC_ALL, "Turkish");
        string nameA = wordA.getName();
        string nameB = wordB.getName();
        std::transform(nameA.begin(), nameA.end(), nameA.begin(), ::tolower);
        std::transform(nameB.begin(), nameB.end(), nameB.begin(), ::tolower);
        if (nameA == nameB){
            result = true;
        } else {
            result = nameA < nameB;
        }
        setlocale(LC_ALL, "English");
        return result;
    }
} TurkishIgnoreCaseWordComparator;

#endif //DICTIONARY_COMPARE_H
