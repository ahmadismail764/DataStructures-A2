#include "AVL.cpp"
#include "item.cpp"
#include "Tree.hpp"
using namespace std;

class AVLTree : public Tree
{
    AVL<item> byName, byPrice;

public:
    AVLTree();
    ~AVLTree();
    void insert(item Item);
    void remove(item Item);
    void displayBySmallerName();
    void displayByGreaterName();
    void displayBySmallerPrice();
    void displayByGreaterPrice();
    void displayItem(string name);
};