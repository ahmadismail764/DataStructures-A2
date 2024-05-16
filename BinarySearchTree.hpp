#include "BST.cpp"
#include "item.cpp"
using namespace std;

class BinarySearchTree
{
    BST<item> byName, byPrice;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(item Item);
    void remove(item Item);
    void displayBySmallerName();
    void displayByGreaterName();
    void displayBySmallerPrice();
    void displayByGreaterPrice();
    void displayItem(string name);
};