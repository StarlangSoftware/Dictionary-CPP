//
// Created by Olcay Taner Yıldız on 5.01.2019.
//

#include <iostream>
#include "TxtDictionary.h"
#include "../Language/TurkishLanguage.h"

int main(){
    //TxtDictionary dictionary = TxtDictionary("turkish_dictionary.txt", Comparator::TURKISH);
    string text = "çöğüşıabcçdefgğhıijklmnoöprsştuüvyzABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";
    vector<string> allChar = Word::allCharacters(text);
    for (string s : allChar){
        cout << s << "\n";
    }
}