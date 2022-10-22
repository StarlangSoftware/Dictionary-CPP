//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include<string>
#include "TrieNode.h"
#include "../TxtWord.h"

class Trie {
private:
    TrieNode* rootNode;
public:
    Trie();
    ~Trie(){
        TrieNode* current = rootNode;
        delete current;
    }
    void addWord(const string& word, Word* root);
    unordered_set<Word*> getWordsWithPrefix(const string& surfaceForm);
    TxtWord* getCompoundWordStartingWith(const string& hash);
};


#endif //DICTIONARY_TRIE_H
