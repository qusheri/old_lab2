#include "test_sorting.h"

template<typename T>
void run_sort_test(ISort<T>& sorter, Sequence<T>* sequence, int (*cmp)(T, T), const std::string& test_name) {
    auto start = std::chrono::high_resolution_clock::now();
    sorter.sort(sequence, cmp);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << test_name << ": ";
    if (is_sorted(sequence, cmp)) {
        std::cout << "Passed";
    } else {
        std::cout << "Failed";
    }
    std::cout << " (Time: " << elapsed.count() << " seconds)\n";
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

// Функции для генерации данных внутри контейнеров
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

void test_sorting_algorithms_on_array_and_list_sequences() {
    const int test_size = 10000; // Large test size
    int (*cmp)(int, int) = compare;

    // Create sorters
    BubbleSort<int> bubble_sort;
    ShakerSort<int> shaker_sort;
    MergeSort<int> merge_sort;
    QuickSort<int> quick_sort;

    // Test with ArraySequence
    std::cout << "Testing with ArraySequence:\n";
    {
        ArraySequence<int>* random_seq = generate_random_array_sequence(test_size);
        run_sort_test(bubble_sort, random_seq, cmp, "BubbleSort (Random)");
        run_sort_test(shaker_sort, random_seq, cmp, "ShakerSort (Random)");
        run_sort_test(merge_sort, random_seq, cmp, "MergeSort (Random)");
        run_sort_test(quick_sort, random_seq, cmp, "QuickSort (Random)");
        delete random_seq;

        ArraySequence<int>* sorted_seq = generate_sorted_array_sequence(test_size);
        run_sort_test(bubble_sort, sorted_seq, cmp, "BubbleSort (Sorted)");
        run_sort_test(shaker_sort, sorted_seq, cmp, "ShakerSort (Sorted)");
        run_sort_test(merge_sort, sorted_seq, cmp, "MergeSort (Sorted)");
        run_sort_test(quick_sort, sorted_seq, cmp, "QuickSort (Sorted)");
        delete sorted_seq;

        ArraySequence<int>* reverse_sorted_seq = generate_reverse_sorted_array_sequence(test_size);
        run_sort_test(bubble_sort, reverse_sorted_seq, cmp, "BubbleSort (Reverse Sorted)");
        run_sort_test(shaker_sort, reverse_sorted_seq, cmp, "ShakerSort (Reverse Sorted)");
        run_sort_test(merge_sort, reverse_sorted_seq, cmp, "MergeSort (Reverse Sorted)");
        run_sort_test(quick_sort, reverse_sorted_seq, cmp, "QuickSort (Reverse Sorted)");
        delete reverse_sorted_seq;
    }

    // Test with ListSequence
    std::cout << "Testing with ListSequence:\n";
    {
        ListSequence<int>* random_seq = generate_random_list_sequence(test_size);
        run_sort_test(bubble_sort, random_seq, cmp, "BubbleSort (Random)");
        run_sort_test(shaker_sort, random_seq, cmp, "ShakerSort (Random)");
        run_sort_test(merge_sort, random_seq, cmp, "MergeSort (Random)");
        run_sort_test(quick_sort, random_seq, cmp, "QuickSort (Random)");
        delete random_seq;

        ListSequence<int>* sorted_seq = generate_sorted_list_sequence(test_size);
        run_sort_test(bubble_sort, sorted_seq, cmp, "BubbleSort (Sorted)");
        run_sort_test(shaker_sort, sorted_seq, cmp, "ShakerSort (Sorted)");
        run_sort_test(merge_sort, sorted_seq, cmp, "MergeSort (Sorted)");
        run_sort_test(quick_sort, sorted_seq, cmp, "QuickSort (Sorted)");
        delete sorted_seq;

        ListSequence<int>* reverse_sorted_seq = generate_reverse_sorted_list_sequence(test_size);
        run_sort_test(bubble_sort, reverse_sorted_seq, cmp, "BubbleSort (Reverse Sorted)");
        run_sort_test(shaker_sort, reverse_sorted_seq, cmp, "ShakerSort (Reverse Sorted)");
        run_sort_test(merge_sort, reverse_sorted_seq, cmp, "MergeSort (Reverse Sorted)");
        run_sort_test(quick_sort, reverse_sorted_seq, cmp, "QuickSort (Reverse Sorted)");
        delete reverse_sorted_seq;
    }
}
