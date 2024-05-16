#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
    T key;
    int height;
    Node *left, *right;

public:
    Node(T value = 0) : key(value), height(0) { left = right = nullptr; }
    int balanceFactor() const { return (left ? left->getHeight() : 0) - (right ? right->getHeight() : 0); }

    T getKey() const { return key; }
    int getHeight() const { return height; }
    Node *getLeft() const { return left; }
    Node *getRight() const { return right; }

    void setLeft(Node *l) { left = l; }
    void setHeight(int h) { height = h; }
    void setRight(Node *r) { right = r; }
};

template <class T>
class AVL
{
    Node<T> *root;

public:
    AVL() { root = new Node<T>(); }
    Node<T> *nodeWithMimumValue() const;
    void visit(Node<T> *node) const { cout << node->getKey() << " "; }

    void breadthFirst() const;
    void inorder(Node<T> *p = nullptr) const;
    void preorder(Node<T> *p = nullptr) const;
    void postorder(Node<T> *p = nullptr) const;

    Node<T> *rightRotate(Node<T> *y);
    Node<T> *leftRotate(Node<T> *y);
    Node<T> *insertNode(Node<T> *node, T value);
    Node<T> *deleteNode(T value);
};
