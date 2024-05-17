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
void AVLTree::displayBySmallerName() { return byName.inorder(); }
void AVLTree::displayBySmallerPrice() { return byPrice.inorder(); }

/* void AVLTree::displayByGreaterName(){
    return byName.inReversedOrderTraversal();
}

void AVLTree::displayByGreaterPrice(){
    return byPrice.inReversedOrderTraversal();
}

void AVLTree::displayItem(string name){
    if (byName.find(item(name,"",0)))
        cout << byName.get(item(name,"",0));
    else
        cout << "NOT FOUND!" << '\n';
} */