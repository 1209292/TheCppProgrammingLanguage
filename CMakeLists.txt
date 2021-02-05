cmake_minimum_required(VERSION 3.5)

project(TheCppProgrammingLanguage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PART_ONE Part\ 1-\ A\ Tour\ of\ Cpp)
set(CHAPTER_TWO CH2\ The\ Basics)
set(CHAPTER_THREE CH3\ Abstraction\ Mechanisms)

add_subdirectory(${PART_ONE}/${CHAPTER_TWO})
add_subdirectory(${PART_ONE}/${CHAPTER_THREE})
