#include "avlTree.hpp"

int main()
{
    AVLTree<int> tree;
    tree.insert(33);
    tree.insert(13);
    tree.insert(53);
    tree.insert(9);
    tree.insert(21);
    tree.insert(61);
    tree.insert(8);
    tree.insert(11);

    cout << "\nPostorder Traversal: ";
    tree.postOrder();
    cout << "\nPreorder Traversal: ";
    tree.preOrder();
    cout << "\nInorder Traversal: ";
    tree.inOrder();
    cout << "\nBreadth-First Traversal: ";
    tree.breadthFirst();
    tree.deleteNode(13);
}
