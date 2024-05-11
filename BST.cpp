#include "BST.hpp"
using namespace std;

BST::BST(){}

BST::BST(bool (*cmp)(const item &, const item &)){
    
}

BST::~BST(){this->clear();}

void BST::insert(item val){
    ++numOfNodes;
    Node *nNode = new Node(val);
    if (root == nullptr)
        return void(root = nNode);
    Node *temp = root,*prv = nullptr;
    while(temp){
        prv = temp;
        if (temp->data == val)
            return;
        if (val < temp->data)
            temp = temp->left;
        else 
            temp = temp->right;
    }
    if (val < prv->data)
        prv -> left = nNode;
    else 
        prv -> right = nNode;
    nNode->parent = prv;
}

bool BST::find(item val) const{
    Node *temp = root;
    while(temp)
        if (temp->data == val)
            return true;
        else if (val > temp->data)
            temp = temp->right;
        else 
            temp = temp->left;
    return false;
}

void BST::remove(item val){
    if (root == nullptr)
        return ;
    Node *temp = root,*prv = nullptr;
    --numOfNodes;
    while(temp)
        if (temp->data == val)
            if (temp->left && temp->right)
                return removeWithTwoChildren(temp);
            else
                return remove(temp);
        else if (val < temp->data)
            temp = temp->left;
        else 
            temp = temp->right;
    return;
}

void BST::remove(Node* temp){
    if (temp->parent->right == temp)
        if (temp->right)
            temp->parent->right = temp->right;
        else if (temp->left)
            temp->parent->right = temp->left;
        else 
            temp->parent->right = nullptr;
    else
        if (temp->left)
            temp->parent->left = temp->left;
        else if (temp->right)
            temp->parent->left = temp->right;
        else 
            temp->parent->left = nullptr;
    delete temp;
    return;
}

void BST::removeWithTwoChildren(Node* temp){
    Node* min = getMin(temp->right);
    temp->data = min->data;
    return remove(min);
}

typename BST::template Node* BST::getMin(Node* temp){
    Node* start = temp;
    while(start->left)
        start = start->left;
    return start;
}

typename BST::template Node* BST::getMax(Node* temp){
    Node* start = temp;
    while(start->right)
        start = start->right;
    return start;
}

int BST::size() const{
    return numOfNodes;
}

void BST::clear(){
    if (root == nullptr)
        return;
    queue <Node*> q;
    q.emplace(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if (temp->right) 
            q.emplace(temp->right);
        if (temp->left)
            q.emplace(temp->left);
        delete temp;
    }
    root = nullptr;
    numOfNodes = 0;
    return;
}

int BST::height(Node* temp) const{
    if (temp == nullptr)
        return 0;
    return 1 + max(height(temp->right),height(temp->left));
}

int BST::height() const {
    return height(root);
}

void BST::inOrderTraversal(Node * temp) const{
    if (temp == nullptr)
        return;
    inOrderTraversal(temp->left);
    cout << temp->data << ' ';
    inOrderTraversal(temp->right);
}

void BST::inReversedOrderTraversal(Node * temp) const{
    if (temp == nullptr)
        return;
    inOrderTraversal(temp->right);
    cout << temp->data << ' ';
    inOrderTraversal(temp->left);
}

void BST::preOrderTraversal(Node * temp) const{
    if (temp == nullptr)
        return;
    cout << temp->data << ' ';
    preOrderTraversal(temp->left);
    preOrderTraversal(temp->right);
}

void BST::postOrderTraversal(Node * temp) const{
    if (temp == nullptr)
        return;
    postOrderTraversal(temp->left);
    postOrderTraversal(temp->right);
    cout << temp->data << ' ';
}

void BST::inOrderTraversal() const{
    return inOrderTraversal(root);
}

void BST::inReversedOrderTraversal() const{
    return inReversedOrderTraversal(root);
}

void BST::preOrderTraversal() const{
    return preOrderTraversal(root);
}

void BST::postOrderTraversal() const{
    return postOrderTraversal(root);
}

void BST::breadthFirstTraversal() const{
    if (root == nullptr)
        return;
    queue<Node*>q;
    q.emplace(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << ' ';
        if (temp->left)
            q.emplace(temp->left);
        if (temp->right)
            q.emplace(temp->right);
    }
}