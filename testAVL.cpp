#include "avlTree.hpp"

int main()
{
    AVL<int> avlTree;
    Node<int> *root = nullptr;
    root = avlTree.insertNode(root, 33);
    root = avlTree.insertNode(root, 13);
    root = avlTree.insertNode(root, 53);
    root = avlTree.insertNode(root, 9);
    root = avlTree.insertNode(root, 21);
    root = avlTree.insertNode(root, 61);
    root = avlTree.insertNode(root, 8);
    root = avlTree.insertNode(root, 11);

    cout << "InOrder: ";
    avlTree.inorder(root);
    cout << endl;
}