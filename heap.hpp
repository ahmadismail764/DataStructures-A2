#include <bits/stdc++.h>
#include "Tree.hpp"
using namespace std;

template <typename T>
class Heap : public Tree
{
private:
    vector<T> heap;
    unsigned int size;
    unsigned int capacity;
    function<bool(T&, T&)> compare;
    bool isMaxHeap = true;

public:
    Heap(function<bool(T&, T&)> comp, int capacity = 10, bool isMaxHeap = true);
    Heap(T* arr, int arrSize, function<bool(T&, T&)> comp, bool isMaxHeap = true);
    void heapifyDown(int i, int heap_size, bool isMaxHeap);
    void heapifyUp(int i, bool isMaxHeap);
    void setComparison(function<bool(T&, T&)> comp);
    void buildMaxHeap();
    void buildMinHeap();
    void insert(T valu);
    T remove();
    void heapSort(function<bool(T&, T&)> comp, bool descending = false);
    void printHeap();
    Heap &operator=(T *arr);
};

#ifndef UNTITLED2_HEAP_H
#define UNTITLED2_HEAP_H

#endif // UNTITLED2_HEAP_H
