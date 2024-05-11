#include <bits/stdc++.h>
#include "item.cpp"
using namespace std;

class BST
{
private:
    class Node{
    public:
        item data;
        Node *left = nullptr,*right = nullptr,*parent = nullptr;
        Node(item data):data(data){}
    };
    Node* root = nullptr;
    int numOfNodes = 0;
    Node* getMin(Node *temp);
    Node* getMax(Node *max);
    void remove(Node* temp);
    void removeWithTwoChildren(Node * temp);
    int height(Node* temp) const;
    void inOrderTraversal(Node* temp) const;
    void inReversedOrderTraversal(Node* temp) const;
    void preOrderTraversal(Node* temp) const;
    void postOrderTraversal(Node* temp) const;
    
public:
    BST();
    BST(bool (*cmp)(const T &, const T &));
    ~BST();
    void insert(item val);
    void remove(item val);
    bool find(item val) const;
    // void print();
    void clear();
    int size() const;
    int height() const;
    void inOrderTraversal() const;
    void inReversedOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    void breadthFirstTraversal() const;
};