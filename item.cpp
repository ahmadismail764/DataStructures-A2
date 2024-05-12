#include <bits/stdc++.h>
using namespace std;

class item {
private:
    string itemName;
    string category;
    int price;
    function <bool(item&,item&)> comparison;
public:
    item(){}
    void setComparison(function <bool(item&, item&)> comparison){
        this->comparison = comparison;
    }
    bool operator<(item& item){
        return comparison(*this,item);
    }
    bool operator==(item& item){
        return (this->category == item.category && this->itemName == item.itemName && this->price == item.price);
    }
    item(string name, string category, int price):itemName(name),category(category),price(price){}
    string getName(){return this->itemName;}
    int getPrice(){return this->price;}
    // void print() {
    //     cout << "Item name: " << itemName << '\n'
    //     << "Category: " << category << '\n'
    //     << "Price: " << price << '\n';
    // }
    friend ostream& operator<< (ostream& os,const item& item){
        os << "Item name: " << item.itemName << '\n'
        << "Category: " << item.category << '\n'
        << "Price: " << item.price << '\n';
        return os;
    }
};
