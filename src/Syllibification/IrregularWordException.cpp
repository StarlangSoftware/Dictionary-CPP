//
// Created by Olcay Taner Yıldız on 1.01.2019.
//

#include "IrregularWordException.h"

const char *IrregularWordException::what() const noexcept {
    return "Irregular word for syllibification";
}
