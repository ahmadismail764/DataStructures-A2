#include <bits/stdc++.h>
#include "Tree.hpp"
using namespace std;

template <class T>
class AVL
{
private:
    template <class X> // make the node a template class
    class Node
    {
        T key;
        int height, BF; // balance factor
        Node *left, *right, *parent;

    public:
        Node(X value = 0) : key(value), height(0), left(nullptr), right(nullptr) {}
        int balanceFactor() const { return (left ? left->getHeight() : 0) - (right ? right->getHeight() : 0); }
    };
    Node<T> *root;

    // private methods, only developer will use
    void balance(); // checks the bf of all nodes and rotates the tree
    void update();  // updates the height and bf of all nodes after each insertion and deletion
    Node<T> *rightRotate(Node<T> *y);
    Node<T> *leftRotate(Node<T> *y);
    // Node<T> *insertNode(Node<T> *node, T value);
    // Node<T> *deleteNode(Node<T> *root, T value);
public:
    AVL() { root = new Node<T>(); }
    Node<T> *nodeWithMinmumValue() const;
    void visit(Node<T> *node) const { cout << node->key << " " << node->height << '\n'; }

    void breadthFirst() const;
    void inorder(Node<T> *p = nullptr) const;
    void preorder(Node<T> *p = nullptr) const;
    void postorder(Node<T> *p = nullptr) const;
    void insert(T value);
    void remove(T value);
};
