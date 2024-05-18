#include "AVLTree.hpp"
using namespace std;
bool compByName(item &first, item &second) { return first.getName() < second.getName(); }
bool compByPrice(item &first, item &second) { return first.getPrice() < second.getPrice(); }

void AVLTree::insert(item Item)
{
    Item.setComparison(compByPrice);
    byPrice.insert(Item);
    Item.setComparison(compByName);
    byName.insert(Item);
}

void AVLTree::remove(item Item)
{
    byName.remove(Item);
    byPrice.remove(Item);
}
void AVLTree::displayBySmallerName() { return byName.inorder(byName.getRoot()); }
void AVLTree::displayBySmallerPrice() { return byPrice.inorder(byPrice.getRoot()); }