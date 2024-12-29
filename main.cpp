#include <iostream>
#include <string>
#include "structs/sorting_algorithms.h"
#include "structs/ArraySequence.h"
#include "structs/ListSequence.h"
#include "tests/test_sorting.h"
#include "tests/structures_tests.h"

// Предполагается, что следующие функции уже определены:
ArraySequence<int>* generate_random_array_sequence(int size);
ListSequence<int>* generate_random_list_sequence(int size);
void save_performance_data_to_csv_and_xl(const std::string& filename);

void show_menu() {
    std::cout << "\nChoose an action:\n";
    std::cout << "0. Func Tests\n";
    std::cout << "1. Run a test\n";
    std::cout << "2. Save results to CSV and Excel\n";
    std::cout << "3. Generate graphs from results\n";
    std::cout << "4. RUN ALL TESTS\n";
    std::cout << "5. Exit\n";
    std::cout << "Your choice: ";
}

void choose_and_run_test() {
    std::cout << "\nSelect the type of sequence:\n";
    std::cout << "1. ArraySequence\n";
    std::cout << "2. ListSequence\n";
    int seq_choice;
    std::cin >> seq_choice;

    if (seq_choice != 1 && seq_choice != 2) {
        std::cerr << "Invalid sequence type selected.\n";
        return;
    }

    std::cout << "Choose the sorting algorithm:\n";
    std::cout << "1. BubbleSort\n";
    std::cout << "2. MergeSort\n";
    std::cout << "3. QuickSort\n";
    std::cout << "4. ShakerSort\n";
    int sort_choice;
    std::cin >> sort_choice;

    ISort<int>* sort_algorithm = nullptr;
    std::string sort_name;

    switch (sort_choice) {
        case 1:
            sort_algorithm = new BubbleSort<int>();
            sort_name = "BubbleSort";
            break;
        case 2:
            sort_algorithm = new MergeSort<int>();
            sort_name = "MergeSort";
            break;
        case 3:
            sort_algorithm = new QuickSort<int>();
            sort_name = "QuickSort";
            break;
        case 4:
            sort_algorithm = new ShakerSort<int>();
            sort_name = "ShakerSort";
            break;
        default:
            std::cerr << "Invalid sorting algorithm selected.\n";
            return;
    }

    std::cout << "Enter the size of the sequence: ";
    int size;
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "The sequence size must be positive.\n";
        delete sort_algorithm;
        return;
    }

    int (*cmp)(int, int) = [](int a, int b) { return a - b; };

    if (seq_choice == 1) { // ArraySequence
        ArraySequence<int>* random_seq = generate_random_array_sequence(size);
        std::cout << run_sort_test(*sort_algorithm, random_seq, cmp, sort_name + " for ArrSeq", size) << std::endl;
        delete random_seq;
    } else if (seq_choice == 2) { // ListSequence
        ListSequence<int>* random_seq = generate_random_list_sequence(size);
        std::cout << run_sort_test(*sort_algorithm, random_seq, cmp, sort_name + " for ListSeq", size) << std::endl;
        delete random_seq;
    }

    delete sort_algorithm;
}

void build_graphs(const std::string& csv_file, const std::string& python_script) {
    std::string command = "python3 " + python_script + " " + csv_file;
    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "Graphs successfully generated.\n";
    } else {
        std::cerr << "Error executing the Python script.\n";
    }
}

int main() {
    const std::string csv_file = "../tests/performance_data.csv";
    const std::string python_script = "../tests/display.py";

    while (true) {
        show_menu();
        int choice;
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the program.\n";
            break;
        }

        std::vector<int> test_sizes;
        for (int i = 1; i <= 1'000'001; i += 100'000) {
            test_sizes.push_back(i);
        }
        switch (choice) {
            case 0:
                std::cout << runLinkedListTests();
                std::cout << runDynamicArrayTests();
                std::cout << runListSequenceTests();
                std::cout << runArraySequenceTests();
                break;
            case 1:
                choose_and_run_test();
                break;
            case 2:
                save_performance_data_to_csv_and_xl(csv_file);
                std::cout << "Results saved to CSV and Excel.\n";
                break;
            case 3:
                build_graphs(csv_file, python_script);
                break;
            case 4:
                test_sorting_algorithms_on_array_and_list_sequences(test_sizes, true, false);
                break;
            default:
                std::cerr << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
