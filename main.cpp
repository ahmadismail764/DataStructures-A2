#include <iostream>
#include "BinarySearchTree.cpp"
#include "item.cpp"
#include "Heap.cpp"
#include "AVL.cpp"
using namespace std;
function<bool(item &, item &)> compareByPrice = [](item &a, item &b)
{ return a.getPrice() < b.getPrice(); };

// Comparison function to compare by name
function<bool(item &, item &)> compareByName = [](item &a, item &b)
{ return a.getName() < b.getName(); };
function<void(item &)> setByPrice = [](item &a)
{ a.setComparison(compareByPrice); };
function<void(item &)> setByName = [](item &a)
{ a.setComparison(compareByName); };

function<bool(item &, item &)> cmp = [](item &x, item &y)
{ return x < y; };  
int main() {
    BinarySearchTree bst;
    Heap<item> heap;
    AVL<int> tree;

int choice, structureChoice;
    string name, category;
    float price;

    while (true) {
        cout << "=== Main Menu ===" << endl;
        cout << "Choose the data structure:" << endl;
        cout << "1. Binary Search Tree (BST)" << endl;
        cout << "2. Heap" << endl;
        cout << "3. Exit" << endl;
        cout << "4 avl " << endl;
        cout << "Enter your choice: ";
        cin >> structureChoice;

        if (structureChoice == 1) {
            while (true) {
                cout << "=== BST Menu ===" << endl;
                cout << "1. Add item" << endl;
                cout << "2. Remove item by name" << endl;
                cout << "3. Remove item by price" << endl;
                cout << "4. Display items sorted by name (ascending)" << endl;
                cout << "5. Display items sorted by name (descending)" << endl;
                cout << "6. Display items sorted by price (ascending)" << endl;
                cout << "7. Display items sorted by price (descending)" << endl;
                cout << "8. Search for an item by name" << endl;
                cout << "9. Return to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "Enter item details:" << endl;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Category: ";
                    cin >> category;
                    cout << "Price: ";
                    cin >> price;
                    bst.insert(item(name, category, price));
                    cout << "Item added successfully!" << endl;
                } else if (choice == 2) {
                    cout << "Enter the name of the item to remove: ";
                    cin >> name;
                    bst.remove(item(name, "", 0)); 
                    cout << "Item removed successfully!" << endl;
                } else if (choice == 3) {
                    cout << "Enter the price of the item to remove: ";
                    cin >> price;
                    bst.remove(item("", "", price)); 
                    cout << "Item removed successfully!" << endl;
                } else if (choice == 4) {
                    cout << "Items sorted by name (ascending):" << endl;
                    bst.displayBySmallerName();
                } else if (choice == 5) {
                    cout << "Items sorted by name (descending):" << endl;
                    bst.displayByGreaterName();
                } else if (choice == 6) {
                    cout << "Items sorted by price (ascending):" << endl;
                    bst.displayBySmallerPrice();
                } else if (choice == 7) {
                    cout << "Items sorted by price (descending):" << endl;
                    bst.displayByGreaterPrice();
                } else if (choice == 8) {
                    cout << "Enter the name of the item to search: ";
                    cin >> name;
                    bst.displayItem(name);
                } else if (choice == 9) {
                    break; // Return to main menu
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        } else if (structureChoice == 2) {
            while (true) {
                cout << "=== Heap Menu ===" << endl;
                cout << "1. Add item" << endl;
                cout << "2. Remove root item" << endl;
                cout << "3. Display items sorted by name (ascending)" << endl;
                cout << "4. Display items sorted by price (ascending)" << endl;
                cout << "5. Return to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "Enter item details:" << endl;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Category: ";
                    cin >> category;
                    cout << "Price: ";
                    cin >> price;
                    heap.insert(item(name, category, price));
                    cout << "Item added successfully!" << endl;
                } else if (choice == 2) {
                    if (heap.isEmpty()) {
                        cout << "Heap is empty. Cannot remove item." << endl;
                    } else {
                        item removedItem = heap.remove();
                        cout << "Removed item: " << removedItem.getName() << endl;
                    }
                } else if (choice == 3) {
                    cout << "Items sorted by name (ascending):" << endl;
                    heap.displayHeap(setByName,1);
                } else if (choice == 4) {
                    cout << "Items sorted by price (ascending):" << endl;
                    heap.displayHeap(setByPrice,1);
                } else if (choice == 5) {
                    break; // Return to main menu
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        } else if (structureChoice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
            break; // Exit the loop and the program
        } 
        else if(structureChoice ==4) {
            while (true) {
                cout << "=== avlMenu ===" << endl;
                cout << "1. Add item" << endl;
                cout << "2. inoderder" << endl;
                cout << "5 exit";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    cout <<  " please enter the number:";
                    int x;
                    cin >>x;
    tree.insert(x);
                } else if (choice == 2) {
                    tree.inorder(tree.getRoot());
                }  else if (choice == 5) {
                    break; // Return to main menu
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            
        }
        
    }

    return 0;
}
