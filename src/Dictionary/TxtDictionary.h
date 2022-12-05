//
// Created by Olcay Taner Yıldız on 4.01.2019.
//

#ifndef DICTIONARY_TXTDICTIONARY_H
#define DICTIONARY_TXTDICTIONARY_H
#include "Dictionary.h"
#include "Trie/Trie.h"
#include "TxtWord.h"

class TxtDictionary : public Dictionary {
private:
    map<string, string> misspelledWords;
    void loadFromText(const string& filename);
    void loadMisspelledWords(const string& filename);
    void loadMorphologicalLexicon(const string& filename);
    void addWordWhenRootSoften(Trie* trie, const string& last, const string& root, TxtWord* word);
public:
    explicit TxtDictionary(const string& filename);
    explicit TxtDictionary(const string& filename = "turkish_dictionary.txt", const string& misspelledFileName = "turkish_misspellings.txt", const string& morphologicalLexicon = "turkish_morphological_lexicon.txt");
    TxtDictionary clone();
    bool addWithFlag(const string& name, const string& flag);
    void addNumber(const string& name);
    void addRealNumber(const string& name);
    void addFraction(const string& name);
    void addTime(const string& name);
    bool addProperNoun(const string& name);
    bool addNoun(const string& name);
    bool addVerb(const string& name);
    bool addAdjective(const string& name);
    bool addAdverb(const string& name);
    bool addPronoun(const string& name);
    void mergeDictionary(const string& secondFilename, const string& mergedFilename);
    void saveAsTxt(const string& filename);
    string getCorrectForm(const string& misspelledWord) const;
    Trie* prepareTrie();
};


#endif //DICTIONARY_TXTDICTIONARY_H
