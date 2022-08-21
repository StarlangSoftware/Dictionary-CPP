//
// Created by Olcay Taner YILDIZ on 26.12.2020.
//

#include "catch.hpp"
#include "../src/Dictionary/Word.h"

TEST_CASE("WordTest-testCharCount") {
    Word word = Word("ali");
    REQUIRE(3 == word.charCount());
    word = Word("Veli");
    REQUIRE(4 == word.charCount());
    word = Word("ahmet");
    REQUIRE(5 == word.charCount());
    word = Word("çöğüşı");
    REQUIRE(6 == word.charCount());
}

TEST_CASE("WordTest-testIsCapital") {
    REQUIRE_FALSE(Word::isCapital("ali"));
    REQUIRE_FALSE(!Word::isCapital("Ali"));
    REQUIRE_FALSE(Word::isCapital("ısı"));
    REQUIRE_FALSE(!Word::isCapital("Isıtıcı"));
    REQUIRE_FALSE(Word::isCapital("çin"));
    REQUIRE_FALSE(!Word::isCapital("Çin"));
    REQUIRE_FALSE(Word::isCapital("ödül"));
    REQUIRE_FALSE(!Word::isCapital("Ödül"));
    REQUIRE_FALSE(Word::isCapital("şişe"));
    REQUIRE_FALSE(!Word::isCapital("Şişe"));
    REQUIRE_FALSE(Word::isCapital("üretici"));
    REQUIRE_FALSE(!Word::isCapital("Üretici"));
}

TEST_CASE("WordTest-testIsPunctuation") {
    REQUIRE_FALSE(!Word::isPunctuation("."));
    REQUIRE_FALSE(!Word::isPunctuation("..."));
    REQUIRE_FALSE(!Word::isPunctuation("["));
    REQUIRE_FALSE(!Word::isPunctuation("]"));
    REQUIRE_FALSE(!Word::isPunctuation("\u2026"));
    REQUIRE_FALSE(!Word::isPunctuation("%"));
    REQUIRE_FALSE(!Word::isPunctuation("&"));
    REQUIRE_FALSE(!Word::isPunctuation("="));
    REQUIRE_FALSE(!Word::isPunctuation("\u0060\u0060"));
    REQUIRE_FALSE(!Word::isPunctuation("\u0060"));
    REQUIRE_FALSE(!Word::isPunctuation("''"));
    REQUIRE_FALSE(!Word::isPunctuation("$"));
    REQUIRE_FALSE(!Word::isPunctuation("!"));
    REQUIRE_FALSE(!Word::isPunctuation("?"));
    REQUIRE_FALSE(!Word::isPunctuation(","));
    REQUIRE_FALSE(!Word::isPunctuation(":"));
    REQUIRE_FALSE(!Word::isPunctuation("--"));
    REQUIRE_FALSE(!Word::isPunctuation(";"));
    REQUIRE_FALSE(!Word::isPunctuation("("));
    REQUIRE_FALSE(!Word::isPunctuation(")"));
    REQUIRE_FALSE(!Word::isPunctuation("'"));
    REQUIRE_FALSE(!Word::isPunctuation("\""));
    REQUIRE_FALSE(!Word::isPunctuation("\u201C"));
    REQUIRE_FALSE(!Word::isPunctuation("\u2018"));
    REQUIRE_FALSE(!Word::isPunctuation("\u201D"));
    REQUIRE_FALSE(!Word::isPunctuation("…"));
    REQUIRE_FALSE(!Word::isPunctuation("\u25CF"));
    REQUIRE_FALSE(!Word::isPunctuation("/"));
    REQUIRE_FALSE(!Word::isPunctuation("-"));
    REQUIRE_FALSE(!Word::isPunctuation("+"));
    REQUIRE_FALSE(!Word::isPunctuation("-LRB-"));
    REQUIRE_FALSE(!Word::isPunctuation("-RRB-"));
    REQUIRE_FALSE(!Word::isPunctuation("-LCB-"));
    REQUIRE_FALSE(!Word::isPunctuation("-RCB-"));
    REQUIRE_FALSE(!Word::isPunctuation("-LSB-"));
    REQUIRE_FALSE(!Word::isPunctuation("-RSB-"));
}

TEST_CASE("WordTest-testIsHonorific") {
    REQUIRE_FALSE(!Word::isHonorific("bay"));
    REQUIRE_FALSE(!Word::isHonorific("Bay"));
    REQUIRE_FALSE(!Word::isHonorific("BAY"));
    REQUIRE_FALSE(!Word::isHonorific("bayan"));
    REQUIRE_FALSE(!Word::isHonorific("Bayan"));
    REQUIRE_FALSE(!Word::isHonorific("BAYAN"));
}

TEST_CASE("WordTest-testIsOrganization") {
    REQUIRE_FALSE(!Word::isOrganization("corp"));
    REQUIRE_FALSE(!Word::isOrganization("Corp"));
    REQUIRE_FALSE(!Word::isOrganization("inc."));
    REQUIRE_FALSE(!Word::isOrganization("co."));
    REQUIRE_FALSE(!Word::isOrganization("Co."));
}

TEST_CASE("WordTest-testToLowerCase") {
    REQUIRE(Word::toLowerCase("ABCDEFGHJKLMNOPQRSTUVWXYZÇÖĞÜŞIİ") == "abcdefghjklmnopqrstuvwxyzçöğüşıi");
}

TEST_CASE("WordTest-testToUpperCase") {
    REQUIRE(Word::toUpperCase("abcdefghjklmnopqrstuvwxyzçöğüşıi") == "ABCDEFGHJKLMNOPQRSTUVWXYZÇÖĞÜŞIİ");
}

TEST_CASE("WordTest-testIsMoney") {
    REQUIRE_FALSE(!Word::isMoney("dolar"));
    REQUIRE_FALSE(!Word::isMoney("sterlin"));
    REQUIRE_FALSE(!Word::isMoney("paunt"));
    REQUIRE_FALSE(!Word::isMoney("ons"));
    REQUIRE_FALSE(!Word::isMoney("ruble"));
    REQUIRE_FALSE(!Word::isMoney("mark"));
    REQUIRE_FALSE(!Word::isMoney("frank"));
    REQUIRE_FALSE(!Word::isMoney("sent"));
    REQUIRE_FALSE(!Word::isMoney("cent"));
    REQUIRE_FALSE(!Word::isMoney("yen"));
    REQUIRE_FALSE(!Word::isMoney("Dolar"));
    REQUIRE_FALSE(!Word::isMoney("Sterlin"));
    REQUIRE_FALSE(!Word::isMoney("Paunt"));
    REQUIRE_FALSE(!Word::isMoney("Ons"));
    REQUIRE_FALSE(!Word::isMoney("Ruble"));
    REQUIRE_FALSE(!Word::isMoney("Mark"));
    REQUIRE_FALSE(!Word::isMoney("Frank"));
    REQUIRE_FALSE(!Word::isMoney("Sent"));
    REQUIRE_FALSE(!Word::isMoney("Cent"));
    REQUIRE_FALSE(!Word::isMoney("Yen"));
    REQUIRE_FALSE(!Word::isMoney("3000$"));
    REQUIRE_FALSE(Word::isMoney("3000"));
}

TEST_CASE("WordTest-testIsTime") {
    REQUIRE_FALSE(!Word::isTime("9:1"));
    REQUIRE_FALSE(!Word::isTime("9:12"));
    REQUIRE_FALSE(!Word::isTime("12:1"));
    REQUIRE_FALSE(!Word::isTime("12:13"));
    REQUIRE_FALSE(!Word::isTime("1:9:1"));
    REQUIRE_FALSE(!Word::isTime("1:9:12"));
    REQUIRE_FALSE(!Word::isTime("1:12:1"));
    REQUIRE_FALSE(!Word::isTime("2:13:14"));
    REQUIRE_FALSE(!Word::isTime("12:9:1"));
    REQUIRE_FALSE(!Word::isTime("11:9:12"));
    REQUIRE_FALSE(!Word::isTime("10:12:1"));
    REQUIRE_FALSE(!Word::isTime("21:13:14"));
    REQUIRE_FALSE(Word::isTime("12"));
    REQUIRE_FALSE(!Word::isTime("ocak"));
    REQUIRE_FALSE(!Word::isTime("şubat"));
    REQUIRE_FALSE(!Word::isTime("mart"));
    REQUIRE_FALSE(!Word::isTime("nisan"));
    REQUIRE_FALSE(!Word::isTime("mayıs"));
    REQUIRE_FALSE(!Word::isTime("haziran"));
    REQUIRE_FALSE(!Word::isTime("temmuz"));
    REQUIRE_FALSE(!Word::isTime("ağustos"));
    REQUIRE_FALSE(!Word::isTime("eylül"));
    REQUIRE_FALSE(!Word::isTime("ekim"));
    REQUIRE_FALSE(!Word::isTime("kasım"));
    REQUIRE_FALSE(!Word::isTime("aralık"));
    REQUIRE_FALSE(!Word::isTime("Ocak"));
    REQUIRE_FALSE(!Word::isTime("Şubat"));
    REQUIRE_FALSE(!Word::isTime("Mart"));
    REQUIRE_FALSE(!Word::isTime("Nisan"));
    REQUIRE_FALSE(!Word::isTime("Mayıs"));
    REQUIRE_FALSE(!Word::isTime("Haziran"));
    REQUIRE_FALSE(!Word::isTime("Temmuz"));
    REQUIRE_FALSE(!Word::isTime("Ağustos"));
    REQUIRE_FALSE(!Word::isTime("Eylül"));
    REQUIRE_FALSE(!Word::isTime("Ekim"));
    REQUIRE_FALSE(!Word::isTime("Kasım"));
    REQUIRE_FALSE(!Word::isTime("Aralık"));
    REQUIRE_FALSE(!Word::isTime("pazartesi"));
    REQUIRE_FALSE(!Word::isTime("salı"));
    REQUIRE_FALSE(!Word::isTime("çarşamba"));
    REQUIRE_FALSE(!Word::isTime("perşembe"));
    REQUIRE_FALSE(!Word::isTime("cuma"));
    REQUIRE_FALSE(!Word::isTime("cumartesi"));
    REQUIRE_FALSE(!Word::isTime("pazar"));
    REQUIRE_FALSE(!Word::isTime("Pazartesi"));
    REQUIRE_FALSE(!Word::isTime("Salı"));
    REQUIRE_FALSE(!Word::isTime("Çarşamba"));
    REQUIRE_FALSE(!Word::isTime("Perşembe"));
    REQUIRE_FALSE(!Word::isTime("Cuma"));
    REQUIRE_FALSE(!Word::isTime("Cumartesi"));
    REQUIRE_FALSE(!Word::isTime("Pazar"));
    REQUIRE_FALSE(Word::isTime("1234567"));
    REQUIRE_FALSE(Word::isTime("-1234"));
    REQUIRE_FALSE(Word::isTime("1834"));
    REQUIRE_FALSE(Word::isTime("2201"));
    REQUIRE_FALSE(!Word::isTime("1934"));
}