#pragma once
#include "ISort.h"
template<typename T>
class BubbleSort : public ISort<T>{
public:
    Sequence<T>* sort(Sequence<T>* container, int (*cmp)(T,T)) {
        for (int j = 1; j < container->GetLength(); j++) {
            bool isSorted = true;
            for (int i = 0; i < container->GetLength() - j; i++) {
                if (cmp((*container)[i], (*container)[i + 1]) > 0) {
                    int tmp = (*container)[i];
                    (*container)[i] = (*container)[i + 1];
                    (*container)[i + 1] = tmp;
                    isSorted = false;
                }
            }
            if (isSorted) {
                break;
            }
        }
        return container;
    }
};

template<typename T>
class ShakerSort : public ISort<T> {
public:
    Sequence<T>* sort(Sequence<T>* container, int (*cmp)(T,T)) {
        bool swapped = true;
        int start = 0;
        int end = container->GetLength() - 1;

        while (swapped) {
            swapped = false;
            for (int i = start; i < end; ++i) {
                if (cmp((*container)[i], (*container)[i + 1]) > 0) {
                    T temp = (*container)[i];
                    (*container)[i] = (*container)[i + 1];
                    (*container)[i + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
            swapped = false;
            --end;
            for (int i = end - 1; i >= start; --i) {
                if (cmp((*container)[i], (*container)[i + 1]) > 0) {
                    T temp = (*container)[i];
                    (*container)[i] = (*container)[i + 1];
                    (*container)[i + 1] = temp;
                    swapped = true;
                }
            }
            ++start;
        }
        return container;
    }
};

template<typename T>
class MergeSort : public ISort<T> {
public:
    Sequence<T>* sort(Sequence<T>* container, int (*cmp)(T,T)) {
        merge_sort(container, 0, container->GetLength() - 1, cmp);
        return container;
    }
private:
    void merge_sort(Sequence<T>* container, int left, int right, int (*cmp)(T,T)) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            merge_sort(container, left, mid, cmp);
            merge_sort(container, mid + 1, right, cmp);
            merging(container, left, mid, right, cmp);
        }
    }
    void merging(Sequence<T>* container, int left, int mid, int right, int (*cmp)(T, T)) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        Sequence<T>* LeftPart = container->GetSubsequence(left, mid);
        Sequence<T>* RightPart = container->GetSubsequence(mid + 1, right);
        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (cmp(LeftPart->Get(i), RightPart->Get(j)) <= 0) {
                (*container)[k] = LeftPart->Get(i);
                i++;
            } else {
                (*container)[k] = RightPart->Get(j);
                j++;
            }
            k++;
        }
        while (i < n1) {
            (*container)[k] = LeftPart->Get(i);
            i++;
            k++;
        }
        while (j < n2) {
            (*container)[k] = RightPart->Get(j);
            j++;
            k++;
        }
        delete LeftPart;
        delete RightPart;
    }
};


template<typename T>
class QuickSort : public ISort<T> {
private:
    void quick_sort(Sequence<T>* container, int (*cmp)(T,T)) {
        T pivot = (*container)[container->GetLength() / 2];
        int size_left = 0, size_right = 0;
        for (int i = 0; i < container->GetLength(); ++i) {
            if (i != container->GetLength() / 2) {
                if (cmp((*container)[i], pivot) <= 0) {
                    ++size_left;
                } else {
                    ++size_right;
                }
            }
        }
        Sequence<T> *left = container->GetSubsequence(0, size_left - 1);
        Sequence<T> *right = container->GetSubsequence(0, size_right - 1);

        size_right = 0, size_left = 0;
        for (int i = 0; i < container->GetLength(); ++i) {
            if (i != container->GetLength() / 2) {
                if (cmp((*container)[i], pivot) <= 0) {
                    (*left)[size_left++] = (*container)[i];
                } else {
                    (*right)[size_right++] = (*container)[i];
                }
            }
        }
        if (left->GetLength() > 1) quick_sort(left, cmp);
        if (right->GetLength() > 1) quick_sort(right, cmp);
        left->Append(pivot);
        for(int i = 0; i < left->GetLength(); ++i){
            (*container)[i] = (*left)[i];
        }
        for(int i = 0; i < right->GetLength(); ++i){
            (*container)[i + left->GetLength()] = (*right)[i];
        }
    }
public:
    Sequence<T>* sort(Sequence<T>* container, int (*cmp)(T,T)) {
        quick_sort(container, cmp);
        return container;
    }
};
