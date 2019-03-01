//
// Created by Olcay Taner Yıldız on 5.01.2019.
//

#include <iostream>
#include "TxtDictionary.h"

int main(){
    TxtDictionary dictionary = TxtDictionary("../dictionary.txt", Comparator::TURKISH);
    int index = dictionary.getWordIndex("çığ");
    cout << index << "\n";
}