#include "../include/item.cpp"
#include "../include/Tree.hpp"
#include "AVL.cpp"
using namespace std;
class AVLTree : public Tree
{
    AVL<item> byName, byPrice;

public:
    AVLTree() {};
    ~AVLTree() {};
    void insert(item Item);
    void remove(item Item);
    void displayBySmallerName();
    void displayBySmallerPrice();
};