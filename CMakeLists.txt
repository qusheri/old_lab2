cmake_minimum_required(VERSION 3.27)
project(sorting_algorithms)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(sorting_algorithms
        structs/smart_ptrs.h
        structs/Sequence.h
        structs/ISort.h
        structs/ArraySequence.h
        structs/DynamicArray.h
        structs/LinkedList.h
        structs/ListSequence.h
        tests/structures_tests.cpp
        tests/structures_tests.h
        structs/sorting_algorithms.h
        tests/test_sorting.cpp
        tests/test_sorting.h
        main.cpp
#        tests/csv_to_excel.cpp
#        tests/csv_to_excel.h
)