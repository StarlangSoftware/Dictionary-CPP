//
// Created by Olcay Taner Yıldız on 2.01.2019.
//

#include "TxtWord.h"

/**
 * A constructor of {@link TxtWord} class which takes a String name as an input and calls its super class {@link Word}
 * with given name.
 *
 * @param name String name.
 */
TxtWord::TxtWord(const string& name) : Word(name) {
}

/**
 * The addFlag method takes a String flag as an input and adds given flag to the flags {@link unordered_set}.
 *
 * @param flag String input to add.
 */
void TxtWord::addFlag(const string& flag) {
    flags.emplace(flag);
}

/**
 * Another constructor of {@link TxtWord} class which takes a String name and a flag as inputs and calls its super class {@link Word}
 * with given name. Then, calls addFlag method with given flag.
 *
 * @param name String input.
 * @param flag String input.
 */
TxtWord::TxtWord(const string& name, const string& flag) {
    this->name = name;
    addFlag(flag);
}

/**
 * The clone method creates {@link TxtWord} type copy with name and add items of flags {@link unordered_set}  to the copy.
 *
 * @return TxtWord type copy.
 */
TxtWord* TxtWord::clone() {
    auto* copy = new TxtWord(name);
    for (const string &flag : flags) {
        copy->addFlag(flag);
    }
    return copy;
}

/**
 * The removeFlag method takes a String flag as an input and removes given flag from the flags {@link unordered_set}.
 *
 * @param flag String input to remove.
 */
void TxtWord::removeFlag(const string& flag) {
    flags.erase(flag);
}

/**
 * The containsFlag method returns true if flags {@link unordered_set} contains flag.
 *
 * @return true if flags {@link unordered_set} contains flag.
 */
bool TxtWord::containsFlag(const string& flag) const {
    return flags.contains(flag);
}

void TxtWord::setMorphology(const string& _morphology){
    this->morphology = _morphology;
}

string TxtWord::getMorphology() const{
    return this->morphology;
}

/**
 * The verbType method checks flags {@link unordered_set} and returns the corresponding cases.
 *
 * @return the corresponding cases.
 */
string TxtWord::verbType() const {
    if (containsFlag("F1P1-NO-REF")) {
        /**
         *There is no example in the Turkish dictionary.
         */
        return "F1P1-NO-REF";
    }
    if (containsFlag("F2P1-NO-REF")) {
        /**
         *F2P1-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeT suffix. e.g. Doğ, göç, için
         */
        return "F2P1-NO-REF";
    }
    if (containsFlag("F3P1-NO-REF")) {
        /**
         *F3P1-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take Passive Hl suffix,
         *can take CausativeT suffix. e.g. Ak
         */
        return "F3P1-NO-REF";
    }
    if (containsFlag("F4P1-NO-REF")) {
        /**
         *F4P1-NO-REF: The bare-form is a verb and depending on this attribute, the verb can't take PassiveHn suffix, can take CausativeT suffix.
         *e.g. Aksa
         */
        return "F4P1-NO-REF";
    }
    if (containsFlag("F4PR-NO-REF")) {
        /**
         *F4PR-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeT suffix. e.g. Çevir, göster
         */
        return "F4PR-NO-REF";
    }
    if (containsFlag("F4PL-NO-REF")) {
        /**
         *F4PL-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeT suffix. e.g. Azal, çoğal
         */
        return "F4PL-NO-REF";
    }
    if (containsFlag("F4PW-NO-REF")) {
        /**
         *F4PW-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take CausativeT suffix. e.g. Birle, boya
         */
        return "F4PW-NO-REF";
    }
    if (containsFlag("F5PL-NO-REF")) {
        /**
         *F5PL-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeDHr suffix. e.g. Çal, kal
         */
        return "F5PL-NO-REF";
    }
    if (containsFlag("F5PR-NO-REF")) {
        /**
         *F5PR-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix. e.g. Birleş, çöz
         */
        return "F5PR-NO-REF";
    }
    if (containsFlag("F5PW-NO-REF")) {
        /**
         *F5PW-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix. e.g. Ye
         */
        return "F5PW-NO-REF";
    }
    if (containsFlag("F1P1")) {
        /**
         *F1P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeAr suffix, can take ReciprocalHs suffix. e.g. Çık, kop
         */
        return "F1P1";
    }
    if (containsFlag("F2P1")) {
        /**
         *F2P1: The bare-form is a verb and depending on this attribute, the verb can can not PassiveHn suffix, can take CausativeHr suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Bit, doy, düş
         */
        return "F2P1";
    }
    if (containsFlag("F2PL")) {
        /**
         *F2PL: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take CausativeHr suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Art, çök
         */
        return "F2PL";
    }
    if (containsFlag("F3P1")) {
        /**
         *F3P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeHl suffix, can take ReciprocalHs suffix. e.g. Kok, sark
         */
        return "F3P1";
    }
    if (containsFlag("F4P1")) {
        /**
         *F4P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Anla
         */
        return "F4P1";
    }
    if (containsFlag("F4PR")) {
        /**
         *F4PR: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Bitir, çağır
         */
        return "F4PR";
    }
    if (containsFlag("F4PL")) {
        /**
         *F4PL: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Bolal, çömel
         */
        return "F4PL";
    }
    if (containsFlag("F4PW")) {
        /**
         *F4PW: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Boyla, çağla
         */
        return "F4PW";
    }
    if (containsFlag("F5P1")) {
        /**
         *F5P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix, can take ReflexiveHn suffix. e.g. Giy
         */
        return "F5P1";
    }
    if (containsFlag("F5PL")) {
        /**
         *F5PL: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Böl, dal
         */
        return "F5PL";
    }
    if (containsFlag("F5PR")) {
        /**
         *F5PR: The bare-form is a verb and depending on this attribute, the verb can take NominalVerb suffixes "-sHm, -SHn, -yHz, SHnHz, -lAr",
         *can take NominalVerb1 suffixes, "-yDH, -ysA
         ", can take NominalVerb2 suffix, "-ymHs", can take AdjectiveRoot suffix, "-SH",
         *can take Adjective suffix, "-ŞAr" e.g. Bilin, çalış
         */
        return "F5PR";
    }
    if (containsFlag("F5PW")) {
        /**
         *F5PW: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Boşver, cezbet
         */
        return "F5PW";
    }
    if (containsFlag("F6P1")) {
        /**
         *F6P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take ReciprocalHs suffix, can take ReflexiveHn suffix. e.g. Gizle, hazırla, kaşı
         */
        return "F6P1";
    }
    return "";
}

/**
 * The isNominal method returns true if flags {@link unordered_set} contains CL_ISIM.
 *
 * @return true if flags {@link unordered_set} contains CL_ISIM.
 */
bool TxtWord::isNominal() const {
    return containsFlag("CL_ISIM");
}

/**
 * The isPassive method returns true if flags {@link unordered_set} contains PASSIVE-HN.
 *
 * @return true if flags {@link unordered_set} contains PASSIVE-HN.
 */
bool TxtWord::isPassive() const {
    return containsFlag("PASSIVE-HN");
}

/**
 * The isAbbreviation method returns true if flags {@link unordered_set} contains IS_KIS.
 *
 * @return true if flags {@link unordered_set} contains IS_KIS.
 */
bool TxtWord::isAbbreviation() const {
    /**
     *IS_KIS: The bare-form of the word is an abbrevation which does not obey
     *vowel harmony while taking suffixes. Örn. Ab
     */
    return containsFlag("IS_KIS");
}

/**
 * The isInterjection method returns true if flags {@link unordered_set} contains IS_INTERJ.
 *
 * @return true if flags {@link unordered_set} contains IS_INTERJ.
 */
bool TxtWord::isInterjection() const {
    /**
     *IS_INTERJ: An interjection is a part of speech that shows the emotion or feeling. e.g. Ah, aferin
     */
    return containsFlag("IS_INTERJ");
}

/**
 * The isDuplicate method returns true if flags {@link unordered_set} contains IS_DUP.
 *
 * @return true if flags {@link unordered_set} contains IS_DUP.
 */
bool TxtWord::isDuplicate() const {
    /**
     *IS_DUP: The bare-form is part of a duplicate form. e.g. Abuk
     */
    return containsFlag("IS_DUP");
}

/**
 * The isCode method returns true if flags {@link unordered_set} contains IS_CODE.
 *
 * @return true if flags {@link unordered_set} contains IS_CODE.
 */
bool TxtWord::isCode() const {
    return containsFlag("IS_CODE");
}

/**
 * The isCode method returns true if flags {@link unordered_set} contains IS_METRIC.
 *
 * @return true if flags {@link unordered_set} contains IS_METRIC.
 */
bool TxtWord::isMetric() const {
    return containsFlag("IS_METRIC");
}

/**
 * The isHeader method returns true if flags {@link unordered_set} contains IS_HEADER.
 *
 * @return true if flags {@link unordered_set} contains IS_HEADER.
 */
bool TxtWord::isHeader() const {
    return containsFlag("IS_HEADER");
}

/**
 * The isAdjective method returns true if flags {@link unordered_set} contains IS_ADJ.
 *
 * @return true if flags {@link unordered_set} contains IS_ADJ.
 */
bool TxtWord::isAdjective() const {
    return containsFlag("IS_ADJ");
}

/**
 * The isPureAdjective method returns true if flags {@link unordered_set} contains IS_PUREADJ.
 *
 * @return true if flags {@link unordered_set} contains IS_PUREADJ.
 */
bool TxtWord::isPureAdjective() const {
    return containsFlag("IS_PUREADJ");
}

/**
 * The isPronoun method returns true if flags {@link unordered_set} contains IS_ZM.
 *
 * @return true if flags {@link unordered_set} contains IS_ZM.
 */
bool TxtWord::isPronoun() const {
    /*
     *IS_ZM: The bare-form of the word is a pronoun. e.g. Hangi, hep, hiçbiri
     */
    return containsFlag("IS_ZM");
}

/**
 * The isQuestion method returns true if flags {@link unordered_set} contains IS_QUES.
 *
 * @return true if flags {@link unordered_set} contains IS_QUES.
 */
bool TxtWord::isQuestion() const {
    /*The bare-form of the word is a question. e.g. Mi, mu, mü
     */
    return containsFlag("IS_QUES");
}

/**
 * The isVerb method returns true if flags {@link unordered_set} contains CL_FIIL.
 *
 * @return true if flags {@link unordered_set} contains CL_FIIL.
 */
bool TxtWord::isVerb() const {
    return containsFlag("CL_FIIL");
}

/**
 * The isPortmanteau method returns true if flags {@link unordered_set} contains IS_BILEŞ.
 *
 * @return true if flags {@link unordered_set} contains IS_BILEŞ.
 */
bool TxtWord::isPortmanteau() const {
    return containsFlag("IS_BILEŞ");
}

/**
 * The isDeterminer method returns true if flags {@link unordered_set} contains IS_DET.
 *
 * @return true if flags {@link unordered_set} contains IS_DET.
 */
bool TxtWord::isDeterminer() const {
    /*
     *IS_DET: The bare-form of the word is a determiner. e.g. Bazı, bir
     */
    return containsFlag("IS_DET");
}

/**
 * The isConjunction method returns true if flags {@link unordered_set} contains IS_CONJ.
 *
 * @return true if flags {@link unordered_set} contains IS_CONJ.
 */
bool TxtWord::isConjunction() const {
    /*
     *IS_CONJ: The bare-form of the word is a conjunction. e.g. Gerek, halbuki
     */
    return containsFlag("IS_CONJ");
}

/**
 * The isAdverb method returns true if flags {@link unordered_set} contains IS_ADVERB.
 *
 * @return true if flags {@link unordered_set} contains IS_ADVERB.
 */
bool TxtWord::isAdverb() const {
    return containsFlag("IS_ADVERB");
}

/**
 * The isPostP method returns true if flags {@link unordered_set} contains IS_POSTP.
 *
 * @return true if flags {@link unordered_set} contains IS_POSTP.
 */
bool TxtWord::isPostP() const {
    /*
     *The bare-form of the word is a postposition. e.g. Önce, takdirde, üzere
     */
    return containsFlag("IS_POSTP");
}

/**
 * The isPortmanteauEndingWithSI method returns true if flags {@link unordered_set} contains IS_B_SI.
 *
 * @return true if flags {@link unordered_set} contains IS_B_SI.
 */
bool TxtWord::isPortmanteauEndingWithSI() const {
    /*
     *IS_B_SI: The bare-form is a portmanteau word ending with "sı". e.g. Giritlalesi
     */
    return containsFlag("IS_B_SI");
}

/**
 * The isPortmanteauFacedVowelEllipsis method returns true if flags {@link unordered_set} contains IS_B_UD.
 *
 * @return true if flags {@link unordered_set} contains IS_B_UD.
 */
bool TxtWord::isPortmanteauFacedVowelEllipsis() const {
    /*
     *IS_B_UD: The bare-form of the word includes vowel epenthesis,
     *therefore the last inserted vowel drops during suffixation. e.g. İnsanoğlu
     */
    return containsFlag("IS_B_UD");
}

/**
 * The isPortmanteauFacedSoftening method returns true if flags {@link unordered_set} contains IS_B_UD.
 *
 * @return true if flags {@link unordered_set} contains IS_B_SD.
 */
bool TxtWord::isPortmanteauFacedSoftening() const {
    /*
     *IS_B_SD: The bare-form of the word includes softening. e.g. Çançiçeği
     */
    return containsFlag("IS_B_SD");
}

/**
 * The isSuffix method returns true if flags {@link unordered_set} contains EK.
 *
 * @return true if flags {@link unordered_set} contains EK.
 */
bool TxtWord::isSuffix() const {
    /*
     * EK: This tag indicates complementary verbs. e.g. İdi, iken, imiş.
     */
    return containsFlag("EK");
}

/**
 * The isProperNoun method returns true if flags {@link unordered_set} contains IS_OA.
 *
 * @return true if flags {@link unordered_set} contains IS_OA.
 */
bool TxtWord::isProperNoun() const {
    /*
     *IS_OA: The bare-form of the word is a proper noun. e.g. Abant, Beşiktaş
     */
    return containsFlag("IS_OA");
}

/**
 * The isPlural method returns true if flags {@link unordered_set} contains IS_CA.
 *
 * @return true if flags {@link unordered_set} contains IS_CA.
 */
bool TxtWord::isPlural() const {
    /*
     *IS_CA: The bare-form of the word is already in a plural form,
     *therefore can not take plural suffixes such as "ler" or "lar". e.g. Buğdaygiller
     */
    return containsFlag("IS_CA");
}

/**
 * The isNumeral method returns true if flags {@link unordered_set} contains IS_SAYI.
 *
 * @return true if flags {@link unordered_set} contains IS_SAYI.
 */
bool TxtWord::isNumeral() const {
    /*
     *IS_SAYI: The word is a number. e.g. Dört
     */
    return containsFlag("IS_SAYI");
}

/**
 * The isReal method returns true if flags {@link unordered_set} contains IS_REELSAYI.
 *
 * @return true if flags {@link unordered_set} contains IS_REELSAYI.
 */
bool TxtWord::isReal() const {
    return containsFlag("IS_REELSAYI");
}

/**
 * The isFraction method returns true if flags {@link unordered_set} contains IS_KESIR.
 *
 * @return true if flags {@link unordered_set} contains IS_KESIR.
 */
bool TxtWord::isFraction() const {
    return containsFlag("IS_KESIR");
}

/**
 * The isTime method returns true if flags {@link unordered_set} contains IS_ZAMAN.
 *
 * @return true if flags {@link unordered_set} contains IS_ZAMAN.
 */
bool TxtWord::isTime() const {
    return containsFlag("IS_ZAMAN");
}

/**
 * The isDate method returns true if flags {@link unordered_set} contains IS_DATE.
 *
 * @return true if flags {@link unordered_set} contains IS_DATE.
 */
bool TxtWord::isDate() const {
    return containsFlag("IS_DATE");
}

/**
 * The isPercent method returns true if flags {@link unordered_set} contains IS_PERCENT.
 *
 * @return true if flags {@link unordered_set} contains IS_PERCENT.
 */
bool TxtWord::isPercent() const {
    return containsFlag("IS_PERCENT");
}

/**
 * The isRange method returns true if flags {@link unordered_set} contains IS_RANGE.
 *
 * @return true if flags {@link unordered_set} contains IS_RANGE.
 */
bool TxtWord::isRange() const {
    return containsFlag("IS_RANGE");
}

/**
 * The isOrdinal method returns true if flags {@link unordered_set} contains IS_ORD.
 *
 * @return true if flags {@link unordered_set} contains IS_ORD.
 */
bool TxtWord::isOrdinal() const {
    /*
     *IS_ORD: The bare-form of the word can take suffixes and these suffixes define a ranking. e.g. Birinci
     */
    return containsFlag("IS_ORD");
}

/**
 * The notObeysVowelHarmonyDuringAgglutination method returns true if flags {@link unordered_set} contains IS_UU.
 *
 * @return true if flags {@link unordered_set} contains IS_UU.
 */
bool TxtWord::notObeysVowelHarmonyDuringAgglutination() const {
    /*
     *IS_UU: The bare-form does not obey vowel harmony while taking suffixes. e.g. Dikkat
     */
    return containsFlag("IS_UU");
}

/**
 * The obeysAndNotObeysVowelHarmonyDuringAgglutination method returns true if flags {@link unordered_set} contain IS_UUU.
 *
 * @return true if flags {@link unordered_set} contains IS_UUU.
 */
bool TxtWord::obeysAndNotObeysVowelHarmonyDuringAgglutination() const {
    /*
     *IS_UUU: The bare-form does not obey vowel harmony while taking suffixes. e.g. Bol, kalp
     */
    return containsFlag("IS_UUU");
}

/**
 * The rootSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains IS_SD, F_SD.
 *
 * @return true if flags {@link unordered_set} contains IS_SD, F_SD.
 */
bool TxtWord::rootSoftenDuringSuffixation() const {
    /*
     *IS_SD: The bare-form final consonant gets devoiced during vowel-initial suffixation. e.g. Çakmak
     */
    return containsFlag("IS_SD") || containsFlag("F_SD");
}

/**
 * The rootSoftenAndNotSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains IS_SDD.
 *
 * @return true if flags {@link unordered_set} contains IS_SDD.
 */
bool TxtWord::rootSoftenAndNotSoftenDuringSuffixation() const {
    /*
     *The bare-form final consonant can (or can not) get devoiced during vowel-initial suffixation. e.g. Kalp
     */
    return containsFlag("IS_SDD");
}

/**
 * The verbSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains F_SD.
 *
 * @return true if flags {@link unordered_set} contains F_SD.
 */
bool TxtWord::verbSoftenDuringSuffixation() const {
    /*
     * F_SD: The bare-form final consonant gets devoiced during vowel-initial suffixation. e.g. Cezbet
     */
    return containsFlag("F_SD");
}

/**
 * The nounSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains IS_SD.
 *
 * @return true if flags {@link unordered_set} contains IS_SD.
 */
bool TxtWord::nounSoftenDuringSuffixation() const {
    /*
     *IS_SD: The bare-form final consonant already has an accusative suffix. e.g. Kabağı
     */
    return containsFlag("IS_SD");
}

/**
 * The endingKChangesIntoG method returns true if flags {@link unordered_set} contains IS_KG.
 *
 * @return true if flags {@link unordered_set} contains IS_KG.
 */
bool TxtWord::endingKChangesIntoG() const {
    /*
     *IS_KG: The bare-form includes vowel epenthesis, therefore the last inserted vowel drope
     *during suffixation. e.g. Çelenk
     */
    return containsFlag("IS_KG");
}

/**
 * The isExceptional method returns true if flags {@link unordered_set} contains IS_EX.
 *
 * @return true if flags {@link unordered_set} contains IS_EX.
 */
bool TxtWord::isExceptional() const {
    /*
     *IS_EX: This tag defines exception words. e.g. Delikanlı
     */
    return containsFlag("IS_EX");
}

/**
 * The duplicatesDuringSuffixation method returns true if flags {@link unordered_set} contains IS_ST.
 *
 * @return true if flags {@link unordered_set} contains IS_ST.
 */
bool TxtWord::duplicatesDuringSuffixation() const {
    /*
     *IS_ST: The second consonant of the bare-form undergoes a resyllabification. e.g. His
     */
    return containsFlag("IS_ST");
}

/**
 * The duplicatesAndNotDuplicatesDuringSuffixation method returns true if flags {@link unordered_set} contains IS_STT.
 *
 * @return true if flags {@link unordered_set} contains IS_STT.
 */
bool TxtWord::duplicatesAndNotDuplicatesDuringSuffixation() const {
    /*
     *IS_STT: The second consonant of the bare-form undergoes a resyllabification. e.g. His
     */
    return containsFlag("IS_STT");
}

/**
 * The lastIdropsDuringSuffixation method returns true if flags {@link unordered_set} contains IS_UD.
 *
 * @return true if flags {@link unordered_set} contains IS_UD.
 */
bool TxtWord::lastIdropsDuringSuffixation() const {
    /*
     *IS_UD: The bare-form includes vowel epenthesis, therefore the last inserted vowel drops during suffixation.
     *e.g. Boyun
     */
    return containsFlag("IS_UD");
}

/**
 * The lastIDropsAndNotDropDuringSuffixation method returns true if flags {@link unordered_set} contains IS_UDD.
 *
 * @return true if flags {@link unordered_set} contains IS_UDD.
 */
bool TxtWord::lastIDropsAndNotDropDuringSuffixation() const {
    /*
     *The bare-form includes vowel epenthesis, therefore the last inserted vowel can (or can not) drop during suffixation. e.g. Kadir
     */
    return containsFlag("IS_UDD");
}

/**
 * The takesRelativeSuffixKi method returns true if flags {@link unordered_set} contains IS_KI.
 *
 * @return true if flags {@link unordered_set} contains IS_KI.
 */
bool TxtWord::takesRelativeSuffixKi() const {
    /*
     *IS_KI: The word can take a suffix such as "ki". e.g. Önce
     */
    return containsFlag("IS_KI");
}

/**
 * The takesRelativeSuffixKu method returns true if flags {@link unordered_set} contains IS_KU.
 *
 * @return true if flags {@link unordered_set} contains IS_KU.
 */
bool TxtWord::takesRelativeSuffixKu() const {
    /*
     *IS_KU: The word can take a suffix such as "kü". e.g. Bugün
     */
    return containsFlag("IS_KU");
}

/**
 * The consonantSMayInsertedDuringPossesiveSuffixation method returns true if flags {@link unordered_set} contains IS_SII.
 *
 * @return true if flags {@link unordered_set} contains IS_SII.
 */
bool TxtWord::consonantSMayInsertedDuringPossesiveSuffixation() const {
    return containsFlag("IS_SII");
}

/**
 * The lastIdropsDuringPassiveSuffixation method returns true if flags {@link unordered_set} contains F_UD.
 *
 * @return true if flags {@link unordered_set} contains F_UD.
 */
bool TxtWord::lastIdropsDuringPassiveSuffixation() const {
    /*
     *F_UD: The bare-form includes vowel epenthesis, therefore the last "ı"
     *drops during passive suffixation. e.g. Çağır
     */
    return containsFlag("F_UD");
}

/**
 * The vowelAChangesToIDuringYSuffixation method returns true if flags {@link unordered_set} contains F_GUD.
 *
 * @return true if flags {@link unordered_set} contains F_GUD.
 */
bool TxtWord::vowelAChangesToIDuringYSuffixation() const {
    /*
     *F_GUD: The verb bare-form includes viwel reduction, the last vowel "a" of the bare-form is replaced with "ı"
     *e.g. Buzağıla
     */
    return containsFlag("F_GUD");
}

/**
 * The vowelEChangesToIDuringYSuffixation method returns true if flags {@link unordered_set} contains F_GUDO.
 *
 * @return true if flags {@link unordered_set} contains F_GUDO.
 */
bool TxtWord::vowelEChangesToIDuringYSuffixation() const {
    /*
     *F_GUDO: The verb bare-form includes viwel reduction, the last vowel "e" of the
     *bare-form is replaced with "i". e.g. Ye
     */
    return containsFlag("F_GUDO");
}

/**
 * The takesSuffixIRAsAorist method returns true if flags {@link unordered_set} contains F_GIR.
 *
 * @return true if flags {@link unordered_set} contains F_GIR.
 */
bool TxtWord::takesSuffixIRAsAorist() const {
    /*
     *F_GIR: The bare-form of the word takes "ir" suffix. e.g. Geç
     */
    return !containsFlag("F_GIR");
}

/**
 * The takesSuffixDIRAsFactitive method returns true if flags {@link unordered_set} contains F_DIR.
 *
 * @return true if flags {@link unordered_set} contains F_DIR.
 */
bool TxtWord::takesSuffixDIRAsFactitive() const {
    /*
     *F_DIR: The bare-form of the word takes "tır" suffix. e.g. Daral
     */
    return !containsFlag("F_DIR");
}

/**
 * The showsSuRegularities method returns true if flags {@link unordered_set} contains IS_SU.
 *
 * @return true if flags {@link unordered_set} contains IS_SU.
 */
bool TxtWord::showsSuRegularities() const {
    return containsFlag("IS_SU");
}

/**
 * The samePos method takes {@link TxtWord} as input and returns true if;
 * <p>
 * flags {@link unordered_set} contains CL_ISIM or given word is CL_ISIM or
 * CL_ISIM: The bare-form of the word is a noun. e.g. Abla
 * <p>
 * flags {@link unordered_set} contains CL_FIIL or given word is CL_FIIL or
 * CL_FIIL: The bare-form of the word is a verb. e.g. Affet
 * <p>
 * flags {@link unordered_set} contains IS_ADJ or given word is IS_ADJ or
 * IS_ADJ: The bare-form of the word is a adjective. e.g. Acayip
 * <p>
 * flags {@link unordered_set} contains IS_ZM or given word is IS_ZM or
 * IS_ZM: The bare-form of the word is a pronoun. e.g. Başkası
 * <p>
 * flags {@link unordered_set} contains IS_ADVERB or given word is IS_ADVERB, false otherwise.
 * IS_ADVERB: The bare-form of the word is a adverb. e.g. Tekrar, açıktan, adeta
 *
 * @param word {@link TxtWord} type input.
 * @return true if given word is nominal, verb, adjective, pronoun or adverb, false otherwise.
 */
bool TxtWord::samePos(const TxtWord& word) const {
    if (isNominal() && word.isNominal()) {
        return true;
    }
    if (isVerb() && word.isVerb()) {
        return true;
    }
    if (isAdjective() && word.isAdjective()) {
        return true;
    }
    if (isPronoun() && word.isPronoun()) {
        return true;
    }
    if (isAdverb() && word.isAdverb()) {
        return true;
    }
    return false;
}

string TxtWord::to_string() const{
    string result;
    for (const string &flag : flags){
        result += " ";
        result += flag;
    }
    return result;
}
