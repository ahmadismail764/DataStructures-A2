#include "Heap.cpp"
#include <bits/stdc++.h>
using namespace std;
#include "item.cpp"

// Comparison function to compare by price
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
int main()
{
    vector<item> items = {
        item("Apple", "Fruit", 1.2),
        item("Doughnut", "Dessert", 5.9),
        item("Banana", "Fruit", 0.8),
        item("Carrot", "Vegetable", 0.5),
        item("Doughnut", "Dessert", 1.1),

    };
    Heap<item> defaultHeap;
    for (auto &itm : items)
    {
        defaultHeap.insert(itm);
    }
    // Default constructor usage

    cout << "Heap sorted by price in descending order:" << endl;
    // defaultHeap.heapSort(1,setByPrice);
    // defaultHeap.printHeap();

    // Constructor that takes an array
    Heap<item> arrayHeap(items.data(), items.size());
    cout << "Heap sorted by price in descending order:" << endl;
    // arrayHeap.heapSort( true, setByPrice);
    // arrayHeap.printHeap();

    // Switch comparison function to compare by name
    cout << "Heap after switching comparison to name (sorted by name):" << endl;
    // arrayHeap.heapSort(true, setByName);
    // arrayHeap.printHeap();

    // Add a new item
    item newItem("Eclair", "Dessert", 2.0);
    arrayHeap.insert(newItem);

    cout << "Heap after adding new item (Eclair):" << endl;
    // arrayHeap.printHeap();

    arrayHeap.displayHeap(setByPrice);

    // // Remove the root item
    // item removedItem = arrayHeap.remove();
    // cout << "Removed item: " << removedItem.getName() << endl;
    //
    // cout << "Heap after removing root item:" << endl;
    // arrayHeap.printHeap();

    return 0;
}