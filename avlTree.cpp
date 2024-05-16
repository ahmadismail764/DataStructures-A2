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
    y->setHeight(max((y->getLeft() ? y->getLeft()->getHeight() : 0), (y->getRight() ? y->getRight()->getHeight() : 0)) + 1);
    x->setHeight(max((x->getLeft() ? x->getLeft()->getHeight() : 0), (x->getRight() ? x->getRight()->getHeight() : 0)) + 1);
    return x;
}

template <class T>
Node<T> *AVL<T>::leftRotate(Node<T> *x)
{
    Node<T> *y = x->getRight();
    Node<T> *T2 = y->getLeft();
    y->setLeft(x);
    x->setRight(T2);
    x->setHeight(max((x->getLeft() ? x->getLeft()->getHeight() : 0), (x->getRight() ? x->getRight()->getHeight() : 0)) + 1);
    y->setHeight(max((y->getLeft() ? y->getLeft()->getHeight() : 0), (y->getRight() ? y->getRight()->getHeight() : 0)) + 1);
    return y;
}

template <class T>
Node<T> *AVL<T>::insertNode(Node<T> *node, T value)
{
    // Perform standard BST insertion
    if (node == nullptr)
        return new Node<T>(value);

    if (value < node->getKey())
        node->setLeft(insertNode(node->getLeft(), value));
    else if (value > node->getKey())
        node->setRight(insertNode(node->getRight(), value));
    else
        return node; // Duplicate keys are not allowed

    // Update height of this node
    node->setHeight(1 + max((node->getLeft() ? node->getLeft()->getHeight() : 0), (node->getRight() ? node->getRight()->getHeight() : 0)));

    // Get the balance factor of this node
    int balance = node->balanceFactor();

    // If the node becomes unbalanced, there are four cases

    // Left Left Case
    if (balance > 1 && value < node->getLeft()->getKey())
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->getRight()->getKey())
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->getLeft()->getKey())
    {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->getRight()->getKey())
    {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    // If the node is already balanced, return it
    return node;
}
