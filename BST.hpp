#include <bits/stdc++.h>
using namespace std;

template <class T>
class BST
{
    template <class X>
    class Node
    {
    public:
        T data;
        Node<T> *left = nullptr, *right = nullptr, *parent = nullptr;
        Node(X data) : data(data) {}
    };
    Node<T> *root = nullptr;
    int numOfNodes = 0;
    Node<T> *getMin(Node<T> *temp);
    Node<T> *getMax(Node<T> *max);
    void remove(Node<T> *temp);
    void removeWithTwoChildren(Node<T> *temp);
    int height(Node<T> *temp) const;
    void inOrderTraversal(Node<T> *temp) const;
    void inReversedOrderTraversal(Node<T> *temp) const;
    void preOrderTraversal(Node<T> *temp) const;
    void postOrderTraversal(Node<T> *temp) const;

public:
    BST();
    BST(bool (*cmp)(const T &, const T &));
    ~BST();
    void insert(T val);
    void remove(T val);
    bool find(T val) const;
    // void print();
    void clear();
    int size() const;
    int height() const;
    void inOrderTraversal() const;
    void inReversedOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    void breadthFirstTraversal() const;
};