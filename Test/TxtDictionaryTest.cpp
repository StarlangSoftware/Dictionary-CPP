//
// Created by Olcay Taner YILDIZ on 26.12.2020.
//

#include "catch.hpp"
#include "../Dictionary/TxtDictionary.h"

bool notContains(unordered_set<Word*> set, Word* word){
    return set.find(word) != set.end();
}

TEST_CASE("DictionaryTest-testPrepareTrie") {
    TxtDictionary dictionary = TxtDictionary();
    Trie* trie = dictionary.prepareTrie();
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("bana"), new Word("ben")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("metni"), new Word("metin")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("ağzı"), new Word("ağız")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("ayrıldı"), new Word("ayır")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("buyruldu"), new Word("buyur")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("ahdi"), new Word("ahit")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("kaybı"), new Word("kayıp")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("kutbu"), new Word("kutup")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("ademelmaları"), new Word("ademelması")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("ağaçküpeleri"), new Word("ağaçküpesi")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("ağaçlığı"), new Word("ağaçlık")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("sumağı"), new Word("sumak")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("deveboyunları"), new Word("deveboynu")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("gökcisimleri"), new Word("gökcismi")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("gökkuşakları"), new Word("gökkuşağı")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("hintarmutları"), new Word("hintarmudu")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("hintpirinçleri"), new Word("hintpirinci")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("sudolapları"), new Word("sudolabı")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("yiyor"), new Word("ye")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("diyor"), new Word("de")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("depoluyor"), new Word("depola")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("dışlıyor"), new Word("dışla")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("fiyongu"), new Word("fiyonk")));
    REQUIRE_FALSE(notContains(trie->getWordsWithPrefix("gongu"), new Word("gonk")));
}