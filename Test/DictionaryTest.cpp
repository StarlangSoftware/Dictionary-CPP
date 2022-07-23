//
// Created by Olcay Taner YILDIZ on 26.12.2020.
//

#include "catch.hpp"
#include "../Dictionary/TxtDictionary.h"

TEST_CASE("DictionaryTest") {
    TxtDictionary lowerCaseDictionary = TxtDictionary("lowercase.txt", Comparator::TURKISH, "turkish_misspellings.txt");
    TxtDictionary mixedCaseDictionary = TxtDictionary("mixedcase.txt", Comparator::TURKISH_NO_CASE, "turkish_misspellings.txt");
    TxtDictionary dictionary = TxtDictionary();
    SECTION("testGetWordIndex"){
        REQUIRE(0 == lowerCaseDictionary.getWordIndex("a"));
        REQUIRE(3 == lowerCaseDictionary.getWordIndex("ç"));
        REQUIRE(8 == lowerCaseDictionary.getWordIndex("ğ"));
        REQUIRE(10 == lowerCaseDictionary.getWordIndex("ı"));
        REQUIRE(18 == lowerCaseDictionary.getWordIndex("ö"));
        REQUIRE(22 == lowerCaseDictionary.getWordIndex("ş"));
        REQUIRE(25 == lowerCaseDictionary.getWordIndex("ü"));
        REQUIRE(28 == lowerCaseDictionary.getWordIndex("z"));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("A") == 0 || mixedCaseDictionary.getWordIndex("A") == 1));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("Ç") == 6 || mixedCaseDictionary.getWordIndex("Ç") == 7));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("Ğ") == 16 || mixedCaseDictionary.getWordIndex("Ğ") == 17));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("I") == 20 || mixedCaseDictionary.getWordIndex("I") == 21));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("İ") == 22 || mixedCaseDictionary.getWordIndex("İ") == 23));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("Ş") == 44 || mixedCaseDictionary.getWordIndex("Ş") == 45));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("Ü") == 50 || mixedCaseDictionary.getWordIndex("Ü") == 51));
        REQUIRE_FALSE(!(mixedCaseDictionary.getWordIndex("Z") == 56 || mixedCaseDictionary.getWordIndex("Z") == 57));
    }
    SECTION("testSize"){
        REQUIRE(29 == lowerCaseDictionary.size());
        REQUIRE(58 == mixedCaseDictionary.size());
        REQUIRE(62113 == dictionary.size());
    }
    SECTION("testGetWord"){
        REQUIRE("a" == lowerCaseDictionary.getWord(0)->getName());
        REQUIRE("ç" == lowerCaseDictionary.getWord(3)->getName());
        REQUIRE("ğ" == lowerCaseDictionary.getWord(8)->getName());
        REQUIRE("ı" == lowerCaseDictionary.getWord(10)->getName());
        REQUIRE("ö" == lowerCaseDictionary.getWord(18)->getName());
        REQUIRE("ş" == lowerCaseDictionary.getWord(22)->getName());
        REQUIRE("ü" == lowerCaseDictionary.getWord(25)->getName());
        REQUIRE("z" == lowerCaseDictionary.getWord(28)->getName());
        for (int i = 0; i < dictionary.size(); i++){
            REQUIRE_FALSE(nullptr == dictionary.getWord(i));
        }
    }
    SECTION("testLongestWordSize"){
        REQUIRE(1 == lowerCaseDictionary.longestWordSize());
        REQUIRE(1 == mixedCaseDictionary.longestWordSize());
        REQUIRE(21 == dictionary.longestWordSize());
    }
    SECTION("testGetWordStartingWith"){
        REQUIRE(20 == lowerCaseDictionary.getWordStartingWith("q"));
        REQUIRE(27 == lowerCaseDictionary.getWordStartingWith("w"));
        REQUIRE(27 == lowerCaseDictionary.getWordStartingWith("x"));
        REQUIRE(40 == mixedCaseDictionary.getWordStartingWith("Q"));
        REQUIRE(54 == mixedCaseDictionary.getWordStartingWith("W"));
        REQUIRE(54 == mixedCaseDictionary.getWordStartingWith("X"));
    }
}
