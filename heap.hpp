#include <bits/stdc++.h>
#include "Tree.hpp"
using namespace std;

template <typename T>
class Heap:public Tree
{
private:
    vector<T> heap;
    unsigned int size;
    unsigned int capacity;
    function<bool(T&, T&)> compare;
    bool isMaxHeap = true;

public:
    Heap(int capacity = 10, bool isMaxHeap = true);
    Heap(T* arr, int arrSize, bool isMaxHeap = true);
    void heapifyDown(int i, int heap_size, bool isMaxHeap);
    void heapifyUp(int i, bool isMaxHeap);
    void buildMaxHeap();
    void buildMinHeap();
    void insert(T valu);
    T remove();
    bool isEmpty();
    void displayHeap(function<void(T&)> f, bool descending = false);
    void printHeap();
    void foreach(function<void(T&)> f);
    Heap &operator=(T *arr);
};

#ifndef UNTITLED2_HEAP_H
#define UNTITLED2_HEAP_H

#endif // UNTITLED2_HEAP_H
