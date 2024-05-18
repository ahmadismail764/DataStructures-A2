#include "AVLTree.cpp"

int main()
{
    
    AVLTree avl;
    avl.insert(item("Apple", "fruit", 4));
    avl.insert(item("Banana", "fruit", 10));
    avl.insert(item("Orange", "fruit", 7));
    avl.insert(item("Soap", "clean", 3.5));
    avl.insert(item("Ball", "sport", 20));
    avl.displayBySmallerName();
    cout << '\n';
    // avl.displayByGreaterName();
    cout << '\n';
    avl.displayBySmallerPrice();
    cout << '\n';
    // avl.displayByGreaterPrice();
    cout << '\n';
    // avl.displayItem("Ball");
    cout << '\n';
    // avl.displayItem("anything");
    // AVL<int> tree;

    // // Insertion Test Cases
    // cout << "Insertion Test Cases:\n";
    // tree.insert(10);
    // tree.insert(5);
    // tree.insert(15);
    // tree.insert(3);
    // tree.insert(7);
    // tree.insert(12);
    // tree.insert(17);
    // cout << "Inorder traversal after insertion:\n";
    // tree.inorder(tree.getRoot());
    // cout << '\n';

    // cout << "Deletion Test Cases:\n";
    // tree.remove(3);
    // tree.remove(7);
    // tree.remove(15);
    // cout << "Inorder traversal after deletion:\n";
    // tree.inorder(tree.getRoot());
    // cout << '\n';

    // // Balancing Test Cases
    // cout << "Balancing Test Cases:\n";
    // tree.insert(20); // Right-heavy tree
    // tree.insert(25);
    // tree.insert(30);
    // cout << "Inorder traversal after balancing (right-heavy):\n";
    // tree.inorder();
    // cout << '\n';

    // tree = AVL<int>(); // Reset tree

    // tree.insert(30); // Left-heavy tree
    // tree.insert(25);
    // tree.insert(20);
    // cout << "Inorder traversal after balancing (left-heavy):\n";
    // tree.inorder();
    // cout << '\n';

    // tree = AVL<int>(); // Reset tree

    // tree.insert(20); // Zigzag pattern
    // tree.insert(30);
    // tree.insert(25);
    // cout << "Inorder traversal after balancing (zigzag pattern):\n";
    // tree.inorder();
    // cout << '\n';

    // // Traversal Test Cases
    // cout << "Traversal Test Cases:\n";
    // cout << "Inorder traversal:\n";
    // tree.inorder();
    // cout << '\n';
    // cout << "Preorder traversal:\n";
    // tree.preorder();
    // cout << '\n';
    // cout << "Postorder traversal:\n";
    // tree.postorder();
    // cout << '\n';
}
