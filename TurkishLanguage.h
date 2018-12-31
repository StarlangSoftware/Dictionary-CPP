//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#ifndef DICTIONARY_TURKISHLANGUAGE_H
#define DICTIONARY_TURKISHLANGUAGE_H


#include "Language.h"

class TurkishLanguage : public Language {
    static const string VOWELS;
    static const string BACK_VOWELS;
    static const string FRONT_VOWELS;
    static const string BACK_ROUNDED_VOWELS;
    static const string BACK_UNROUNDED_VOWELS;
    static const string FRONT_ROUNDED_VOWELS;
    static const string FRONT_UNROUNDED_VOWELS;
    static const string CONSONANT_DROPS;
    static const string CONSONANTS;
    static const string SERT_SESSIZ;
    static const string LOWERCASE_LETTERS;
    static const string UPPERCASE_LETTERS ;
    static const string LETTERS;
public:
    static bool isVowel(char ch);
    static bool isBackVowel(char ch);
    static bool isFrontVowel(char ch);
    static bool isBackRoundedVowel(char ch);
    static bool isFrontRoundedVowel(char ch);
    static bool isBackUnroundedVowel(char ch);
    static bool isFrontUnroundedVowel(char ch);
    static bool isConsonantDrop(char ch);
    static bool isConsonant(char ch);
    static bool isSertSessiz(char ch);
};

const string TurkishLanguage::VOWELS = "aeıioöuüâî";
const string TurkishLanguage::BACK_VOWELS = "aıouâ";
const string TurkishLanguage::FRONT_VOWELS = "eiöüî";
const string TurkishLanguage::BACK_ROUNDED_VOWELS = "ou";
const string TurkishLanguage::BACK_UNROUNDED_VOWELS = "aıâ";
const string TurkishLanguage::FRONT_ROUNDED_VOWELS = "öü";
const string TurkishLanguage::FRONT_UNROUNDED_VOWELS = "eiî";
const string TurkishLanguage::CONSONANT_DROPS = "nsy";
const string TurkishLanguage::CONSONANTS = "bcçdfgğhjklmnprsştvyzxqw";
const string TurkishLanguage::SERT_SESSIZ = "çfhkpsşt";
const string TurkishLanguage::LOWERCASE_LETTERS = "abcçdefgğhıijklmnoöprsştuüvyz";
const string TurkishLanguage::UPPERCASE_LETTERS = "ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";
const string TurkishLanguage::LETTERS = "abcçdefgğhıijklmnoöprsştuüvyzABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";

/**
 * The isVowel method takes a character as an input and returns true if given character is a vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a vowel.
 */
bool TurkishLanguage::isVowel(char ch) {
    return (VOWELS.find_first_of(ch) != -1);
}

/**
 * The isBackVowel method takes a character as an input and returns true if given character is a back vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back vowel.
 */
bool TurkishLanguage::isBackVowel(char ch){
    return (BACK_VOWELS.find_first_of(ch) != -1);
}

/**
 * The isFrontVowel method takes a character as an input and returns true if given character is a front vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front vowel.
 */
bool TurkishLanguage::isFrontVowel(char ch) {
    return (FRONT_VOWELS.find_first_of(ch) != -1);
}

/**
 * The isBackRoundedVowel method takes a character as an input and returns true if given character is a back rounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back rounded vowel.
 */
bool TurkishLanguage::isBackRoundedVowel(char ch) {
    return (BACK_ROUNDED_VOWELS.find_first_of(ch) != -1);
}

/**
 * The isFrontRoundedVowel method takes a character as an input and returns true if given character is a front rounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front rounded vowel.
 */
bool TurkishLanguage::isFrontRoundedVowel(char ch) {
    return (FRONT_ROUNDED_VOWELS.find_first_of(ch) != -1);
}

/**
 * The isBackUnroundedVowel method takes a character as an input and returns true if given character is a back unrounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back unrounded vowel.
 */
bool TurkishLanguage::isBackUnroundedVowel(char ch) {
    return (BACK_UNROUNDED_VOWELS.find_first_of(ch) != -1);
}

/**
 * The isFrontUnroundedVowel method takes a character as an input and returns true if given character is a front unrounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front unrounded vowel.
 */
bool TurkishLanguage::isFrontUnroundedVowel(char ch) {
    return (FRONT_UNROUNDED_VOWELS.find_first_of(ch) != -1);
}

/**
 * The isConsonantDrop method takes a character as an input and returns true if given character is a dropping consonant.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a dropping consonant.
 */
bool TurkishLanguage::isConsonantDrop(char ch) {
    return (CONSONANT_DROPS.find_first_of(ch) != -1);
}

/**
 * The isConsonant method takes a character as an input and returns true if given character is a consonant.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a consonant.
 */
bool TurkishLanguage::isConsonant(char ch) {
    return (CONSONANTS.find_first_of(ch) != -1);
}

/**
 * The isSertSessiz method takes a character as an input and returns true if given character is a sert sessiz.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a sert sessiz.
 */
bool TurkishLanguage::isSertSessiz(char ch) {
    return (SERT_SESSIZ.find_first_of(ch) != -1);
}


#endif //DICTIONARY_TURKISHLANGUAGE_H
