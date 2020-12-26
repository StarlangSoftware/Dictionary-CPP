cmake_minimum_required(VERSION 3.12)
project(Dictionary)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
link_directories(library)
add_library(Dictionary Dictionary/Pos.h Dictionary/Word.cpp Dictionary/Word.h Language/Language.h Language/TurkishLanguage.h Dictionary/Trie/TrieNode.cpp Dictionary/Trie/TrieNode.h Dictionary/Trie/Trie.cpp Dictionary/Trie/Trie.h Syllibification/IrregularWordException.cpp Syllibification/IrregularWordException.h Syllibification/Syllable.cpp Syllibification/Syllable.h Syllibification/SyllableList.cpp Syllibification/SyllableList.h Dictionary/ExceptionalWord.cpp Dictionary/ExceptionalWord.h Dictionary/VectorizedWord.cpp Dictionary/VectorizedWord.h Dictionary/Dictionary.cpp Dictionary/Dictionary.h Dictionary/TxtWord.cpp Dictionary/TxtWord.h Dictionary/TxtDictionary.cpp Dictionary/TxtDictionary.h Dictionary/VectorizedDictionary.cpp Dictionary/VectorizedDictionary.h)
target_link_libraries(Dictionary Math)
add_executable(Test Dictionary/Pos.h Dictionary/Word.cpp Dictionary/Word.h Language/Language.h Language/TurkishLanguage.h Dictionary/Trie/TrieNode.cpp Dictionary/Trie/TrieNode.h Dictionary/Trie/Trie.cpp Dictionary/Trie/Trie.h Syllibification/IrregularWordException.cpp Syllibification/IrregularWordException.h Syllibification/Syllable.cpp Syllibification/Syllable.h Syllibification/SyllableList.cpp Syllibification/SyllableList.h Dictionary/ExceptionalWord.cpp Dictionary/ExceptionalWord.h Dictionary/VectorizedWord.cpp Dictionary/VectorizedWord.h Dictionary/Dictionary.cpp Dictionary/Dictionary.h Dictionary/TxtWord.cpp Dictionary/TxtWord.h Dictionary/TxtDictionary.cpp Dictionary/TxtDictionary.h Dictionary/VectorizedDictionary.cpp Dictionary/VectorizedDictionary.h Test/TrieTest.cpp Test/WordTest.cpp Test/TxtWordTest.cpp Test/DictionaryTest.cpp Test/TxtDictionaryTest.cpp)
target_link_libraries(Test Math)
