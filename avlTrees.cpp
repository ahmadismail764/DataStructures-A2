#include "avlTree.hpp"

template <class T>
AVLTree<T>::AVLTree() { root = 0; }

template <class T>
void AVLTree<T>::clear() { root = 0; }

template <class T>
bool AVLTree<T>::isEmpty() { return root == 0; }

template <class T>
void AVLTree<T>::visit(AVLNode<T> *node) { cout << node->key << " "; }

template <class T>
T *AVLTree<T>::search(T &el)
{
    AVLNode<T> *p = root;
    while (p != 0)
    {
        if (el == p->key)
            return &p->key;
        else if (el < p->key)
            p = p->left;
        else
            p = p->right;
    }
}

// Breadth-First starts here
template <class T>
void AVLTree<T>::breadthFirst()
{
    queue<AVLNode<T> *> queue;
    AVLNode<T> *p = root;
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
// Breadth-First ends here

// Depth first traversal starts here
template <class T>
void AVLTree<T>::inorder(AVLNode<T> *p)
{
    if (p != 0)
    {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template <class T>
void AVLTree<T>::preorder(AVLNode<T> *p)
{
    if (p != 0)
    {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void AVLTree<T>::postorder(AVLNode<T> *p)
{
    if (p != 0)
    {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}
// Depth first traversal starts here

template <class T>
void AVLTree<T>::insert(const T &el)
{
    AVLNode<T> *p = root, *prev = 0;
    while (p != 0)
    {
        prev = p;
        p = ((p->key < el) ? p->right : p->left);
    }
    if (root == 0)
        root = new AVLNode<T>(el);
    else if (prev->key < el)
        prev->right = new AVLNode<T>(el);
    else
        prev->left = new AVLNode<T>(el);
}

template <class T>
void AVLTree<T>::deleteByCopying(AVLNode<T> *&node)
{
    AVLNode<T> *prev, *tmp = node;
    if (node->right == 0)
        node = node->left;

    else if (node->left == 0)
        node = node->right;
    else
    {
        tmp = node->left;
        prev = node;
        while (tmp->right != 0)
        {
            prev = tmp;
            tmp = tmp->right;
        }
        node->key = tmp->key;
        if (prev == node)
            prev->left = tmp->left;
        else
            prev->right = tmp->left;
    }
    delete tmp;
}

int main() { return 0; }