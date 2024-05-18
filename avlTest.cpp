#include "AVL.cpp"

int main()
{
    AVL<int> tree;

    // Insertion Test Cases
    cout << "Insertion Test Cases:\n";
    tree.insert(10);
    tree.insert(5);
    // tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);
    cout << "Inorder traversal after insertion:\n";
    tree.inorder(tree.getRoot());
    cout << '\n';

    // cout << "Deletion Test Cases:\n";
    // tree.remove(3);
    // tree.inorder(tree.getRoot());
    // tree.remove(7);  // Deleting node with one child
    // tree.remove(15); // Deleting node with two children
    // cout << "Inorder traversal after deletion:\n";
    // tree.inorder(tree.getRoot());
    // cout << endl;

    // // Balancing Test Cases
    // cout << "Balancing Test Cases:\n";
    // tree.insert(20); // Right-heavy tree
    // tree.insert(25);
    // tree.insert(30);
    // cout << "Inorder traversal after balancing (right-heavy):\n";
    // tree.inorder();
    // cout << endl;

    // tree = AVL<int>(); // Reset tree

    // tree.insert(30); // Left-heavy tree
    // tree.insert(25);
    // tree.insert(20);
    // cout << "Inorder traversal after balancing (left-heavy):\n";
    // tree.inorder();
    // cout << endl;

    // tree = AVL<int>(); // Reset tree

    // tree.insert(20); // Zigzag pattern
    // tree.insert(30);
    // tree.insert(25);
    // cout << "Inorder traversal after balancing (zigzag pattern):\n";
    // tree.inorder();
    // cout << endl;

    // // Traversal Test Cases
    // cout << "Traversal Test Cases:\n";
    // cout << "Inorder traversal:\n";
    // tree.inorder();
    // cout << endl;
    // cout << "Preorder traversal:\n";
    // tree.preorder();
    // cout << endl;
    // cout << "Postorder traversal:\n";
    // tree.postorder();
    // cout << endl;

    // return 0;
}
