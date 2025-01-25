cmake_minimum_required(VERSION 3.12)
project(Dictionary)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(math REQUIRED)
find_package(util REQUIRED)

add_library(Dictionary Dictionary/Pos.h Dictionary/Word.cpp Dictionary/Word.h Language/Language.h Language/TurkishLanguage.h Dictionary/Trie/TrieNode.cpp Dictionary/Trie/TrieNode.h Dictionary/Trie/Trie.cpp Dictionary/Trie/Trie.h Syllibification/IrregularWordException.cpp Syllibification/IrregularWordException.h Syllibification/Syllable.cpp Syllibification/Syllable.h Syllibification/SyllableList.cpp Syllibification/SyllableList.h Dictionary/ExceptionalWord.cpp Dictionary/ExceptionalWord.h Dictionary/VectorizedWord.cpp Dictionary/VectorizedWord.h Dictionary/Dictionary.cpp Dictionary/Dictionary.h Dictionary/TxtWord.cpp Dictionary/TxtWord.h Dictionary/TxtDictionary.cpp Dictionary/TxtDictionary.h Dictionary/VectorizedDictionary.cpp Dictionary/VectorizedDictionary.h Language/EnglishLanguage.h)
target_link_libraries(Dictionary math::math util::util)
