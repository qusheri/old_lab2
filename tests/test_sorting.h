#pragma once
#include "../structs/ArraySequence.h"
#include "../structs/ListSequence.h"
#include <iostream>
#include <chrono>
#include <random>
#include "string"
#include "../structs/ISort.h"
#include "../structs/sorting_algorithms.h"
#include <vector>

template<typename T>
std::string run_sort_test(ISort<T>& sorter, Sequence<T>* sequence, int (*cmp)(T, T), const std::string& test_name, int data_size);

int compare(int a, int b);

template<typename T>
bool is_sorted(Sequence<T>* sequence, int (*cmp)(T, T));

ArraySequence<int>* generate_random_array_sequence(int size);

ListSequence<int>* generate_random_list_sequence(int size);

ArraySequence<int>* generate_sorted_array_sequence(int size);

ListSequence<int>* generate_sorted_list_sequence(int size);

ArraySequence<int>* generate_reverse_sorted_array_sequence(int size);

ListSequence<int>* generate_reverse_sorted_list_sequence(int size);

std::string test_sorting_algorithms_on_array_and_list_sequences(const std::vector<int>& test_sizes, bool arr_seq, bool list_seq);

void save_performance_data_to_csv_and_xl(const std::string& filename);