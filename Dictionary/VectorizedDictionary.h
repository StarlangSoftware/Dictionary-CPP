//
// Created by olcay on 20.02.2019.
//

#ifndef DICTIONARY_VECTORIZEDDICTIONARY_H
#define DICTIONARY_VECTORIZEDDICTIONARY_H


#include "Dictionary.h"

class VectorizedDictionary : public Dictionary {
public:
    explicit VectorizedDictionary(Comparator comparator);

};


#endif //DICTIONARY_VECTORIZEDDICTIONARY_H
