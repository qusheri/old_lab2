#include "test_sorting.h"
#include "sstream"
#include <map>
#include <string>
#include <fstream>
#include "set"

std::map<std::string, std::map<int, double>> performance_data;
std::set<int> sizes;

template<typename T>
std::string run_sort_test(ISort<T>& sorter, Sequence<T>* sequence, int (*cmp)(T, T), const std::string& test_name, int data_size) {
    auto start = std::chrono::high_resolution_clock::now();
    sorter.sort(sequence, cmp);
    auto end = std::chrono::high_resolution_clock::now();

    std::ostringstream result;
    std::chrono::duration<double> elapsed = end - start;

    performance_data[test_name][data_size] = elapsed.count();
    sizes.insert(data_size);
    result << test_name << " (Size " << data_size << "): ";
    if (is_sorted(sequence, cmp)) {
        result << "Passed";
    } else {
        result << "Failed";
    }
    result << " (Time: " << elapsed.count() << " seconds)\n";

    return result.str();
}

int compare(int a, int b) {
    return a - b;
}

template<typename T>
bool is_sorted(Sequence<T>* sequence, int (*cmp)(T, T)) {
    for (int i = 1; i < sequence->GetLength(); i++) {
        if (cmp((*sequence)[i - 1], (*sequence)[i]) > 0) {
            return false;
        }
    }
    return true;
}

ArraySequence<int>* generate_random_array_sequence(int size) {
    ArraySequence<int>* sequence = new ArraySequence<int>();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10000);

    for (int i = 0; i < size; i++) {
        sequence->Append(dis(gen));
    }
    return sequence;
}

ListSequence<int>* generate_random_list_sequence(int size) {
    ListSequence<int>* sequence = new ListSequence<int>();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10000);

    for (int i = 0; i < size; i++) {
        sequence->Append(dis(gen));
    }
    return sequence;
}

ArraySequence<int>* generate_sorted_array_sequence(int size) {
    ArraySequence<int>* sequence = new ArraySequence<int>();
    for (int i = 0; i < size; i++) {
        sequence->Append(i);
    }
    return sequence;
}

ListSequence<int>* generate_sorted_list_sequence(int size) {
    ListSequence<int>* sequence = new ListSequence<int>();
    for (int i = 0; i < size; i++) {
        sequence->Append(i);
    }
    return sequence;
}

ArraySequence<int>* generate_reverse_sorted_array_sequence(int size) {
    ArraySequence<int>* sequence = new ArraySequence<int>();
    for (int i = size; i > 0; i--) {
        sequence->Append(i);
    }
    return sequence;
}

ListSequence<int>* generate_reverse_sorted_list_sequence(int size) {
    ListSequence<int>* sequence = new ListSequence<int>();
    for (int i = size; i > 0; i--) {
        sequence->Append(i);
    }
    return sequence;
}

std::string test_sorting_algorithms_on_array_and_list_sequences(
    const std::vector<int>& test_sizes,
    bool arr_seq,
    bool list_seq
) {
    int (*cmp)(int, int) = compare;
    std::ostringstream result;

    BubbleSort<int> bubble_sort;
    ShakerSort<int> shaker_sort;
    MergeSort<int> merge_sort;
    QuickSort<int> quick_sort;

    for (const int size : test_sizes) {
        result << "Testing size = " << size << "\n\n";

        if (arr_seq) {
            result << "Testing with ArraySequence:\n";
            ArraySequence<int>* random_seq = generate_random_array_sequence(size);

            // result << run_sort_test(bubble_sort, random_seq, cmp, "BubbleSort (Random) for ArrSeq", size);
            // result << run_sort_test(shaker_sort, random_seq, cmp, "ShakerSort (Random) for ArrSeq", size);
            result << run_sort_test(merge_sort, random_seq, cmp, "MergeSort (Random) for ArrSeq", size);
            result << run_sort_test(quick_sort, random_seq, cmp, "QuickSort (Random) for ArrSeq", size);

            ArraySequence<int>* sorted_seq = generate_sorted_array_sequence(size);

            // result << run_sort_test(bubble_sort, sorted_seq, cmp, "BubbleSort (Sorted) for ArrSeq", size);
            // result << run_sort_test(shaker_sort, sorted_seq, cmp, "ShakerSort (Sorted) for ArrSeq", size);
            result << run_sort_test(merge_sort, sorted_seq, cmp, "MergeSort (Sorted) for ArrSeq", size);
            result << run_sort_test(quick_sort, sorted_seq, cmp, "QuickSort (Sorted) for ArrSeq", size);

            ArraySequence<int>* rev_sorted_seq = generate_reverse_sorted_array_sequence(size);

            // result << run_sort_test(bubble_sort, rev_sorted_seq, cmp, "BubbleSort (AntiSorted) for ArrSeq", size);
            // result << run_sort_test(shaker_sort, rev_sorted_seq, cmp, "ShakerSort (AntiSorted) for ArrSeq", size);
            result << run_sort_test(merge_sort, rev_sorted_seq, cmp, "MergeSort (AntiSorted) for ArrSeq", size);
            result << run_sort_test(quick_sort, rev_sorted_seq, cmp, "QuickSort (AntiSorted) for ArrSeq", size);

            delete random_seq;
            delete sorted_seq;
            delete rev_sorted_seq;
        }

        if (list_seq) {
            result << "Testing with ListSequence:\n";
            ListSequence<int>* random_seq = generate_random_list_sequence(size);

            // result << run_sort_test(bubble_sort, random_seq, cmp, "BubbleSort (Random) for ListSeq", size);
            // result << run_sort_test(shaker_sort, random_seq, cmp, "ShakerSort (Random) for ListSeq", size);
            result << run_sort_test(merge_sort, random_seq, cmp, "MergeSort (Random) for ListSeq", size);
            result << run_sort_test(quick_sort, random_seq, cmp, "QuickSort (Random) for ListSeq", size);

            ListSequence<int>* sorted_seq = generate_sorted_list_sequence(size);

            // result << run_sort_test(bubble_sort, sorted_seq, cmp, "BubbleSort (Sorted) for ListSeq", size);
            // result << run_sort_test(shaker_sort, sorted_seq, cmp, "ShakerSort (Sorted) for ListSeq", size);
            result << run_sort_test(merge_sort, sorted_seq, cmp, "MergeSort (Sorted) for ListSeq", size);
            result << run_sort_test(quick_sort, sorted_seq, cmp, "QuickSort (Sorted) for ListSeq", size);

            ListSequence<int>* rev_sorted_seq = generate_reverse_sorted_list_sequence(size);

            // result << run_sort_test(bubble_sort, rev_sorted_seq, cmp, "BubbleSort (AntiSorted) for ListSeq", size);
            // result << run_sort_test(shaker_sort, rev_sorted_seq, cmp, "ShakerSort (AntiSorted) for ListSeq", size);
            result << run_sort_test(merge_sort, rev_sorted_seq, cmp, "MergeSort (AntiSorted) for ListSeq", size);
            result << run_sort_test(quick_sort, rev_sorted_seq, cmp, "QuickSort (AntiSorted) for ListSeq", size);

            delete random_seq;
            delete sorted_seq;
            delete rev_sorted_seq;
        }
    }

    return result.str();
}

void save_performance_data_to_csv_and_xl(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    if (!performance_data.empty()) {
        file << "Test Name";
        for (const auto& size : sizes) {
            file << ',' << size;
        }
        file << '\n';

        for (auto [test_name, timings] : performance_data) {
            file << test_name;
            for(int size: sizes) {
                if(timings.count(size)) {
                    file << ',' << timings[size];
                } else {
                    file << ",NA";
                }
            }
            file << '\n';
        }

        file.close();
    } else {
        std::cerr << "Performance data is empty. No CSV generated.\n";
    }

    int result = std::system("python ../tests/csv_to_xl.py");
    if (result == 0) {
        std::cout << "CSV успешно конвертирован в Excel." << std::endl;
    } else {
        std::cerr << "Ошибка при выполнении скрипта." << std::endl;
    }
}
