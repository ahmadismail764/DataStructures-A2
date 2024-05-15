#include <bits/stdc++.h>
using namespace std;
template <typename T>
class AVLTree
{
    struct Node
    {
        T key;
        Node *left, *right;
        int height;
        Node(T key) : key(key), left(nullptr), right(nullptr), height(1) {}
    };
    Node *root;

    // void printTree(Node *root, string indent, bool last);

public:
    AVLTree() : root(nullptr) {}
    AVLTree(T value);
    int height(Node *N);
    int getBalanceFactor(Node *N);
    Node *rightRotate(Node *y), *leftRotate(Node *x);
    Node *insert(T key);
    Node *nodeWithMinimumValue(Node *node);
    Node *deleteNode(T key);
    // void insert(T key) { root = insertNode(root, key); }
    // void remove(T key) { root = deleteNode(root, key); }
    // void print() { printTree(root, "", true); }
    void postOrder() const;
    void preOrder() const;
    void inOrder() const;
    void breadthFirst() const;
};