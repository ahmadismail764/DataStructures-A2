#include <bits/stdc++.h>
using namespace std;

template <class T>
class AVL
{
    template <class X> // make the node a template class
    class Node
    {
    public:
        T key;
        int height, BF; // balance factor (right - left)
        Node *left, *right;
        Node(X value = 0) : key(value), height(0), BF(0), left(nullptr), right(nullptr) {}
    };
    Node<T> *root;

    Node<T> *balance(Node<T> *temp);
    void update(Node<T> *temp);
    void rightRotate(Node<T> *curr);
    void leftRotate(Node<T> *curr);
    Node<T> *insert(Node<T> *curr, T value);
    Node<T> *getParent(Node<T> *curr);
    void remove(Node<T> *curr, T value);
    void remove(Node<T> *curr);
    void removeWithTwoChildren(Node<T> *curr);

public:
    AVL() { root = nullptr; }
    Node<T> *getRoot() const { return root; }
    void visit(Node<T> *node) const { cout << node->key << " " << node->height << ' ' << node->BF << '\n'; }
    void breadthFirst() const;
    void inorder(Node<T> *p = nullptr) const;
    void preorder(Node<T> *p = nullptr) const;
    void postorder(Node<T> *p = nullptr) const;
    void insert(T value);
    void remove(T value);
};
