//
// Created by Olcay Taner Yıldız on 5.01.2019.
//

#include <iostream>
#include "TxtDictionary.h"
#include "../Language/TurkishLanguage.h"

int main(){
    //TxtDictionary dictionary = TxtDictionary("turkish_dictionary.txt", Comparator::TURKISH);
    string text = "çöğüşıabcçdefgğhıijklmnoöprsştuüvyzABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";
    string* allChar = Word::allCharacters(text);
    for (int i = 0; i < Word::size(text); i++){
        cout << allChar[i] << "\n";
    }
}
