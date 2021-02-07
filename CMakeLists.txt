cmake_minimum_required(VERSION 3.5)

project(TheCppProgrammingLanguage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    set(PART_ONE Part_1_A_Tour_of_Cpp)
    set(CHAPTER_TWO CH2_The_Basics)
    set(CHAPTER_THREE CH3_Abstraction_Mechanisms)
endif (WIN32)

if(UNIX)
    set(PART_ONE Part\ 1-\ A\ Tour\ of\ Cpp)
    set(CHAPTER_TWO CH2\ The\ Basics)
    set(CHAPTER_THREE CH3\ Abstraction\ Mechanisms)
endif (UNIX)

add_subdirectory(${PART_ONE}/${CHAPTER_TWO})
add_subdirectory(${PART_ONE}/${CHAPTER_THREE})
