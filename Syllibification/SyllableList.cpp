//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "SyllableList.h"
#include "IrregularWordException.h"
#include "../Language/TurkishLanguage.h"
#include "../Dictionary/Word.h"

/**
 * A constructor of {@link SyllableList} class which takes a String word as an input. First it creates a syllable {@link vector}
 * and a {@link string} sbSyllable. Then it loops i times, where i ranges from 0 to length of given word, first
 * it gets the ith character of given word and checks whether it is a vowel and the last character of the word.
 * <p>
 * If it is a vowel it appends it to the sbSyllable and if it is the last vowel it also appends the next character to the sbSyllable.
 * Then, it adds the sbSyllable tot he syllables {@link vector}.
 * <p>
 * If it is not a vowel, and the sbSyllable's length is 1 also the previous character is a consonant it gets the last item of
 * syllables {@link vector} since there cannot be a Turkish word which starts with two consonants. However, if it is
 * two last characters of word, then it adds it to the syllable {@link ArrayList}. At the end, it updatse the syllables {@link vector}.
 *
 * @param word String input.
 * @throws IrregularWordException if it is not a regular Turkish word.
 */
SyllableList::SyllableList(string word) {
    string sbSyllable;
    for (unsigned long i = 0; i < Word::size(word); i++) {
        string c = Word::charAt(word, i);
        bool isVowel = TurkishLanguage::isVowel(c);
        bool isLastChar = i == Word::size(word) - 1;
        if (isVowel) {
            sbSyllable += c;
            // If it is the last vowel.
            if (i == word.length() - 2) {
                sbSyllable += Word::charAt(word, i + 1);
                i++;
            }
            syllables.emplace_back(Syllable(sbSyllable));
            sbSyllable = "";
        } else {
            // A syllable should not start with two consonants.
            string tempSyl = sbSyllable;
            if (Word::size(tempSyl) == 1) {
                // The previous character was also a consonant.
                if (!TurkishLanguage::isVowel(Word::charAt(tempSyl, 0))) {
                    if (syllables.empty())
                        throw IrregularWordException();
                    unsigned long lastPos = syllables.size() - 1;
                    string str = syllables.at(lastPos).getText();
                    str += tempSyl;
                    if (isLastChar) {
                        // If the last char is also a consonant, add it to latest syllable. Ex: 'park'.
                        str += c;
                    }
                    // Update previous syllable.
                    syllables[lastPos] = Syllable(str);
                    sbSyllable = c;
                }
            }
            sbSyllable += c;
        }
    }
}

/**
 * The getSyllables method creates a new {@link vector} syllables and loops through the globally defined syllables
 * {@link vector} and adds each item to the newly created syllables {@link vector}.
 *
 * @return vector syllables.
 */
vector<string> SyllableList::getSyllables() {
    vector<string> syllables;
    for (Syllable syllable : syllables) {
        syllables.emplace_back(syllable.getText());
    }
    return syllables;
}
