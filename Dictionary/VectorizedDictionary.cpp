//
// Created by olcay on 20.02.2019.
//

#include "VectorizedDictionary.h"

/**
 * A constructor of {@link VectorizedDictionary} class which takes a {@link WordComparator} as an input and calls its
 * super class {@link Dictionary} with {@link WordComparator} input.
 *
 * @param comparator {@link WordComparator} type input.
 */
VectorizedDictionary::VectorizedDictionary(Comparator comparator) : Dictionary(comparator) {
}
