#include "test_sorting.h"
#include "sstream"
#include <map>
#include <string>
#include <fstream>

std::map<std::string, std::vector<std::pair<int, double>>> performance_data;

template<typename T>
std::string run_sort_test(ISort<T>& sorter, Sequence<T>* sequence, int (*cmp)(T, T), const std::string& test_name, int data_size) {
    auto start = std::chrono::high_resolution_clock::now();
    sorter.sort(sequence, cmp);
    auto end = std::chrono::high_resolution_clock::now();

    std::ostringstream result;
    std::chrono::duration<double> elapsed = end - start;

    performance_data[test_name].push_back({data_size, elapsed.count()});

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

    for (int size : test_sizes) {
        result << "Testing size = " << size << "\n\n";

        if (arr_seq) {
            result << "Testing with ArraySequence:\n";
            ArraySequence<int>* random_seq = generate_random_array_sequence(size);

            result << run_sort_test(bubble_sort, random_seq, cmp, "BubbleSort (Random)", size);
            result << run_sort_test(shaker_sort, random_seq, cmp, "ShakerSort (Random)", size);
            result << run_sort_test(merge_sort, random_seq, cmp, "MergeSort (Random)", size);
            result << run_sort_test(quick_sort, random_seq, cmp, "QuickSort (Random)", size);

            delete random_seq;
        }

        if (list_seq) {
            result << "Testing with ListSequence:\n";
            ListSequence<int>* random_seq = generate_random_list_sequence(size);

            result << run_sort_test(bubble_sort, random_seq, cmp, "BubbleSort (Random)", size);
            result << run_sort_test(shaker_sort, random_seq, cmp, "ShakerSort (Random)", size);
            result << run_sort_test(merge_sort, random_seq, cmp, "MergeSort (Random)", size);
            result << run_sort_test(quick_sort, random_seq, cmp, "QuickSort (Random)", size);

            delete random_seq;
        }
    }

    try {
        save_performance_data_to_csv_and_xl("../tests/performance_data.csv");
        result << "Performance data saved to performance_data.csv\n";
    } catch (const std::exception& ex) {
        result << "Error saving performance data: " << ex.what() << "\n";
    }

    return result.str();
}

void save_performance_data_to_csv_and_xl(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    if (!performance_data.empty()) {
        file << "Test Size";

        auto test_sizes = performance_data.begin()->second;
        for(auto test : test_sizes) {
            file << ',' << test.first;
        }
        file << '\n';

        // Записываем данные
        for (const auto& [test_name, timings] : performance_data) {
            file << test_name;
            for (auto timing : timings) {
                file << "," << timing.second;
            }
            file << "\n";
        }
        file.close();
    }
    int result = std::system("python ../tests/csv_to_xl.py");
    result += std::system("python ../tests/display.py");
    if (result == 0) {
        std::cout << "CSV успешно конвертирован в Excel." << std::endl;
    } else {
        std::cerr << "Ошибка при выполнении скрипта." << std::endl;
    }
}
