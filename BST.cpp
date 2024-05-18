#include "BST.hpp"
using namespace std;

template <class T>
BST<T>::BST() {}

template <class T>
BST<T>::~BST() { this->clear(); }

template <class T>
void BST<T>::insert(T val)
{
    ++numOfNodes;
    Node<T> *nNode = new Node<T>(val);
    if (root == nullptr)
        return void(root = nNode);
    Node<T> *temp = root, *prv = nullptr;
    while (temp)
    {
        prv = temp;
        if (temp->data == val)
            return;
        if (val < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (val < prv->data)
        prv->left = nNode;
    else
        prv->right = nNode;
    nNode->parent = prv;
}

template <class T>
bool BST<T>::find(T val) const
{
    Node<T> *temp = root;
    while (temp)
    {
        if (temp->data == val)
            return true;
        else if (temp->data < val)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false;
}

template <class T>
T BST<T>::get(T val)
{
    Node<T> *temp = root;
    while (temp)
    {
        if (temp->data == val)
            return temp->data;
        else if (temp->data < val)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return temp->data;
}

template <class T>
void BST<T>::remove(T val)
{
    if (root == nullptr)
        return;
    Node<T> *temp = root, *prv = nullptr;
    --numOfNodes;
    while (temp)
    {
        if (temp->data == val)
            if (temp->left && temp->right)
                return removeWithTwoChildren(temp);
            else
                return remove(temp);
        else if (val < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return;
}

template <class T>
void BST<T>::remove(Node<T> *temp)
{
    if (temp->parent->right == temp)
        if (temp->right)
            temp->parent->right = temp->right;
        else if (temp->left)
            temp->parent->right = temp->left;
        else
            temp->parent->right = nullptr;
    else if (temp->left)
        temp->parent->left = temp->left;
    else if (temp->right)
        temp->parent->left = temp->right;
    else
        temp->parent->left = nullptr;
    delete temp;
    return;
}

template <class T>
void BST<T>::removeWithTwoChildren(Node<T> *temp)
{
    Node<T> *min = getMin(temp->right);
    temp->data = min->data;
    return remove(min);
}

template <class T>
typename BST<T>::template Node<T> *BST<T>::getMin(Node<T> *temp)
{
    Node<T> *start = temp;
    while (start->left)
        start = start->left;
    return start;
}

template <class T>
typename BST<T>::template Node<T> *BST<T>::getMax(Node<T> *temp)
{
    Node<T> *start = temp;
    while (start->right)
        start = start->right;
    return start;
}

template <class T>
int BST<T>::size() const
{
    return numOfNodes;
}

template <class T>
void BST<T>::clear()
{
    if (root == nullptr)
        return;
    queue<Node<T> *> q;
    q.emplace(root);
    while (!q.empty())
    {
        Node<T> *temp = q.front();
        q.pop();
        if (temp->right)
            q.emplace(temp->right);
        if (temp->left)
            q.emplace(temp->left);
        delete temp;
    }
    root = nullptr;
    numOfNodes = 0;
    return;
}

template <class T>
int BST<T>::height(Node<T> *temp) const
{
    if (temp == nullptr)
        return 0;
    return 1 + max(height(temp->right), height(temp->left));
}

template <class T>
int BST<T>::height() const
{
    return height(root);
}

template <class T>
void BST<T>::inOrderTraversal(Node<T> *temp) const
{
    if (temp == nullptr)
        return;
    inOrderTraversal(temp->left);
    cout << temp->data;
    inOrderTraversal(temp->right);
}

template <class T>
void BST<T>::inReversedOrderTraversal(Node<T> *temp) const
{
    if (temp == nullptr)
        return;
    inReversedOrderTraversal(temp->right);
    cout << temp->data;
    inReversedOrderTraversal(temp->left);
}

template <class T>
void BST<T>::preOrderTraversal(Node<T> *temp) const
{
    if (temp == nullptr)
        return;
    cout << temp->data;
    preOrderTraversal(temp->left);
    preOrderTraversal(temp->right);
}

template <class T>
void BST<T>::postOrderTraversal(Node<T> *temp) const
{
    if (temp == nullptr)
        return;
    postOrderTraversal(temp->left);
    postOrderTraversal(temp->right);
    cout << temp->data;
}

template <class T>
void BST<T>::inOrderTraversal() const
{
    return inOrderTraversal(root);
}

template <class T>
void BST<T>::inReversedOrderTraversal() const
{
    return inReversedOrderTraversal(root);
}

template <class T>
void BST<T>::preOrderTraversal() const
{
    return preOrderTraversal(root);
}

template <class T>
void BST<T>::postOrderTraversal() const
{
    return postOrderTraversal(root);
}

template <class T>
void BST<T>::breadthFirstTraversal() const
{
    if (root == nullptr)
        return;
    queue<Node<T> *> q;
    q.emplace(root);
    while (!q.empty())
    {
        Node<T> *temp = q.front();
        q.pop();
        cout << temp->data;
        if (temp->left)
            q.emplace(temp->left);
        if (temp->right)
            q.emplace(temp->right);
    }
}