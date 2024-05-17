#include "AVL.hpp"

template <class T>
typename AVL<T>::template Node<T>* AVL<T>::nodeWithMinmumValue() const
{
    Node<T> *current = root;
    while (current->right() != NULL)
        current = current->right;
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
typename AVL<T>::template Node<T>* AVL<T>::rightRotate(Node<T> *y)
{
    Node<T> *x = y->left;
    Node<T> *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height++;
    x->height++;
    return x;
}

template <class T>
typename AVL<T>::template Node<T>* AVL<T>::leftRotate(Node<T> *x)
{
    Node<T> *y = x->right;
    Node<T> *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height++;
    y->height++;
    return y;
}

template <class T>
void AVL<T>::insert(T value){
    Node<T> *nNode = new Node<T>(value);
    if (root == nullptr)
        return void(root = nNode);
    Node<T> *temp = root, *prv = nullptr;
    while (temp)
    {
        prv = temp;
        if (temp->key == value)
            return;
        if (value < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (value < prv->key)
        prv->left = nNode;
    else
        prv->right = nNode;
    nNode->parent = prv;
    this->update();
    this->balance();
    return;
}

template <class T>
void AVL<T>::remove(T value){
    if (root == nullptr)
        return;
    Node<T> *temp = root, *prv = nullptr;
    while (temp)
    {
        if (temp->key == value)
            if (temp->left && temp->right)
                // return removeWithTwoChildren(temp);
            else
                // return remove(temp);
        else if (value < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    this->update();
    this->balance();
    return;
}