#include "BinarySearchTree.cpp"

int main()
{
    BinarySearchTree bst;
    bst.insert(item("Apple", "fruit", 4));
    bst.insert(item("Banana", "fruit", 10));
    bst.insert(item("Orange", "fruit", 7));
    bst.insert(item("Soap", "clean", 3.5));
    bst.insert(item("Ball", "sport", 20));
    bst.displayBySmallerName();
    cout << '\n';
    bst.displayByGreaterName();
    cout << '\n';
    bst.displayBySmallerPrice();
    cout << '\n';
    bst.displayByGreaterPrice();
    cout << '\n';
    bst.displayItem("Ball");
    cout << '\n';
    bst.displayItem("anything");
}