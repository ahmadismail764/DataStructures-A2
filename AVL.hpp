#include <bits/stdc++.h>
#include "Tree.hpp"
using namespace std;

template <class T>
class AVL
{
    template <class X> // make the node a template class
    class Node
    {
        T key;
        int height, BF; // balance factor (right - left)
        Node *left, *right, *parent;

    public:
        Node(X value = 0) : key(value), height(0), left(nullptr), right(nullptr) {}
    };
    Node<T> *root;

    // private methods, only developer will use
    Node<T> *balance(Node<T> *temp); // checks the bf of all nodes and rotates the tree
    void update(Node<T> *temp);      // updates the height and bf of all nodes after each insertion and deletion
    Node<T> *rightRotate(Node<T> *curr);
    Node<T> *leftRotate(Node<T> *curr);
    Node<T> *insert(Node<T> *curr, T value);
    Node<T> *remove(Node<T> *curr, T value);
    void remove(Node<T> *curr);
    void removeWithTwoChildren(Node<T> *curr) : public : AVL() { root = new Node<T>(); }
    Node<T> *nodeWithMinValue() const;
    void visit(Node<T> *node) const { cout << node->key << " " << node->height << '\n'; }

    void breadthFirst() const;
    void inorder(Node<T> *p = nullptr) const;
    void preorder(Node<T> *p = nullptr) const;
    void postorder(Node<T> *p = nullptr) const;
    void insert(T value);
    void remove(T value);
};
