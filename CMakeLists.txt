cmake_minimum_required(VERSION 3.12)
project(Dictionary)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(math REQUIRED)

add_library(Dictionary src/Dictionary/Pos.h src/Dictionary/Word.cpp src/Dictionary/Word.h src/Language/Language.h src/Language/TurkishLanguage.h src/Dictionary/Trie/TrieNode.cpp src/Dictionary/Trie/TrieNode.h src/Dictionary/Trie/Trie.cpp src/Dictionary/Trie/Trie.h src/Syllibification/IrregularWordException.cpp src/Syllibification/IrregularWordException.h src/Syllibification/Syllable.cpp src/Syllibification/Syllable.h src/Syllibification/SyllableList.cpp src/Syllibification/SyllableList.h src/Dictionary/ExceptionalWord.cpp src/Dictionary/ExceptionalWord.h src/Dictionary/VectorizedWord.cpp src/Dictionary/VectorizedWord.h src/Dictionary/Dictionary.cpp src/Dictionary/Dictionary.h src/Dictionary/TxtWord.cpp src/Dictionary/TxtWord.h src/Dictionary/TxtDictionary.cpp src/Dictionary/TxtDictionary.h src/Dictionary/VectorizedDictionary.cpp src/Dictionary/VectorizedDictionary.h src/Language/EnglishLanguage.h)
target_link_libraries(Dictionary math::math)
add_executable(Test src/Dictionary/Pos.h src/Dictionary/Word.cpp src/Dictionary/Word.h src/Language/Language.h src/Language/TurkishLanguage.h src/Dictionary/Trie/TrieNode.cpp src/Dictionary/Trie/TrieNode.h src/Dictionary/Trie/Trie.cpp src/Dictionary/Trie/Trie.h src/Syllibification/IrregularWordException.cpp src/Syllibification/IrregularWordException.h src/Syllibification/Syllable.cpp src/Syllibification/Syllable.h src/Syllibification/SyllableList.cpp src/Syllibification/SyllableList.h src/Dictionary/ExceptionalWord.cpp src/Dictionary/ExceptionalWord.h src/Dictionary/VectorizedWord.cpp src/Dictionary/VectorizedWord.h src/Dictionary/Dictionary.cpp src/Dictionary/Dictionary.h src/Dictionary/TxtWord.cpp src/Dictionary/TxtWord.h src/Dictionary/TxtDictionary.cpp src/Dictionary/TxtDictionary.h src/Dictionary/VectorizedDictionary.cpp src/Dictionary/VectorizedDictionary.h Test/TrieTest.cpp Test/WordTest.cpp Test/TxtWordTest.cpp Test/DictionaryTest.cpp Test/TxtDictionaryTest.cpp src/Language/EnglishLanguage.h)
target_link_libraries(Test math::math)
