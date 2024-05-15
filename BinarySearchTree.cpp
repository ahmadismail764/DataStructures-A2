#include "BinarySearchTree.hpp"
using namespace std;

bool compByName(item &first, item &second)
{
    return first.getName() < second.getName();
}

bool compByPrice(item &first, item &second)
{
    return first.getPrice() < second.getPrice();
}

BinarySearchTree::BinarySearchTree() {}
BinarySearchTree::~BinarySearchTree() {}

void BinarySearchTree::insert(item &Item)
{
    Item.setComparison(compByPrice);
    byPrice.insert(Item);
    Item.setComparison(compByName);
    byName.insert(Item);
}

void BinarySearchTree::remove(item &item)
{
    byName.remove(item);
    byPrice.remove(item);
}

void BinarySearchTree::displayBySmallerName()
{
    return byName.inOrderTraversal();
}

void BinarySearchTree::displayByGreaterName()
{
    return byName.inReversedOrderTraversal();
}

void BinarySearchTree::displayBySmallerPrice()
{
    return byPrice.inOrderTraversal();
}

void BinarySearchTree::displayByGreaterPrice()
{
    return byPrice.inReversedOrderTraversal();
}