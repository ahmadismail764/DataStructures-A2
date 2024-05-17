#include "Heap.h"

template<class T>
Heap<T>::Heap() {
    size = 0;
    capacity = 1;
    name_max_heap = new T[capacity];
    name_min_heap = new T[capacity];
    price_max_heap = new T[capacity];
    price_min_heap = new T[capacity];
}
template<class T>
Heap<T>::~Heap(){
    delete[] name_max_heap;
    delete[] name_min_heap;
    delete[] price_min_heap;
    delete[] price_max_heap;
}

template<class T>
Heap<T>::Heap(T* arr, int size) {
    this->size = size;
    capacity = 1;
    if (size > capacity) {
        while (capacity < size) capacity *= 2;
        name_max_heap = new T[capacity];
        name_min_heap = new T[capacity];
        price_max_heap = new T[capacity];
        price_min_heap = new T[capacity];
    }
    std::copy(arr, arr + size, name_max_heap);
    std::copy(arr, arr + size, name_min_heap);
    for (int i = size / 2; i >= 0; --i) {
        maxheapify(i);
    }
    for (int i = size / 2; i >= 0; --i) {
        minheapify(i);
    }
}

template<class T>
void Heap<T>::maxheapify(int i, const std::function<bool()>cmp) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int mx = i;
    if(l < size && cmp(name_max_heap[l], name_max_heap[mx])){
        mx = l;
    }
    if(r < size && cmp(name_max_heap[r], name_max_heap[mx])){
        mx = r;
    }
    if(mx != i){
        std::swap(name_max_heap[mx], name_max_heap[i]);
        maxheapify(mx);
    }
}


template<class T>
void Heap<T>::minheapify(int i, const std::function<bool()>cmp) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int mn = i;
    if(l < size && cmp(name_min_heap[l] ,name_min_heap[mn])){
        mn = l;
    }
    if(r < size && cmp(name_min_heap[r] ,name_min_heap[mn])){
        mn = r;
    }
    if(mn != i){
        std::swap(name_min_heap[mn],name_min_heap[i]);
        maxheapify(mn);
    }
}

template<class T>
Heap<T>& Heap<T>::operator=(T* arr) {
    this->name_max_heap = arr;
    this->min_heap = arr;
    return *this;
}

template<class T>
void Heap<T>::print() {
    for (int i = 0; i < size; ++i) {
        std::cout<< name_max_heap[i] << ' ';
    }
    std::cout<< std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout<<name_min_heap[i] << ' ';
    }
}