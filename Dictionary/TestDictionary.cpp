//
// Created by Olcay Taner Yıldız on 5.01.2019.
//

#include <iostream>
#include "TxtDictionary.h"

int main(){
    TxtDictionary dictionary = TxtDictionary("../dictionary.txt", Comparator::ENGLISH);
    int index = dictionary.getWordIndex("a");
    cout << index << "\n";
    string text = "abcçdefgğhıijklmnoöpqrsştuüvwxyzABCÇDEFGĞHIİJKLMNOÖPQRSŞTUÜVWXYZ";
    string text2 = "çöğüöı";
    cout << Word::lastChar(text2);
}