#include "BST.cpp"
#include "../include/item.cpp"
#include "../include/Tree.hpp"

class BinarySearchTree : public Tree
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