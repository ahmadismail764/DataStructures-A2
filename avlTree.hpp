#include <bits/stdc++.h>
using namespace std;

template <class T>
class AVLTree
{
private:
    template <class X>
    class AVLNode
    {
    public:
        T key;
        AVLNode<T> *left, *right;
        AVLNode(){left = right = nullptr;}
        AVLNode(const T &el, AVLNode<X> *l = nullptr, AVLNode<X> *r = nullptr) : key(el), left(l), right(r) {}
    };
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