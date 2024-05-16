#include <algorithm>
#include <iostream>
template<typename T>
class Heap{
private:
    T* name_max_heap, *name_min_heap, *price_max_heap, *price_min_heap;
    unsigned int size;
    unsigned int capacity;
public:
    Heap();
    Heap(T* arr, int size);
    ~Heap();
    void minheapify(int i, std::function<bool()>cmp = [](const T&x, const T&y){return x <= y;});
    void maxheapify(int i, std::function<bool()>cmp = [](const T&x, const T&y){return x <= y;});
    void add(T item);
    void print();
    void remove(T item);
    void displayItem(T item);
    void displayItemsSortedByName();
    void displayItemsSortedBYPrice();
    Heap& operator = (T* arr);
};



#ifndef UNTITLED2_HEAP_H
#define UNTITLED2_HEAP_H

#endif //UNTITLED2_HEAP_H
