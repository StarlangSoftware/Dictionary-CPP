//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#ifndef DICTIONARY_TRIENODE_H
#define DICTIONARY_TRIENODE_H
#include<map>
#include <unordered_set>
#include "../Word.h"

using namespace std;

class TrieNode {
private:
    map<string, TrieNode*> children;
    unordered_set<Word*> words;
    void addWord(const string& word, unsigned long index, Word* root);
public:
    TrieNode();
    ~TrieNode(){
        for (auto& child : children){
            delete child.second;
        }
    }
    void addWord(const string& word, Word* root);
    TrieNode* getChild(const string& ch) const;
    bool childExists(const string& ch) const;
    unordered_set<Word*> getWords() const;
};


#endif //DICTIONARY_TRIENODE_H
