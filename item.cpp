#include <bits/stdc++.h>
using namespace std;

class item {
private:
    string itemName;
    string category;
    int price;
public:
    item(string name, string category, int price):itemName(name),category(category),price(price){}
    bool operator<(const item&);
    // void print() {
    //     cout << "Item name: " << itemName << '\n'
    //     << "Category: " << category << '\n'
    //     << "Price: " << price << '\n';
    // }
    friend ostream& operator<< (const item& item,ostream& os){
        os << "Item name: " << item.itemName << '\n'
        << "Category: " << item.category << '\n'
        << "Price: " << item.price << '\n';
        return os;
    }
};