//
// Created by Olcay Taner Yıldız on 5.01.2019.
//

#include <iostream>
#include "TxtDictionary.h"

int main(){
    TxtDictionary dictionary = TxtDictionary("../dictionary.txt", Comparator::ENGLISH);
    int index = dictionary.getWordIndex("a");
    cout << index << "\n";
    string text = "abc;çdefg;ğhı;ijklmn;oöpqr;s;ştu;üvwx;yzABC;Ç;DEFG;ĞHI;İ;JKLMNO;ÖPQ;RSŞTUÜV;WXYZ";
    vector<string> items = Word::split(text, ";");
    for (string item : items){
        cout << item << "\n";
    }
}