//
// Created by Olcay Taner Yıldız on 4.01.2019.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "TxtDictionary.h"
#include "TxtWord.h"

/**
 * Another constructor of {@link TxtDictionary} class which takes a String filename and a {@link WordComparator} as inputs.
 * And calls its super class {@link Dictionary} with given {@link WordComparator}, assigns given filename input to the
 * filename variable. Then, it calls loadFromText method with given filename.
 *
 * @param filename   String input.
 * @param comparator {@link WordComparator} input.
 */
TxtDictionary::TxtDictionary(string filename, Comparator comparator) : Dictionary(comparator) {
    loadFromText(filename);
    this->filename = move(filename);
}

/**
 * The clone method which creates new {@link TxtDictionary} object with filename and comparator variables.
 *
 * @return new {@link TxtDictionary} object.
 */
TxtDictionary TxtDictionary::clone() {
    return TxtDictionary(filename, comparator);
}

/**
 * The addNumber method takes a String name and calls addWithFlag method with given name and IS_SAYI flag.
 *
 * @param name String input.
 */
void TxtDictionary::addNumber(string name) {
    addWithFlag(move(name), "IS_SAYI");
}

/**
 * The addWithFlag method takes a String name and a flag as inputs. First it creates a {@link TxtWord} word, then if
 * given name is not in words {@link vector} it creates new {@link TxtWord} with given name and assigns it to
 * the word and adds given flag to the word, it also add newly created word to the words {@link vector}'s index
 * found by performing a binary search and return true at the end. If given name is in words {@link java.util.ArrayList},
 * it adds it the given flag to the word.
 *
 * @param name String input.
 * @param flag String flag.
 * @return true if given name is in words {@link java.util.ArrayList}, false otherwise.
 */
bool TxtDictionary::addWithFlag(string name, string flag) {
    return false;
}

/**
 * The addRealNumber method takes a String name and calls addWithFlag method with given name and IS_REELSAYI flag.
 *
 * @param name String input.
 */
void TxtDictionary::addRealNumber(string name) {
    addWithFlag(move(name), "IS_REELSAYI");
}

/**
 * The addFraction method takes a String name and calls addWithFlag method with given name and IS_KESIR flag.
 *
 * @param name String input.
 */
void TxtDictionary::addFraction(string name) {
    addWithFlag(move(name), "IS_KESIR");
}

/**
* The addTime method takes a String name and calls addWithFlag method with given name and IS_ZAMAN flag.
*
* @param name String input.
*/
void TxtDictionary::addTime(string name) {
    addWithFlag(move(name), "IS_ZAMAN");
}

/**
 * The addProperNoun method takes a String name and calls addWithFlag method with given name and IS_OA flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addProperNoun(string name) {
    return addWithFlag(move(name), "IS_OA");
}

/**
 * The addNoun method takes a String name and calls addWithFlag method with given name and CL_ISIM flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addNoun(string name) {
    return addWithFlag(move(name), "CL_ISIM");
}

/**
 * The addVerb method takes a String name and calls addWithFlag method with given name and CL_FIIL flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addVerb(string name) {
    return addWithFlag(move(name), "CL_FIIL");
}

/**
 * The addAdjective method takes a String name and calls addWithFlag method with given name and IS_ADJ flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addAdjective(string name) {
    return addWithFlag(move(name), "IS_ADJ");
}

/**
 * The addAdverb method takes a String name and calls addWithFlag method with given name and IS_ADVERB flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addAdverb(string name) {
    return addWithFlag(move(name), "IS_ADVERB");
}

/**
 * The addPronoun method takes a String name and calls addWithFlag method with given name and IS_ZM flag.
 *
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
bool TxtDictionary::addPronoun(string name) {
    return addWithFlag(move(name), "IS_ZM");
}

/**
 * The mergeDictionary method takes a String inputs; secondFilename and mergedFilename. It reads given files line by
 * line and splits them according to spaces and write each word to file whichever comes first lexicographically and
 * continue to read files till the end.
 *
 * @param secondFilename String input.
 * @param mergedFilename String input.
 */
void TxtDictionary::mergeDictionary(string secondFilename, string mergedFilename) {
    ifstream firstfile, secondfile;
    ofstream outfile;
    string st1, st2;
    string word1, word2, flag;
    firstfile.open(filename, ifstream :: in);
    secondfile.open(secondFilename, ifstream :: in);
    outfile.open(mergedFilename, ofstream :: out);
    getline(firstfile, st1);
    getline(secondfile, st2);
    while (firstfile.good() && secondfile.good()) {
        word1 = st1.substr(0, st1.find(' '));
        word2 = st2.substr(0, st2.find(' '));
        if (word1 < word2) {
            outfile << st1 + "\n";
            getline(firstfile, st1);
        } else {
            if (word1 > word2) {
                outfile << st2 + "\n";
                getline(secondfile, st2);
            } else {
                flag = st2.substr(st2.find(' ') + 1, st2.find(' ', st2.find(' ') + 1));
                if (st1.find_first_of(flag) != -1) {
                    outfile << st1 + "\n";
                } else {
                    outfile << st1 + " " + flag + "\n";
                }
                getline(firstfile, st1);
                getline(secondfile, st2);
            }
        }
    }
    if (!firstfile.good() && secondfile.good()) {
        while (secondfile.good()) {
            getline(secondfile, st2);
            outfile << st2 + "\n";
        }
    }
    firstfile.close();
    secondfile.close();
    outfile.close();
}

/**
 * The loadFromText method takes a String filename as an input. It reads given file line by line and splits according to space
 * and assigns each word to the String array. Then, adds these word with their flags tot he words {@link java.util.ArrayList}.
 * At the end it sorts the words {@link java.util.ArrayList}.
 *
 * @param filename File input.
 */
void TxtDictionary::loadFromText(string filename) {
    int i;
    string line;
    ifstream inputFile;
    TxtWord* currentWord = new TxtWord("");
    inputFile.open(filename, ifstream :: in);
    while (inputFile.good()) {
        getline(inputFile, line);
        vector<string> tokens = Word::split(line);
        if (!tokens.empty()) {
            currentWord = new TxtWord(tokens[0]);
            for (i = 1; i < tokens.size(); i++) {
                currentWord->addFlag(tokens[i]);
            }
            words.emplace_back(currentWord);
        }
    }
    inputFile.close();
    sort();
}

/**
 * The saveAsTxt method takes a filename as an input and prints out the items of words {@link unordered_set}.
 *
 * @param filename String input.
 */
void TxtDictionary::saveAsTxt(string filename) {
    ofstream outfile;
    int i;
    outfile.open(filename, ofstream :: out);
    for (i = 0; i < words.size(); i++) {
        outfile << words.at(i)->to_string() + "\n";
    }
    outfile.close();
}

/**
 * The addWordWhenRootSoften is used to add word to Trie whose last consonant will be soften.
 * For instance, in the case of Dative Case Suffix, the word is 'müzik' when '-e' is added to the word, the last
 * char is drooped and root became 'müzi' and by changing 'k' into 'ğ' the word transformed into 'müziğe' as in the
 * example of 'Herkes müziğe doğru geldi'.
 * <p>
 * In the case of accusative, possessive of third person and a derivative suffix, the word is 'kanat' when '-i' is
 * added to word, last char is dropped, root became 'kana' then 't' transformed into 'd' and added to Trie. The word is
 * changed into 'kanadı' as in the case of 'Kuşun kırık kanadı'.
 *
 * @param trie the name of the Trie to add the word.
 * @param last the last char of the word to be soften.
 * @param root the substring of the word whose last one or two chars are omitted from the word to bo softed.
 * @param word the original word.
 */
void TxtDictionary::addWordWhenRootSoften(Trie trie, string last, string root, TxtWord *word) {
    if (last == "p"){
        trie.addWord(root + 'b', word);
    } else {
        if (last == "ç"){
            trie.addWord(root + 'c', word);
        } else {
            if (last == "t"){
                trie.addWord(root + 'd', word);
            } else {
                if (last == "k" || last == "g"){
                    trie.addWord(root + "ğ", word);
                }
            }
        }
    }
}

/**
 * The prepareTrie method is used to create a Trie with the given dictionary. First, it gets the word from dictionary,
 * then checks some exceptions like 'ben' which does not fit in the consonant softening rule and transforms into 'bana',
 * and later on it generates a root by removing the last char from the word however if the length of the word is greater
 * than 1, it also generates the root by removing the last two chars from the word.
 * <p>
 * Then, it gets the last char of the root and adds root and word to the result Trie. There are also special cases such as;
 * lastIdropsDuringSuffixation condition, if it is true then addWordWhenRootSoften method will be used rather than addWord.
 * Ex : metin + i = metni
 * isPortmanteauEndingWithSI condition, if it is true then addWord method with rootWithoutLastTwo will be used.
 * Ex : ademelması + lar = ademelmaları
 * isPortmanteau condition, if it is true then addWord method with rootWithoutLast will be used.
 * Ex : mısıryağı + lar = mısıryağları
 * vowelEChangesToIDuringYSuffixation condition, if it is then addWord method with rootWithoutLast will be used
 * depending on the last char whether it is 'e' or 'a'.
 * Ex : ye + iniz - yiyiniz
 * endingKChangesIntoG condition, if it is true then addWord method with rootWithoutLast will be used with added 'g'.
 * Ex : ahenk + i = ahengi
 *
 * @param currentDictionary the dictionary that Trie will be created.
 * @return the resulting Trie.
 */
Trie TxtDictionary::prepareTrie() {
    Trie result = Trie();
    string root, rootWithoutLast, rootWithoutLastTwo;
    string last, lastBefore = " ";
    for (int i = 0; i < size(); i++) {
        TxtWord* word = (TxtWord*) getWord(i);
        root = word->getName();
        if (root == "ben") {
            result.addWord("bana", word);
        }
        rootWithoutLast = Word::substringExceptLastChar(root);
        if (root.length() > 1) {
            rootWithoutLastTwo = Word::substringExceptLastTwoChars(root);
        } else {
            rootWithoutLastTwo = "";
        }
        if (root.length() > 1){
            lastBefore = Word::charAt(root, Word::size(root) - 2);
        }
        last = Word::lastChar(root);
        result.addWord(root, word);
        if (word->lastIdropsDuringSuffixation() || word->lastIdropsDuringPassiveSuffixation()) {
            if (word->rootSoftenDuringSuffixation()) {
                addWordWhenRootSoften(result, last, rootWithoutLastTwo, word);
            } else {
                result.addWord(rootWithoutLastTwo + last, word);
            }
        }
        // NominalRootNoPossesive
        if (word->isPortmanteauEndingWithSI()) {
            result.addWord(rootWithoutLastTwo, word);
        }
        if (word->rootSoftenDuringSuffixation()) {
            addWordWhenRootSoften(result, last, rootWithoutLast, word);
        }
        if (word->isPortmanteau()) {
            if (word->isPortmanteauFacedVowelEllipsis()){
                result.addWord(rootWithoutLastTwo + last + lastBefore, word);
            } else {
                if (word->isPortmanteauFacedSoftening()){
                    if (lastBefore == "b"){
                        result.addWord(rootWithoutLastTwo + "p", word);
                    } else {
                        if (lastBefore == "c"){
                            result.addWord(rootWithoutLastTwo + "ç", word);
                        } else {
                            if (lastBefore == "d"){
                                result.addWord(rootWithoutLastTwo + "t", word);
                            } else {
                                if (lastBefore == "ğ"){
                                    result.addWord(rootWithoutLastTwo + "k", word);
                                }
                            }
                        }
                    }
                } else {
                    result.addWord(rootWithoutLast, word);
                }
            }
        }
        if (word->vowelEChangesToIDuringYSuffixation() || word->vowelAChangesToIDuringYSuffixation()) {
            if (last == "e"){
                result.addWord(rootWithoutLast, word);
            } else {
                if (last == "a"){
                    result.addWord(rootWithoutLast, word);
                }
            }
        }
        if (word->endingKChangesIntoG()) {
            result.addWord(rootWithoutLast + "g", word);
        }
    }
    return result;
}
