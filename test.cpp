#include "BinarySearchTree.cpp"
using namespace std;

int main()
{
    BinarySearchTree bst;
    item Item("Apple", "fruit", 4), Item2("Banana", "fruit", 10), Item3("Orange", "fruit", 7);
    bst.insert(Item);
    bst.insert(Item2);
    bst.insert(Item3);
    bst.displayBySmallerName();
    cout << '\n';
    bst.displayByGreaterName();
    cout << '\n';
    bst.displayBySmallerPrice();
    cout << '\n';
    bst.displayByGreaterPrice();
    cout << '\n';
}