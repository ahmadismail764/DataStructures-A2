#include "avlTree.hpp"

template <class T>
Node<T> *AVL<T>::nodeWithMimumValue() const
{
    Node<T> *current = root;
    while (current->getRight() != NULL)
        current = current->getRight();
    return current;
}

template <class T>
void AVL<T>::breadthFirst() const
{
    queue<Node<T> *> queue;
    Node<T> *p = root;
    if (p != 0)
    {
        queue.push(p);
        while (!queue.empty())
        {
            p = queue.front();
            queue.pop();
            visit(p);
            if (p->getLeft() != nullptr)
                queue.push(p->getLeft());
            if (p->getRight() != nullptr)
                queue.push(p->getRight());
        }
    }
}

template <class T>
void AVL<T>::inorder(Node<T> *p) const
{
    if (p)
    {
        inorder(p->getLeft());
        visit(p);
        inorder(p->getRight());
    }
}

template <class T>
void AVL<T>::preorder(Node<T> *p) const
{
    if (p)
    {
        visit(p);
        preorder(p->getLeft());
        preorder(p->getRight());
    }
}

template <class T>
void AVL<T>::postorder(Node<T> *p) const
{
    if (p)
    {
        postorder(p->getLeft());
        postorder(p->getRight());
        visit(p);
    }
}

template <class T>
Node<T> *AVL<T>::rightRotate(Node<T> *y)
{
    Node<T> *x = y->getLeft();
    Node<T> *T2 = x->getRight();
    x->setRight(y);
    y->setLeft(T2);
    y->setHeight();
    x->setHeight();
    return x;
}

template <class T>
Node<T> *AVL<T>::leftRotate(Node<T> *x)
{
    Node<T> *y = x->getRight();
    Node<T> *T2 = y->getLeft();
    y->setLeft(x);
    x->setRight(T2);
    x->setHeight();
    y->setHeight();
    return y;
}