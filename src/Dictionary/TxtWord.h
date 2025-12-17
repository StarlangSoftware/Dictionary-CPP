//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#ifndef DICTIONARY_TXTWORD_H
#define DICTIONARY_TXTWORD_H

#include <string>
#include <unordered_set>
#include "Word.h"

using namespace std;

class TxtWord : public Word {
private:
    unordered_set<string> flags;
    string morphology;
public:
    explicit TxtWord(const string& name);
    TxtWord(const string& name, const string& flag);
    void addFlag(const string& flag);
    TxtWord* clone() const;
    void removeFlag(const string& flag);
    void setMorphology(const string& _morphology);
    [[nodiscard]] string getMorphology() const;
    [[nodiscard]] string verbType() const;
    [[nodiscard]] bool containsFlag(const string& flag) const;
    [[nodiscard]] bool samePos(const TxtWord& word) const;
    [[nodiscard]] bool isNominal() const;
    [[nodiscard]] bool isPassive() const;
    [[nodiscard]] bool isAbbreviation() const;
    [[nodiscard]] bool isInterjection() const;
    [[nodiscard]] bool isDuplicate() const;
    [[nodiscard]] bool isCode() const;
    [[nodiscard]] bool isMetric() const;
    [[nodiscard]] bool isHeader() const;
    [[nodiscard]] bool isAdjective() const;
    [[nodiscard]] bool isPureAdjective() const;
    [[nodiscard]] bool isPronoun() const;
    [[nodiscard]] bool isQuestion() const;
    [[nodiscard]] bool isVerb() const;
    [[nodiscard]] bool isPortmanteau() const;
    [[nodiscard]] bool isDeterminer() const;
    [[nodiscard]] bool isConjunction() const;
    [[nodiscard]] bool isAdverb() const;
    [[nodiscard]] bool isPostP() const;
    [[nodiscard]] bool isPortmanteauEndingWithSI() const;
    [[nodiscard]] bool isPortmanteauFacedVowelEllipsis() const;
    [[nodiscard]] bool isPortmanteauFacedSoftening() const;
    [[nodiscard]] bool isSuffix() const;
    [[nodiscard]] bool isProperNoun() const;
    [[nodiscard]] bool isPlural() const;
    [[nodiscard]] bool isNumeral() const;
    [[nodiscard]] bool isReal() const;
    [[nodiscard]] bool isFraction() const;
    [[nodiscard]] bool isTime() const;
    [[nodiscard]] bool isDate() const;
    [[nodiscard]] bool isPercent() const;
    [[nodiscard]] bool isRange() const;
    [[nodiscard]] bool isOrdinal() const;
    [[nodiscard]] bool notObeysVowelHarmonyDuringAgglutination() const;
    [[nodiscard]] bool obeysAndNotObeysVowelHarmonyDuringAgglutination() const;
    [[nodiscard]] bool rootSoftenDuringSuffixation() const;
    [[nodiscard]] bool rootSoftenAndNotSoftenDuringSuffixation() const;
    [[nodiscard]] bool verbSoftenDuringSuffixation() const;
    [[nodiscard]] bool nounSoftenDuringSuffixation() const;
    [[nodiscard]] bool endingKChangesIntoG() const;
    [[nodiscard]] bool isExceptional() const;
    [[nodiscard]] bool duplicatesDuringSuffixation() const;
    [[nodiscard]] bool duplicatesAndNotDuplicatesDuringSuffixation() const;
    [[nodiscard]] bool lastIdropsDuringSuffixation() const;
    [[nodiscard]] bool lastIDropsAndNotDropDuringSuffixation() const;
    [[nodiscard]] bool takesRelativeSuffixKi() const;
    [[nodiscard]] bool takesRelativeSuffixKu() const;
    [[nodiscard]] bool consonantSMayInsertedDuringPossesiveSuffixation() const;
    [[nodiscard]] bool lastIdropsDuringPassiveSuffixation() const;
    [[nodiscard]] bool vowelAChangesToIDuringYSuffixation() const;
    [[nodiscard]] bool vowelEChangesToIDuringYSuffixation() const;
    [[nodiscard]] bool takesSuffixIRAsAorist() const;
    [[nodiscard]] bool takesSuffixDIRAsFactitive() const;
    [[nodiscard]] bool showsSuRegularities() const;
    [[nodiscard]] string to_string() const;
};


#endif //DICTIONARY_TXTWORD_H
