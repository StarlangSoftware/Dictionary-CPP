//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#ifndef DICTIONARY_IRREGULARWORDEXCEPTION_H
#define DICTIONARY_IRREGULARWORDEXCEPTION_H
#include <exception>
using namespace std;

class IrregularWordException : public exception {
public:
    const char* what() const noexcept override;
};


#endif //DICTIONARY_IRREGULARWORDEXCEPTION_H
