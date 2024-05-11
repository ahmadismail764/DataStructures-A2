#include "BinarySearchTree.hpp"
using namespace std;

BinarySearchTree::BinarySearchTree(){}
BinarySearchTree::~BinarySearchTree(){}
void BinarySearchTree::insert(item item){
    byName.insert(item);
    byPrice.insert(item);
}
void BinarySearchTree::remove(item item){
    byName.remove(item);
    byPrice.remove(item);
}
void BinarySearchTree::displayBySmallerName(){
    return byName.inOrderTraversal();
}
void BinarySearchTree::displayByGreaterName(){
    return byName.inReversedOrderTraversal();
}
void BinarySearchTree::displayBySmallerPrice(){
    return byPrice.inOrderTraversal();
}
void BinarySearchTree::displayByGreaterPrice(){
    return byPrice.inReversedOrderTraversal();
}