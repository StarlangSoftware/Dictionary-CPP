//
// Created by Olcay Taner YILDIZ on 26.12.2020.
//

#include "catch.hpp"
#include "../Dictionary/TxtDictionary.h"

TEST_CASE("TxtWordTest-testVerbType") {
    TxtDictionary dictionary = TxtDictionary();
    map<string, int> verbs;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        string verbType = word->verbType();
        if (verbs.contains(verbType)){
            verbs[verbType] = verbs[verbType] + 1;
        } else {
            verbs[verbType] = 1;
        }
    }
    REQUIRE(5 == verbs["F2P1-NO-REF"]);
    REQUIRE(1 == verbs["F3P1-NO-REF"]);
    REQUIRE(1 == verbs["F4P1-NO-REF"]);
    REQUIRE(14 == verbs["F4PR-NO-REF"]);
    REQUIRE(2 == verbs["F4PL-NO-REF"]);
    REQUIRE(67 == verbs["F4PW-NO-REF"]);
    REQUIRE(10 == verbs["F5PL-NO-REF"]);
    REQUIRE(111 == verbs["F5PR-NO-REF"]);
    REQUIRE(1 == verbs["F5PW-NO-REF"]);
    REQUIRE(2 == verbs["F1P1"]);
    REQUIRE(11 == verbs["F2P1"]);
    REQUIRE(4 == verbs["F3P1"]);
    REQUIRE(1 == verbs["F4P1"]);
    REQUIRE(1 == verbs["F5P1"]);
    REQUIRE(7 == verbs["F6P1"]);
    REQUIRE(2 == verbs["F2PL"]);
    REQUIRE(49 == verbs["F4PL"]);
    REQUIRE(18 == verbs["F5PL"]);
    REQUIRE(173 == verbs["F4PR"]);
    REQUIRE(808 == verbs["F5PR"]);
    REQUIRE(1396 == verbs["F4PW"]);
    REQUIRE(13 == verbs["F5PW"]);
}

TEST_CASE("TxtWordTest-testIsNominal") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isNominal()){
            count++;
        }
    }
    REQUIRE(30598 == count);
}

TEST_CASE("TxtWordTest-testIsPassive") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPassive()){
            count++;
        }
    }
    REQUIRE(10 == count);
}

TEST_CASE("TxtWordTest-testIsAbbreviation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isAbbreviation()){
            count++;
        }
    }
    REQUIRE(102 == count);
}

TEST_CASE("TxtWordTest-testIsInterjection") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isInterjection()){
            count++;
        }
    }
    REQUIRE(106 == count);
}

TEST_CASE("TxtWordTest-testIsDuplicate") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isDuplicate()){
            count++;
        }
    }
    REQUIRE(124 == count);
}

TEST_CASE("TxtWordTest-testIsAdjective") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isAdjective()){
            count++;
        }
    }
    REQUIRE(9686 == count);
}

TEST_CASE("TxtWordTest-testIsPronoun") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPronoun()){
            count++;
        }
    }
    REQUIRE(49 == count);
}

TEST_CASE("TxtWordTest-testIsQuestion") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isQuestion()){
            count++;
        }
    }
    REQUIRE(4 == count);
}

TEST_CASE("TxtWordTest-testIsVerb") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isVerb()){
            count++;
        }
    }
    REQUIRE(5043 == count);
}

TEST_CASE("TxtWordTest-testIsPortmanteau") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPortmanteau()){
            count++;
        }
    }
    REQUIRE(1292 == count);
}

TEST_CASE("TxtWordTest-testIsDeterminer") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isDeterminer()){
            count++;
        }
    }
    REQUIRE(13 == count);
}

TEST_CASE("TxtWordTest-testIsConjunction") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isConjunction()){
            count++;
        }
    }
    REQUIRE(52 == count);
}

TEST_CASE("TxtWordTest-testIsAdverb") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isAdverb()){
            count++;
        }
    }
    REQUIRE(1849 == count);
}

TEST_CASE("TxtWordTest-testIsPostP") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPostP()){
            count++;
        }
    }
    REQUIRE(49 == count);
}

TEST_CASE("TxtWordTest-testIsPortmanteauEndingWithSI") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPortmanteauEndingWithSI()){
            count++;
        }
    }
    REQUIRE(177 == count);
}

TEST_CASE("TxtWordTest-testIsPortmanteauFacedVowelEllipsis") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPortmanteauFacedVowelEllipsis()){
            count++;
        }
    }
    REQUIRE(25 == count);
}

TEST_CASE("TxtWordTest-testIsPortmanteauFacedSoftening") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPortmanteauFacedSoftening()){
            count++;
        }
    }
    REQUIRE(347 == count);
}

TEST_CASE("TxtWordTest-testIsSuffix") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isSuffix()){
            count++;
        }
    }
    REQUIRE(3 == count);
}

TEST_CASE("TxtWordTest-testIsProperNoun") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isProperNoun()){
            count++;
        }
    }
    REQUIRE(19013 == count);
}

TEST_CASE("TxtWordTest-testIsPlural") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isPlural()){
            count++;
        }
    }
    REQUIRE(398 == count);
}

TEST_CASE("TxtWordTest-testIsNumeral") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isNumeral()){
            count++;
        }
    }
    REQUIRE(33 == count);
}

TEST_CASE("TxtWordTest-testNotObeysVowelHarmonyDuringAgglutination") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->notObeysVowelHarmonyDuringAgglutination()){
            count++;
        }
    }
    REQUIRE(315 == count);
}

TEST_CASE("TxtWordTest-testObeysAndNotObeysVowelHarmonyDuringAgglutination") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->obeysAndNotObeysVowelHarmonyDuringAgglutination()){
            count++;
        }
    }
    REQUIRE(5 == count);
}

TEST_CASE("TxtWordTest-testRootSoftenDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->rootSoftenDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(5530 == count);
}

TEST_CASE("TxtWordTest-testRootSoftenAndNotSoftenDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->rootSoftenAndNotSoftenDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(14 == count);
}

TEST_CASE("TxtWordTest-testVerbSoftenDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->verbSoftenDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(87 == count);
}

TEST_CASE("TxtWordTest-testNounSoftenDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->nounSoftenDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(5444 == count);
}

TEST_CASE("TxtWordTest-testEndingKChangesIntoG") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->endingKChangesIntoG()){
            count++;
        }
    }
    REQUIRE(26 == count);
}

TEST_CASE("TxtWordTest-testIsExceptional") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->isExceptional()){
            count++;
        }
    }
    REQUIRE(31 == count);
}

TEST_CASE("TxtWordTest-testDuplicatesDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->duplicatesDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(36 == count);
}

TEST_CASE("TxtWordTest-testDuplicatesAndNotDuplicatesDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->duplicatesAndNotDuplicatesDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(4 == count);
}

TEST_CASE("TxtWordTest-testLastIdropsDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->lastIdropsDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(167 == count);
}

TEST_CASE("TxtWordTest-testLastIDropsAndNotDropDuringSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->lastIDropsAndNotDropDuringSuffixation()){
            count++;
        }
    }
    REQUIRE(4 == count);
}

TEST_CASE("TxtWordTest-testTakesRelativeSuffixKi") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->takesRelativeSuffixKi()){
            count++;
        }
    }
    REQUIRE(16 == count);
}

TEST_CASE("TxtWordTest-testTakesRelativeSuffixKu") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->takesRelativeSuffixKu()){
            count++;
        }
    }
    REQUIRE(4 == count);
}

TEST_CASE("TxtWordTest-testLastIdropsDuringPassiveSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->lastIdropsDuringPassiveSuffixation()){
            count++;
        }
    }
    REQUIRE(11 == count);
}

TEST_CASE("TxtWordTest-testVowelAChangesToIDuringYSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->vowelAChangesToIDuringYSuffixation()){
            count++;
        }
    }
    REQUIRE(1301 == count);
}

TEST_CASE("TxtWordTest-testVowelEChangesToIDuringYSuffixation") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->vowelEChangesToIDuringYSuffixation()){
            count++;
        }
    }
    REQUIRE(2 == count);
}

TEST_CASE("TxtWordTest-testTakesSuffixIRAsAorist") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (!word->takesSuffixIRAsAorist()){
            count++;
        }
    }
    REQUIRE(51 == count);
}

TEST_CASE("TxtWordTest-testTakesSuffixDIRAsFactitive") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (!word->takesSuffixDIRAsFactitive()){
            count++;
        }
    }
    REQUIRE(197 == count);
}

TEST_CASE("TxtWordTest-testShowsSuRegularities") {
    TxtDictionary dictionary = TxtDictionary();
    int count = 0;
    for (int i = 0; i < dictionary.size(); i++){
        auto* word = (TxtWord*) dictionary.getWord(i);
        if (word->showsSuRegularities()){
            count++;
        }
    }
    REQUIRE(5 == count);
}
