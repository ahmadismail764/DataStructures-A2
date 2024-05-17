#include "heap.hpp"
#include <bits/stdc++.h>

template <class T>
Heap<T>::Heap(T *arr, int arrSize, function<bool(T &, T &)> comp, bool isMaxHeap) : size(arrSize), capacity(arrSize * 2), compare(comp), isMaxHeap(isMaxHeap)
{
    heap.resize(capacity);
    copy(arr, arr + arrSize, heap.begin());
    if (isMaxHeap)
    {
        buildMaxHeap();
    }
    else
        buildMinHeap();
}

template <class T>
Heap<T>::Heap(function<bool(T &, T &)> comp, int capacity, bool isMaxHeap) : size(0), capacity(capacity), compare(comp), isMaxHeap(isMaxHeap)
{
    heap.resize(capacity);
    (isMaxHeap) ? buildMaxHeap() : buildMinHeap();
}

template <class T>
void Heap<T>::heapifyUp(int i, bool isMaxHeap)
{
    int parent = (i - 1) / 2;

    if (isMaxHeap)
    {
        if (i > 0 && compare(heap[parent], heap[i]))
        {
            swap(heap[parent], heap[i]);
            heapifyUp(parent, isMaxHeap);
        }
    }
    else
    {
        if (i > 0 && compare(heap[i], heap[parent]))
        {
            swap(heap[parent], heap[i]);
            heapifyUp(parent, isMaxHeap);
        }
    }
}

template <class T>
void Heap<T>::heapifyDown(int i, int heap_size, bool isMaxHeap)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int target = i;

    if (isMaxHeap)
    {
        if (left < heap_size && compare(heap[target], heap[left]))
            target = left;

        if (right < heap_size && compare(heap[target], heap[right]))
            target = right;
    }
    else
    {
        if (left < heap_size && compare(heap[left], heap[target]))
            target = left;
        if (right < heap_size && compare(heap[right], heap[target]))
            target = right;
    }

    if (target != i)
    {
        swap(heap[i], heap[target]);
        heapifyDown(target, heap_size, isMaxHeap);
    }
}
template <class T>
void Heap<T>::setComparison(function<bool(T &, T &)> comp)
{
    compare = comp;
    (isMaxHeap) ? buildMaxHeap() : buildMinHeap();
}

template <class T>
void Heap<T>::insert(T value)
{
    if (size == capacity)
    {
        capacity *= 2;
        heap.resize(capacity);
    }
    heap[size] = value;
    heapifyUp(size, isMaxHeap);
    size++;
}

template <class T>
T Heap<T>::remove()
{
    if (size == 0)
    {
        throw out_of_range("Heap is empty");
    }
    T root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0, size, isMaxHeap);
    return root;
}

template <class T>
void Heap<T>::buildMaxHeap()
{
    for (int i = size / 2 - 1; i >= 0; --i)
        heapifyDown(i, size, true);
}

template <class T>
void Heap<T>::buildMinHeap()
{
    for (int i = size / 2 - 1; i >= 0; --i)
        heapifyDown(i, size, false);
}

template <class T>
void Heap<T>::heapSort(function<bool(T &, T &)> comp, bool descending)
{
    setComparison(comp);
    int originalSize = size;
    if (descending)
    {
        buildMinHeap();
        for (int i = size - 1; i >= 1; --i)
        {
            swap(heap[0], heap[i]);
            heapifyDown(0, i, false);
        }
    }
    else
    {
        buildMaxHeap();
        for (int i = size - 1; i >= 1; --i)
        {
            swap(heap[0], heap[i]);
            heapifyDown(0, i, true);
        }
    }
    size = originalSize; // Restore original size
}

template <class T>
void Heap<T>::printHeap()
{
    (isMaxHeap) ? buildMaxHeap() : buildMinHeap();
    for (int i = 0; i < size; ++i)
        cout << heap[i] << " ";
    cout << '\n';
}