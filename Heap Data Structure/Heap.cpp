#include "heap.hpp"

template <class T>
Heap<T>::Heap(T *arr, int arrSize, bool isMaxHeap) : size(arrSize), capacity(arrSize * 2), isMaxHeap(isMaxHeap)
{
    compare = [](T &a, T &b)
    { return a < b; };
    heap.resize(capacity);
    std::copy(arr, arr + arrSize, heap.begin());
    if (isMaxHeap)
    {
        buildMaxHeap();
    }
    else
        buildMinHeap();
}

template <class T>
Heap<T>::Heap(int capacity, bool isMaxHeap) : size(0), capacity(capacity), isMaxHeap(isMaxHeap)
{
    compare = [](T &a, T &b)
    { return a < b; };
    heap.resize(capacity);
    if (isMaxHeap)
    {
        buildMaxHeap();
    }
    else
        buildMinHeap();
}

template <class T>
void Heap<T>::heapifyUp(int i, bool isMaxHeap)
{
    int parent = (i - 1) / 2;

    if (isMaxHeap)
    {
        if (i > 0 && compare(heap[parent], heap[i]))
        {
            std::swap(heap[parent], heap[i]);
            heapifyUp(parent, isMaxHeap);
        }
    }
    else
    {
        if (i > 0 && compare(heap[i], heap[parent]))
        {
            std::swap(heap[parent], heap[i]);
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
        {
            target = left;
        }
        if (right < heap_size && compare(heap[target], heap[right]))
        {
            target = right;
        }
    }
    else
    {
        if (left < heap_size && compare(heap[left], heap[target]))
        {
            target = left;
        }
        if (right < heap_size && compare(heap[right], heap[target]))
        {
            target = right;
        }
    }

    if (target != i)
    {
        std::swap(heap[i], heap[target]);
        heapifyDown(target, heap_size, isMaxHeap);
    }
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
    {
        heapifyDown(i, size, true);
    }
}

template <class T>
void Heap<T>::buildMinHeap()
{
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        heapifyDown(i, size, false);
    }
}

template <class T>
void Heap<T>::displayHeap(function<void(T &)> f, bool descending)
{
    vector<T> temp;
    temp = heap;
    foreach (f)
        ;
    int originalSize = size;
    if (descending)
    {
        buildMinHeap();
        for (int i = size - 1; i >= 1; --i)
        {
            std::swap(heap[0], heap[i]);
            heapifyDown(0, i, false);
        }
    }
    else
    {
        buildMaxHeap();
        for (int i = size - 1; i >= 1; --i)
        {
            std::swap(heap[0], heap[i]);
            heapifyDown(0, i, true);
        }
    }
    size = originalSize; // Restore original size
    for (int i = 0; i < size; ++i)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
    heap = temp;
}

template <class T>
void Heap<T>::printHeap()
{
    for (int i = 0; i < size; ++i)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

template <class T>
bool Heap<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
void Heap<T>::foreach (function<void(T &)> f)
{
    for (auto &i : heap)
    {
        f(i);
    }
}
