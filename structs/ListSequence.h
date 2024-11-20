#pragma once
#include "LinkedList.h"
#include "Sequence.h"

template<typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> list_;
public:
    ListSequence(T* items, int count) : list_(items, count) {}

    ListSequence() : list_() {}
    ListSequence(const ListSequence<T>& other) : list_(other.list_) {}
    T GetFirst() override {
        return list_.GetFirst();
    }

    T GetLast() override {
        return list_.GetLast();
    }

    T Get(int index) override {
        return list_.Get(index);
    }
    void pop_front(){
        list_.pop_front();
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        ListSequence<T>* subsequence = new ListSequence<T>();
        LinkedList<T>* sublist = list_.GetSubList(startIndex, endIndex);
        for (int i = 0; i < sublist->GetLength(); ++i) {
            subsequence->Append((*sublist)[i]);
        }
        delete sublist;
        return subsequence;
    }

    int GetLength() override {
        return list_.GetLength();
    }

    Sequence<T>* Append(T item) override {
        list_.Append(item);
        return this;
    }

    Sequence<T>* Prepend(T item) override {
        list_.Prepend(item);
        return this;
    }

    Sequence<T>* InsertAt(T item, int index) override {
        list_.InsertAt(item, index);
        return this;
    }

    Sequence<T>* Concat(Sequence<T>* otherList) override {
        ListSequence<T>* concatenatedSequence = new ListSequence<T>();
        LinkedList<T>* otherListPtr = dynamic_cast<LinkedList<T>*>(otherList);
        if (otherListPtr) {
            LinkedList<T>* combinedList = list_.Concat(otherListPtr);
            for (int i = 0; i < combinedList->GetLength(); ++i) {
                concatenatedSequence->Append((*combinedList)[i]);
            }
            delete combinedList;
        }
        return concatenatedSequence;
    }
    void Clear() override{
        list_.~LinkedList();
    }
    T& operator[](const size_t i) override {
        return list_[i];
    }
    const T& operator[](const size_t i) const override {
        return list_[i];
    }
};