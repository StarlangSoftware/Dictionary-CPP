//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_TXTWORD_H
#define DICTIONARY_TXTWORD_H

#include<vector>
#include <string>
#include <unordered_set>
#include "Word.h"

using namespace std;

class TxtWord : public Word {
private:
    unordered_set<string> flags;
    string morphology;
public:
    TxtWord(const string& name);
    TxtWord(const string& name, const string& flag);
    void addFlag(const string& flag);
    TxtWord* clone();
    void removeFlag(const string& flag);
    void setMorphology(const string& _morphology);
    string getMorphology() const;
    string verbType() const;
    bool containsFlag(const string& flag) const;
    bool samePos(const TxtWord& word) const;
    bool isNominal() const;
    bool isPassive() const;
    bool isAbbreviation() const;
    bool isInterjection() const;
    bool isDuplicate() const;
    bool isCode() const;
    bool isMetric() const;
    bool isHeader() const;
    bool isAdjective() const;
    bool isPureAdjective() const;
    bool isPronoun() const;
    bool isQuestion() const;
    bool isVerb() const;
    bool isPortmanteau() const;
    bool isDeterminer() const;
    bool isConjunction() const;
    bool isAdverb() const;
    bool isPostP() const;
    bool isPortmanteauEndingWithSI() const;
    bool isPortmanteauFacedVowelEllipsis() const;
    bool isPortmanteauFacedSoftening() const;
    bool isSuffix() const;
    bool isProperNoun() const;
    bool isPlural() const;
    bool isNumeral() const;
    bool isReal() const;
    bool isFraction() const;
    bool isTime() const;
    bool isDate() const;
    bool isPercent() const;
    bool isRange() const;
    bool isOrdinal() const;
    bool notObeysVowelHarmonyDuringAgglutination() const;
    bool obeysAndNotObeysVowelHarmonyDuringAgglutination() const;
    bool rootSoftenDuringSuffixation() const;
    bool rootSoftenAndNotSoftenDuringSuffixation() const;
    bool verbSoftenDuringSuffixation() const;
    bool nounSoftenDuringSuffixation() const;
    bool endingKChangesIntoG() const;
    bool isExceptional() const;
    bool duplicatesDuringSuffixation() const;
    bool duplicatesAndNotDuplicatesDuringSuffixation() const;
    bool lastIdropsDuringSuffixation() const;
    bool lastIDropsAndNotDropDuringSuffixation() const;
    bool takesRelativeSuffixKi() const;
    bool takesRelativeSuffixKu() const;
    bool consonantSMayInsertedDuringPossesiveSuffixation() const;
    bool lastIdropsDuringPassiveSuffixation() const;
    bool vowelAChangesToIDuringYSuffixation() const;
    bool vowelEChangesToIDuringYSuffixation() const;
    bool takesSuffixIRAsAorist() const;
    bool takesSuffixDIRAsFactitive() const;
    bool showsSuRegularities() const;
    string to_string() const;
};


#endif //DICTIONARY_TXTWORD_H
