cmake_minimum_required(VERSION 3.12)
project(Dictionary)

set(CMAKE_CXX_STANDARD 20)

include_directories(Language include)
link_directories(library)
add_library(Dictionary Dictionary/Pos.h Dictionary/Word.cpp Dictionary/Word.h Language/Language.h Language/TurkishLanguage.h Dictionary/Trie/TrieNode.cpp Dictionary/Trie/TrieNode.h Dictionary/Trie/Trie.cpp Dictionary/Trie/Trie.h Syllibification/IrregularWordException.cpp Syllibification/IrregularWordException.h Syllibification/Syllable.cpp Syllibification/Syllable.h Syllibification/SyllableList.cpp Syllibification/SyllableList.h Dictionary/ExceptionalWord.cpp Dictionary/ExceptionalWord.h VectorizedWord.cpp VectorizedWord.h Dictionary/Compare.h Dictionary/Dictionary.cpp Dictionary/Dictionary.h Dictionary/TxtWord.cpp Dictionary/TxtWord.h)
