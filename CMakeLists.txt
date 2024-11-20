cmake_minimum_required(VERSION 3.27)
project(sorting_algorithms)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)
add_executable(sorting_algorithms
        structs/main.cpp
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
)

target_link_libraries(sorting_algorithms Qt6::Widgets Qt6::Charts)