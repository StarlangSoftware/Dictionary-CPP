//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "TrieNode.h"

/**
 * A constructor of TrieNode class which creates a new children map.
 */
TrieNode::TrieNode() = default;

/**
 * The addWord method takes a String word, an index, and a Word root as inputs. First it creates a TrieNode child
 * and if words {@link unordered_set} is null it creates a new {@link unordered_set} and add the given root word to this {@link unordered_set}, if it
 * is not null, it directly adds it to the {@link unordered_set} when the given index is equal to the length of given word.
 * <p>
 * Then, it extracts the character at given index of given word and if children map contains a mapping for the
 * extracted character, it assigns it to the TrieNode child, else it creates a new TrieNode and assigns it to the
 * child. At the end, it recursively calls the addWord method with the next index of child and puts the character with
 * the child into the children map.
 *
 * @param word  String input.
 * @param index Integer index.
 * @param root  Word input to add.
 */
void TrieNode::addWord(const string& word, unsigned long index, Word* root) {
    TrieNode* child;
    if (index == Word::size(word)) {
        words.emplace(root);
        return;
    }
    string ch = Word::charAt(word, index);
    if (children.contains(ch)) {
        child = children.find(ch)->second;
    } else {
        child = new TrieNode();
    }
    child->addWord(word, index + 1, root);
    children.emplace(ch, child);
}

/**
 * The addWord method takes a String word and a Word type root as inputs. It calls addWord method with index 0.
 *
 * @param word String input.
 * @param root Word type input.
 */
void TrieNode::addWord(const string& word, Word* root) {
    addWord(word, 0, root);
}

/**
 * The getChild method takes a Character and gets its corresponding value from children HashMap.
 *
 * @param ch Character input.
 * @return the value from children HashMap.
 */
TrieNode* TrieNode::getChild(const string& ch) const{
    return children.find(ch)->second;
}

/**
 * The getWords method returns the words {@link unordered_set}.
 *
 * @return the words {@link unordered_set}.
 */
unordered_set<Word*> TrieNode::getWords() const{
    return words;
}

/**
 * Checks if the given child exists for a given character for the current TrieNode in the Trie.
 * @param ch Character for which search is done.
 * @return True if th child exists for that character, false otherwise.
 */
bool TrieNode::childExists(const string& ch) const{
    return children.contains(ch);
}
