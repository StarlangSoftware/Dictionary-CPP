//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#ifndef DICTIONARY_TRIENODE_H
#define DICTIONARY_TRIENODE_H
#include<map>
#include <unordered_set>
#include "../Word.h"

using namespace std;

namespace std
{
    template<>
    struct hash<Word>
    {
        size_t
        operator()(const Word & word) const
        {
            return hash<string>()(word.getName());
        }
    };
}
class TrieNode {
private:
    map<char, TrieNode> children;
    unordered_set<Word> words;
    void addWord(string word, unsigned long index, Word root);
public:
    TrieNode();
    void addWord(string word, Word root);
    TrieNode getChild(char ch);
    bool childExists(char ch);
    unordered_set<Word> getWords();
};


#endif //DICTIONARY_TRIENODE_H
