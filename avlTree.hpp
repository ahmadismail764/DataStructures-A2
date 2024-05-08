#include <bits/stdc++.h>
#include "avlNode.cpp"
using namespace std;

template <class T>
class AVLTree
{
public:
    AVLNode<T> *root;
    AVLTree();
    void clear();
    bool isEmpty();
    void visit(AVLNode<T> *node);
    T *search(T &el);
    void breadthFirst();
    /* Depth-First Traversal starts here */
    void inorder(AVLNode<T> *p);
    void preorder(AVLNode<T> *p);
    void postorder(AVLNode<T> *p);
    /* Depth-First Traversal ends here*/
    void insert(const T &el);
    void deleteByCopying(AVLNode<T> *&node);
};