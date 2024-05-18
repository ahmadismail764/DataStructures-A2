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
    cout << "\n\n\n";
    avl.displayBySmallerPrice();
}
