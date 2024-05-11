#include "BST.cpp"
using namespace std;

class BinarySearchTree {
private:
    BST byName,byPrice;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(item item);
    void remove(item item);
    void displayBySmallerName();
    void displayByGreaterName();
    void displayBySmallerPrice();
    void displayByGreaterPrice();
};