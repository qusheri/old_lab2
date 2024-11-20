#pragma once
#include "cstddef"
#include "Sequence.h"
#include "iostream"
template<typename T>
class ISort{
public:
    virtual ~ISort() = default;
    virtual Sequence<T>* sort(Sequence<T>* container, int (*cmp)(T,T)) = 0;
};

