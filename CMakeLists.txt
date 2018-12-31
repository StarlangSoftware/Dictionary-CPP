cmake_minimum_required(VERSION 3.12)
project(Dictionary)

set(CMAKE_CXX_STANDARD 20)

add_library(Dictionary Pos.h Word.cpp Word.h Language.h TurkishLanguage.h)
