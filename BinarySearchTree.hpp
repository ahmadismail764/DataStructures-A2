#include "BST.cpp"
#include "item.cpp"
using namespace std;

class BinarySearchTree {
private:
    BST<item> byName,byPrice;
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(item& item);
    void remove(item& item);
    void displayBySmallerName();
    void displayByGreaterName();
    void displayBySmallerPrice();
    void displayByGreaterPrice();
};