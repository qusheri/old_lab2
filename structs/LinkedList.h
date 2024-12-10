#pragma once
#include "smart_ptrs.h"
#include "stdexcept"

template<typename T>
class LinkedList {
private:
    struct Node {
        T value;
        ShrdPtr<Node> next;
        explicit Node(const T &value) : value(value), next(ShrdPtr<Node>()) {}
    };
    ShrdPtr<Node> head;
    size_t size_;
public:
    LinkedList() : head(ShrdPtr<Node>()), size_(0) {}
    void pop_front(){
        if(size_ > 0) {
            this->head = this->head->next;
            size_--;
        } else{
            throw std::out_of_range("Cannot pop from an empty list.");
        }
    }
    LinkedList(T* items, int count) : head(ShrdPtr<Node>()), size_(0) {
        if (count > 0) {
            head = ShrdPtr<Node>(new Node(items[0]));
            ShrdPtr<Node> current = head;
            for (int i = 1; i < count; ++i) {
                current->next = ShrdPtr<Node>(new Node(items[i]));
                current = current->next;
            }
            size_ = count;
        }
    }

    LinkedList(const LinkedList<T>& list) : head(ShrdPtr<Node>()), size_(0) {
        if (!list.head.null()) {
            head = ShrdPtr<Node>(new Node(list.head->value));
            ShrdPtr<Node> current = head;
            ShrdPtr<Node> listCurrent = list.head->next;
            while (!listCurrent.null()) {
                current->next = ShrdPtr<Node>(new Node(listCurrent->value));
                current = current->next;
                listCurrent = listCurrent->next;
            }
            size_ = list.size_;
        }
    }

    ~LinkedList() = default;

    T GetFirst() const {
        if(size_ == 0){
            throw std::out_of_range("Cannot get element from an empty list.");
        }
        return head->value;
    }

    T GetLast() const {
        if(size_ == 0){
            throw std::out_of_range("Cannot get element from an empty list.");
        }
        ShrdPtr<Node> current = head;
        while (!current->next.null()) {
            current = current->next;
        }
        return current->value;
    }

    T Get(int index) const {
        if(index >= size_){
            throw std::out_of_range("Index out of range or list is empty");
        }
        ShrdPtr<Node> current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
        if (startIndex < 0 || endIndex < 0 || startIndex >= size_ || endIndex >= size_ || startIndex > endIndex) {
            return new LinkedList<T>();
        }
        LinkedList<T>* sublist = new LinkedList<T>();
        ShrdPtr<Node> current = head;
        for (int i = 0; i <= endIndex; ++i) {
            if (i >= startIndex) {
                sublist->Append(current->value);
            }
            current = current->next;
        }
        return sublist;
    }

    size_t GetLength() const {
        return size_;
    }

    void Append(T item) {
        ShrdPtr<Node> newNode = ShrdPtr<Node>(new Node(item));
        if (head.null()) {
            head = newNode;
        } else {
            ShrdPtr<Node> current = head;
            while (!current->next.null()) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++size_;
    }

    void Prepend(T item) {
        ShrdPtr<Node> newNode = ShrdPtr<Node>(new Node(item));
        newNode->next = head;
        head = newNode;
        ++size_;
    }

    void InsertAt(T item, int index) {
        if (index == 0) {
            Prepend(item);
            return;
        } else if(index >= size_){
            throw std::out_of_range("Index is out of range.");
        }
        ShrdPtr<Node> newNode = ShrdPtr<Node>(new Node(item));
        ShrdPtr<Node> current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        ++size_;
    }

    LinkedList<T>* Concat(LinkedList<T> *list) const {
        LinkedList<T>* concatenatedList = new LinkedList<T>(*this);
        ShrdPtr<Node> current = list->head;
        while (!current.null()) {
            concatenatedList->Append(current->value);
            current = current->next;
        }
        return concatenatedList;
    }

    T &operator[](size_t index) {
        ShrdPtr<Node> current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    const T &operator[](size_t index) const {
        ShrdPtr<Node>current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }
};
