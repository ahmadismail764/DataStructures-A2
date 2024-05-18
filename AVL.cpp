#include "AVL.hpp"

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
            if (p->left != nullptr)
                queue.push(p->left);
            if (p->right != nullptr)
                queue.push(p->right);
        }
    }
}

template <class T>
void AVL<T>::inorder(Node<T> *p) const
{
    if (p)
    {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template <class T>
void AVL<T>::preorder(Node<T> *p) const
{
    if (p)
    {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void AVL<T>::postorder(Node<T> *p) const
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template <class T>
typename AVL<T>::template Node<T> *AVL<T>::rightRotate(Node<T> *curr)
{
    Node<T> *newRoot = curr->left;
    Node<T> *T2 = newRoot->right;
    newRoot->left = curr;
    newRoot->parent = curr->parent;
    curr->parent = newRoot;
    curr->left = T2;
    T2->parent = curr;
    update(curr);
    update(newRoot);
    return newRoot;
}

template <class T>
typename AVL<T>::template Node<T> *AVL<T>::leftRotate(Node<T> *curr)
{
    Node<T> *newRoot = curr->right;
    Node<T> *T2 = newRoot->left;
    newRoot->left = curr;
    newRoot->parent = curr->parent;
    curr->parent = newRoot;
    curr->right = T2;
    T2->parent = curr;
    update(curr);
    update(newRoot);
    return newRoot;
}

template <class T>
void AVL<T>::insert(T value) { root = insert(root, value); }

template <class T>
typename AVL<T>::template Node<T> *AVL<T>::insert(Node<T> *curr, T value)
{
    if (curr == nullptr)
        return new Node<T>(value);
    if (value < curr->key)
        curr->left = insert(curr->left, value);
    else
        curr->right = insert(curr->right, value);
    update(curr);
    return balance(curr);
}

template <class T>
void AVL<T>::update(Node<T> *temp)
{
    int lh = -1, rh = -1;
    if (temp->left)
        lh = temp->left->height;
    if (temp->right)
        rh = temp->right->height;
    temp->height = max(rh, lh) + 1;
    temp->BF = rh - lh;
}

template <class T>
typename AVL<T>::template Node<T> *AVL<T>::balance(Node<T> *curr)
{
    if (curr->BF < -1)
    {
        if (curr->left->BF > 0)
            leftRotate(curr->left);
        rightRotate(curr);
    }
    else if (curr->BF > 1)
    {
        if (curr->right->BF < 0)
            rightRotate(curr->right);
        leftRotate(curr);
    }
    return curr;
}

template <class T>
void AVL<T>::remove(T value)
{
    if (root == nullptr)
        return;
    return remove(root, value);
}

template <class T>
void AVL<T>::removeWithTwoChildren(Node<T> *temp)
{
    Node<T> *min = temp->right;
    while (min->left)
        min = min->left;
    temp->data = min->data;
    return remove(min);
}

template <class T>
void AVL<T>::remove(Node<T> *temp)
{
    if (temp->parent->right == temp)
    {
        if (temp->right)
            temp->parent->right = temp->right;
        else if (temp->left)
            temp->parent->right = temp->left;
        else
            temp->parent->right = nullptr;
    }
    else
    {
        if (temp->left)
            temp->parent->left = temp->left;
        else if (temp->right)
            temp->parent->left = temp->right;
        else
            temp->parent->left = nullptr;
    }
    delete temp;
    return;
}

template <class T>
void AVL<T>::remove(Node<T> *curr, T value)
{
    if (curr == nullptr)
        return;
    if (curr->key == value)
        return (curr->left && curr->right) ? removeWithTwoChildren(curr) : remove(curr);
    (value < curr->key) ? remove(curr->left, value) : remove(curr->right, value);
    update(curr);
    curr = balance(curr);
}