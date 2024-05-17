#include <bits/stdc++.h>
using namespace std;

class item
{
private:
    string itemName, category;
    float price;
    function<bool(item &, item &)> comparison;

public:
    item() {}
    void setComparison(function<bool(item &, item &)> comparison) { this->comparison = comparison; }
    bool operator<(item &item) { return comparison(*this, item); }
    bool operator==(item &item) { return (this->itemName == item.itemName); }
    item(string name, string category, float price) : itemName(name), category(category), price(price) {}
    string getName() { return this->itemName; }
    int getPrice() { return this->price; }
    friend ostream &operator<<(ostream &os, const item &item)
    {
        os << "Item name: " << item.itemName << '\n'
           << "Category: " << item.category << '\n'
           << "Price: " << item.price << '\n';
        return os;
    }
};
