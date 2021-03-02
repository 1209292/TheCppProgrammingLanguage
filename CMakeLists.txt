cmake_minimum_required(VERSION 3.5)

project(TheCppProgrammingLanguage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PART_ONE Part_1_A_Tour_of_Cpp)
set(CHAPTER_TWO CH2_The_Basics)
set(CHAPTER_THREE CH3_Abstraction_Mechanisms)
set(CHAPTER_FOUR CH4_Containers_and_Algorithms)

add_subdirectory(${PART_ONE}/${CHAPTER_TWO})
add_subdirectory(${PART_ONE}/${CHAPTER_THREE})
add_subdirectory(${PART_ONE}/${CHAPTER_FOUR})
