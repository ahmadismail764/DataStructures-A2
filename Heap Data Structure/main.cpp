#include "Heap.cpp"

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
        defaultHeap.insert(itm);

    // Default constructor usage
    cout << "Heap sorted by price in descending order:\n";

    // Constructor that takes an array
    Heap<item> arrayHeap(items.data(), items.size());
    cout << "Heap sorted by price in descending order:\n";

    // Switch comparison function to compare by name
    cout << "Heap after switching comparison to name (sorted by name):\n";

    // Add a new item
    item newItem("Eclair", "Dessert", 2.0);
    arrayHeap.insert(newItem);
    cout << "Heap after adding new item (Eclair):\n";
    arrayHeap.displayHeap(setByPrice);
}