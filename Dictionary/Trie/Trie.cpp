//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "Trie.h"

/**
 * A constructor of {@link Trie} class which creates a new {@link TrieNode} as rootNode.
 */
Trie::Trie() {
}

/**
 * The addWord method which takes a String word and a {@link Word} root as inputs and adds given word and root to the rootNode.
 *
 * @param word String input.
 * @param root {@link Word} input.
 */
void Trie::addWord(string word, Word root) {
    rootNode.addWord(move(word), move(root));
}

/**
 * The getWordsWithPrefix method which takes a String surfaceForm as an input. First it creates a {@link TrieNode} current and assigns
 * the rootNode to it, then it creates a new {@link HashSet} words. It loops i times where i ranges from 0 to length of surfaceForm
 * and assigns current's child that corresponds to the surfaceForm's char at index i and assigns it as {@link TrieNode} current.
 * If current is not null, it adds all words of current to the words {@link HashSet}.
 *
 * @param surfaceForm String input.
 * @return words {@link unordered_set}.
 */
unordered_set<Word> Trie::getWordsWithPrefix(string surfaceForm) {
    TrieNode current = rootNode;
    unordered_set<Word> words;
    for (int i = 0; i < Word::size(surfaceForm); i++) {
        string ch = Word::charAt(surfaceForm, i);
        if (current.childExists(ch)) {
            current = current.getChild(ch);
            if (!current.getWords().empty()) {
                unordered_set<Word> wordsToBeAdded = current.getWords();
                words.insert(wordsToBeAdded.begin(), wordsToBeAdded.end());
            }
        } else {
            break;
        }
    }
    return words;
}
