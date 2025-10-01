//
// Created by Olcay Taner YILDIZ on 26.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/Dictionary/Trie/Trie.h"
#include "../src/Dictionary/TxtDictionary.h"
#include <unordered_set>
using namespace std;

bool areSetsNotEqual(unordered_set<Word*> set1, unordered_set<Word*> set2){
    if (set1.size() != set2.size()){
        return true;
    }
    for (Word* item1 : set1){
        bool found = false;
        for (Word* item2 : set2){
            if (*item1 == *item2){
                found = true;
            }
        }
        if (!found){
            return true;
        }
    }
    return false;
}

TEST_CASE("TrieTest-getWordsWithPrefixSimple") {
    Trie simpleTrie = Trie();
    simpleTrie.addWord("azı", new Word("azı"));
    simpleTrie.addWord("az", new Word("az"));
    simpleTrie.addWord("ad", new Word("ad"));
    simpleTrie.addWord("adi", new Word("adi"));
    simpleTrie.addWord("adil", new Word("adil"));
    simpleTrie.addWord("a", new Word("a"));
    simpleTrie.addWord("adilane", new Word("adilane"));
    simpleTrie.addWord("ısı", new Word("ısı"));
    simpleTrie.addWord("ısıtıcı", new Word("ısıtıcı"));
    simpleTrie.addWord("ölü", new Word("ölü"));
    simpleTrie.addWord("ölüm", new Word("ölüm"));
    simpleTrie.addWord("ören", new Word("ören"));
    simpleTrie.addWord("örgü", new Word("örgü"));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a")}), simpleTrie.getWordsWithPrefix("a")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad")}), simpleTrie.getWordsWithPrefix("ad")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad"), new Word("adi")}), simpleTrie.getWordsWithPrefix("adi")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad"), new Word("adi"), new Word("adil")}), simpleTrie.getWordsWithPrefix("adil")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad"), new Word("adi"), new Word("adilane"), new Word("adil")}), simpleTrie.getWordsWithPrefix("adilane")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ölü")}), simpleTrie.getWordsWithPrefix("ölü")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ölü"), new Word("ölüm")}), simpleTrie.getWordsWithPrefix("ölüm")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ısı")}), simpleTrie.getWordsWithPrefix("ısı")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ısıtıcı"), new Word("ısı")}), simpleTrie.getWordsWithPrefix("ısıtıcı")));
}

TEST_CASE("TrieTest-getWordsWithPrefixComplex") {
    Trie complexTrie = Trie();
    TxtDictionary dictionary = TxtDictionary();
    for (int i = 0; i < dictionary.size(); i++){
        complexTrie.addWord(dictionary.getWord(i)->getName(), dictionary.getWord(i));
    }
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a")}), complexTrie.getWordsWithPrefix("a")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad")}), complexTrie.getWordsWithPrefix("ad")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad"), new Word("adi")}), complexTrie.getWordsWithPrefix("adi")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad"), new Word("adi"), new Word("adil")}), complexTrie.getWordsWithPrefix("adil")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("a"), new Word("ad"), new Word("adi"), new Word("adilane"), new Word("adil")}), complexTrie.getWordsWithPrefix("adilane")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ölü"), new Word("öl")}), complexTrie.getWordsWithPrefix("ölü")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ölü"), new Word("öl"), new Word("ölüm")}), complexTrie.getWordsWithPrefix("ölüm")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ı"), new Word("ısı")}), complexTrie.getWordsWithPrefix("ısı")));
    REQUIRE_FALSE(areSetsNotEqual(unordered_set<Word*>({new Word("ı"), new Word("ısıtıcı"), new Word("ısıt"), new Word("ısı")}), complexTrie.getWordsWithPrefix("ısıtıcı")));
}