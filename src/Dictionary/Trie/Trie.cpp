//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "Trie.h"

/**
 * A constructor of Trie class which creates a new TrieNode as rootNode.
 */
Trie::Trie(){
    rootNode = new TrieNode();
}

/**
 * The addWord method which takes a String word and a Word root as inputs and adds given word and root to the rootNode.
 *
 * @param word String input.
 * @param root Word input.
 */
void Trie::addWord(const string& word, Word* root) {
    rootNode->addWord(word, root);
}

/**
 * The getWordsWithPrefix method which takes a String surfaceForm as an input. First it creates a TrieNode current and assigns
 * the rootNode to it, then it creates a new HashSet words. It loops i times where i ranges from 0 to length of surfaceForm
 * and assigns current's child that corresponds to the surfaceForm's char at index i and assigns it as TrieNode current.
 * If current is not null, it adds all words of current to the words HashSet.
 *
 * @param surfaceForm String input.
 * @return words {@link unordered_set}.
 */
unordered_set<Word*> Trie::getWordsWithPrefix(const string& surfaceForm) const{
    TrieNode* current = rootNode;
    unordered_set<Word*> words;
    for (int i = 0; i < Word::size(surfaceForm); i++) {
        string ch = Word::charAt(surfaceForm, i);
        if (current->childExists(ch)) {
            current = current->getChild(ch);
            if (!current->getWords().empty()) {
                unordered_set<Word*> wordsToBeAdded = current->getWords();
                words.merge(wordsToBeAdded);
            }
        } else {
            break;
        }
    }
    return words;
}

/**
 * The getCompoundWordStartingWith method takes a String hash. First it creates a TrieNode current and assigns
 * the rootNode to it. Then it loops i times where i ranges from 0 to length of given hash and assigns current's child that
 * corresponds to the hash's char at index i and assigns it as current. If current is null, it returns null.
 * <p>
 * If current is not null,  it loops through the words of current TrieNode and if it is a Portmanteau word, it
 * directly returns the word.
 *
 * @param hash String input.
 * @return null if TrieNode is null, otherwise portmanteau word.
 */
TxtWord *Trie::getCompoundWordStartingWith(const string& hash) const{
    TrieNode* current = rootNode;
    for (int i = 0; i < Word::size(hash); i++) {
        if (current->childExists(Word::charAt(hash, i))){
            current = current->getChild(Word::charAt(hash, i));
        } else {
            return nullptr;
        }
    }
    if (!current->getWords().empty()) {
        for (Word* word : current->getWords()) {
            if (((TxtWord*) word)->isPortmanteau()) {
                return (TxtWord*) word;
            }
        }
    }
    return nullptr;
}
