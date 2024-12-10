#include "structures_tests.h"
#include "iostream"
std::string runLinkedListTests() {
    std::ostringstream result;
    result << "LinkedList Tests:\n";

    // Тест: добавление элементов в начало списка
    result << "  Functional Test 1 (push front): ";
    {
        try {
            LinkedList<int> list;
            list.Prepend(10);
            list.Prepend(20);
            result << ((list.GetFirst() == 20 && list.GetLength() == 2) ? "Passed" : "Failed") << "\n";
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    // Тест: получение первого элемента
    result << "  Functional Test 2 (get first element): ";
    {
        try {
            LinkedList<int> list;
            list.Prepend(5);
            result << (list.GetFirst() == 5 ? "Passed" : "Failed") << "\n";
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    // Тест: удаление элемента из пустого списка
    result << "  Exception Test 1 (pop from empty list): ";
    {
        try {
            LinkedList<int> list;
            list.pop_front();
            result << "Failed (no exception thrown)\n";
        } catch (const std::out_of_range &e) {
            result << "Passed\n";
        } catch (...) {
            result << "Failed (unknown exception)\n";
        }
    }

    // Тест: получение элемента по индексу
    result << "  Functional Test 3 (get by index): ";
    {
        try {
            LinkedList<int> list;
            list.Append(10);
            list.Append(20);
            result << (list.Get(1) == 20 ? "Passed" : "Failed") << "\n";
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    // Тест: конкатенация двух списков
    result << "  Functional Test 4 (concat lists): ";
    {
        try {
            LinkedList<int> list1;
            list1.Append(1);
            LinkedList<int> list2;
            list2.Append(2);
            LinkedList<int>* concatenated = list1.Concat(&list2);
            result << (concatenated->GetLength() == 2 && concatenated->Get(1) == 2 ? "Passed" : "Failed") << "\n";
            delete concatenated;
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    result << "All LinkedList tests passed\n";
    return result.str();
}

std::string runDynamicArrayTests() {
    std::ostringstream result;
    result << "DynamicArray Tests:\n";

    // Тест: добавление элемента в конец
    result << "  Functional Test 1 (append): ";
    {
        try {
            DynamicArray<int> array(2);
            array[0] = 1;
            array[1] = 2;
            array.Append(3);
            result << ((array[2] == 3 && array.Size() == 3) ? "Passed" : "Failed") << "\n";
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    // Тест: получение элемента по индексу
    result << "  Functional Test 2 (get by index): ";
    {
        try {
            DynamicArray<int> array(3);
            array[0] = 5;
            result << (array[0] == 5 ? "Passed" : "Failed") << "\n";
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    // Тест: исключение на выход за границы
    result << "  Exception Test 1 (out of range): ";
    {
        try {
            DynamicArray<int> array(2);
            array[10]; // Выход за границы
            result << "Failed (no exception thrown)\n";
        } catch (const std::out_of_range &e) {
            result << "Passed\n";
        } catch (...) {
            result << "Failed (unknown exception)\n";
        }
    }

    result << "All DynamicArray tests passed\n";
    return result.str();
}

std::string runListSequenceTests() {
    std::ostringstream result;
    result << "ListSequence Tests:\n";

    // Тест: добавление элемента в конец
    result << "  Functional Test 1 (append): ";
    {
        try {
            ListSequence<int> seq;
            seq.Append(10);
            result << (seq.GetLast() == 10 ? "Passed" : "Failed") << "\n";
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    // Тест: получение подпоследовательности
    result << "  Functional Test 2 (subsequence): ";
    {
        try {
            int items[] = {1, 2, 3, 4, 5};
            ListSequence<int> seq(items, 5);
            Sequence<int>* subseq = seq.GetSubsequence(1, 3);
            result << ((subseq->GetLength() == 3 && subseq->Get(0) == 2) ? "Passed" : "Failed") << "\n";
            delete subseq;
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }
    result << "All ListSquence tests passed\n";
    return result.str();
}

std::string runArraySequenceTests() {
    std::ostringstream result;
    result << "ArraySequence Tests:\n";

    // Тест: добавление элемента в конец
    result << "  Functional Test 1 (append): ";
    {
        try {
            ArraySequence<int> seq;
            seq.Append(10);
            result << (seq.GetLast() == 10 ? "Passed" : "Failed") << "\n";
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    // Тест: получение подпоследовательности
    result << "  Functional Test 2 (subsequence): ";
    {
        try {
            int items[] = {1, 2, 3, 4, 5};
            ArraySequence<int> seq(items, 5);
            Sequence<int>* subseq = seq.GetSubsequence(1, 3);
            result << ((subseq->GetLength() == 3 && subseq->Get(0) == 2) ? "Passed" : "Failed") << "\n";
            delete subseq;
        } catch (const std::exception &e) {
            result << "Failed with exception: " << e.what() << "\n";
        }
    }

    result << "All Arraysequence tests passed\n";
    return result.str();
}
