#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
    Node() { left = right = nullptr; }
    Node(const int &el, Node *l = nullptr, Node *r = nullptr) : key(el), left(l), right(r) {}
};

class AVLTree
{
public:
    Node *root;
    /* Managerial */
    AVLTree();
    void clearHelper(Node *node);
    void clear();
    bool isEmpty();
    void visit(Node *node);
    int getBalanceFactor(Node *node);
    Node *rightRotate(Node *node);
    Node *leftRotate(Node *node);
    /* Managerial */

    Node *nodewithMinimumVal(Node *node);
    Node *search(int &el);
    void breadthFirst();
    /* Depth-First Traversal starts here */
    void inorder(Node *p);
    void preorder(Node *p);
    void postorder(Node *p);
    /* Depth-First Traversal ends here*/
    Node *insert(Node *node, int key);
    Node *deleteNode(Node *root, int key);
};