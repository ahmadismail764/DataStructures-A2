#include "avlTree.hpp"

template <class T>
AVLTree<T>::AVLTree(T value)
{
    root = nullptr;
    root->left = root->right = nullptr;
    root->key = value;
    root->height = 0;
}

template <class T>
int AVLTree<T>::height(Node *N)
{
    return ((N == nullptr) ? 0 : N->height);
}

template <class T>
typename AVLTree<T>::Node *AVLTree<T>::rightRotate(Node *y)
{
    Node *x = y->left, *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

template <class T>
int AVLTree<T>::getBalanceFactor(Node *N)
{
    return ((N == nullptr) ? height(N->left) - height(N->right));
}

template <class T>
typename AVLTree<T>::Node *AVLTree<T>::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

/* template <class T>
typename AVLTree<T>::Node *AVLTree<T>::insert(T key)
{
    if (!root->key)
    {
        AVLTree(key);
        return;
    }
    Node *node;
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1)
    {
        if (key < node->left->key)
            return rightRotate(node);
        else if (key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1)
    {
        if (key > node->right->key)
            return leftRotate(node);
        else if (key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}
 */
template <class T>
typename AVLTree<T>::Node *AVLTree<T>::nodeWithMinimumValue(Node *node)
{
    Node *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

template <class T>
typename AVLTree<T>::Node *AVLTree<T>::deleteNode(T key)
{
    if (root == nullptr)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == nullptr) || (root->right == nullptr))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            Node *temp = nodeWithMinimumValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1)
    {
        if (getBalanceFactor(root->left) >= 0)
            return rightRotate(root);
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1)
    {
        if (getBalanceFactor(root->right) <= 0)
            return leftRotate(root);
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

template <class T>
void AVLTree<T>::postOrder() const
{
    Node *current = root;
    while (current != nullptr)
    {
        postOrder(current->left);
        postOrder(current->right);
        cout << current->key << ' ';
    }
}

template <class T>
void AVLTree<T>::preOrder() const
{
    Node *current = root;
    if (current != nullptr)
    {
        cout << current->key << " ";
        preorderTraversal(current->left);
        preorderTraversal(current->right);
    }
}

template <class T>
void AVLTree<T>::inOrder() const
{
    Node *current = root;
    if (current != nullptr)
    {
        inorderTraversal(current->left);
        cout << current->key << " ";
        inorderTraversal(current->right);
    }
}

template <class T>
void AVLTree<T>::breadthFirst() const
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->key << " ";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}
