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
    int height(Node *N);
    int getBalanceFactor(Node *N);
    Node *rightRotate(Node *y), *leftRotate(Node *x);
    Node *insertNode(Node *node, T key);
    Node *nodeWithMinimumValue(Node *node);
    Node *deleteNode(Node *root, T key);
    void printTree(Node *root, string indent, bool last);

public:
    AVLTree() : root(nullptr) {}
    void insert(T key) { root = insertNode(root, key); }
    void remove(T key) { root = deleteNode(root, key); }
    void print() { printTree(root, "", true); }
};

int main()
{
    AVLTree<int> tree;
    tree.insert(33);
    tree.insert(13);
    tree.insert(53);
    tree.insert(9);
    tree.insert(21);
    tree.insert(61);
    tree.insert(8);
    tree.insert(11);
    tree.print();
    tree.remove(13);
    cout << "After deleting 13\n";
    tree.print();
}
