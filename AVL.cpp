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
    {
        return new Node<T>(value);
    }
    if (value < curr->key)
        curr->left = insert(curr->left, value);
    else
        curr->right = insert(curr->right, value);
    update(curr);
    balance(curr);
    return curr;
}

template <class T>
void AVL<T>::update(Node<T> *temp)
{
    int lh = -1, rh = -1;
    if (temp->left)
        cout << "in first condition " << temp->left->key << '\n',
        lh = temp->left->height;
    if (temp->right)
        cout << "in second condition " << temp->right->key << '\n',

        rh = temp->right->height;
    temp->height = max(rh, lh) + 1;
    temp->BF = rh - lh;
    cout << "in update, in " << temp->key 
    << " with hight " << temp->height 
    << " and " << lh << ' ' << rh <<' ' << temp->BF << '\n';
}

template <class T>
void AVL<T>::balance(Node<T> *curr)
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
    temp->key = min->key;
    return remove(min);
}

template <class T>
void AVL<T>::remove(Node<T> *temp)
{
    if (temp->parent && temp->parent->right == temp)
    {
        if (temp->right)
            temp->parent->right = temp->right;
        else if (temp->left)
            temp->parent->right = temp->left;
        else
            temp->parent->right = nullptr;
    }
    else if (temp->parent)
    {
        if (temp->left)
            temp->parent->left = temp->left;
        else if (temp->right)
            temp->parent->left = temp->right;
        else
            temp->parent->left = nullptr;
    }
    delete temp;
    cout << "Finally deleted it!\n";
    return;
}

template <class T>
void AVL<T>::remove(Node<T> *curr, T value)
{
    cout << "Delete!1\n";
    if (curr == nullptr)
        return;
    if (curr->key == value)
    {
        if (curr->left && curr->right)
        {
            cout << "Delete!2\n";
            removeWithTwoChildren(curr);
        }
        else
        {
            cout << "Delete!3\n";
            remove(curr);
        }
    }
    if (value < curr->key)
        remove(curr->left, value);
    else
        remove(curr->right, value);
    update(curr);
    balance(curr);
    cout << "Deletion Success!\n";
}