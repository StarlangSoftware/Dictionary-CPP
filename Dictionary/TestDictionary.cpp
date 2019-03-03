//
// Created by Olcay Taner Yıldız on 5.01.2019.
//

#include <iostream>
#include "TxtDictionary.h"

int main(){
    TxtDictionary dictionary = TxtDictionary("turkish_dictionary.txt", Comparator::TURKISH);
    Trie trie = dictionary.prepareTrie();
    unordered_set<Word*> words = trie.getWordsWithPrefix("ab");
}