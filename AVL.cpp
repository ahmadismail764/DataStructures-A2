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
void AVL<T>::insert(T value) { 
    if (root == nullptr)
        root = new Node<T>(value);
    else 
        insert(root,value);
}

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
    return balance(curr);
    // return curr;
}

template <class T>
typename AVL<T>::template Node<T> *AVL<T>::getParent(Node<T> *curr){
    if (curr == root || root == nullptr)
        return nullptr;
    Node<T>* temp = root;
    while(temp)
        if (temp->left == curr || temp->right == curr)
            return temp;
        else if (curr->key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
}


template <class T>
void AVL<T>::update(Node<T> *temp)
{
    int lh = -1, rh = -1;
    if (temp->left)
        // cout << "in first condition " << temp->left->key << '\n',
        lh = temp->left->height;
    if (temp->right)
        // cout << "in second condition " << temp->right->key << '\n',
        rh = temp->right->height;
    temp->height = max(rh, lh) + 1;
    temp->BF = rh - lh;
    // cout << "in update, in " << temp->key 
    // << " with hight " << temp->height 
    // << " and " << lh << ' ' << rh <<' ' << temp->BF << '\n';
}

template <class T>
void AVL<T>::leftRotate(Node<T> *curr)
{
    Node<T> *newRoot = curr->right, *parent = getParent(curr);
    Node<T> *T2 = newRoot->left;
    if (parent == nullptr)
        root = newRoot;
    else if (parent->right == curr)
        parent->right = newRoot;
    else
        parent->left = newRoot;
    newRoot->left = curr;
    curr->right = T2;
    update(curr);
    update(newRoot);
}

template <class T>
void AVL<T>::rightRotate(Node<T> *curr)
{
    
    Node<T> *newRoot = curr->left;
    Node<T> *T2 = newRoot->right, *parent = getParent(curr);
    if (parent == nullptr)
        root = newRoot;
    else if (parent->right == curr)
        parent->right = newRoot;
    else
        parent->left = newRoot;
    newRoot->right = curr;
    curr->left = T2;
    // cout << "in right rotation " << curr->key << ' '
    // << curr->left->key << ' ' 
    // << newRoot->key <<' '
    // << newRoot->right->key<< ' '
    // << root->key << ' '
    // << root->right->key << ' '
    // << root->left->key << '\n';
    update(curr);
    update(newRoot);
    // return newRoot;
}

template <class T>
typename AVL<T>::template Node<T>* AVL<T>::balance(Node<T> *curr)
{
    if (curr->BF < -1)
    {
        // cout << "in first balance " << curr->key << '\n';
        if (curr->left->BF > 0)
            leftRotate(curr->left);
        rightRotate(curr);
    }
    else if (curr->BF > 1)
    {
        // cout << "in second balance " << curr->key << '\n';

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
    temp->key = min->key;
    return remove(min);
}

template <class T>
void AVL<T>::remove(Node<T> *temp)
{
    Node<T>* parent = getParent(temp);
    if (parent && parent->right == temp)
    {
        if (temp->right)
            parent->right = temp->right;
        else if (temp->left)
            parent->right = temp->left;
        else
            parent->right = nullptr;
    }
    else if (parent)
    {
        if (temp->left)
            parent->left = temp->left;
        else if (temp->right)
            parent->left = temp->right;
        else
            parent->left = nullptr;
    }
    delete temp;
    cout << "Finally deleted it!\n";
    return;
}

template <class T>
void AVL<T>::remove(Node<T> *curr, T value){
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
    curr = balance(curr);
    cout << "Deletion Success!\n";
}