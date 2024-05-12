#include "avlTree.hpp"

AVLTree::AVLTree() { root = nullptr; }

void AVLTree::clearHelper(Node *node)
{
    if (node == nullptr)
        return;
    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
}

void AVLTree::clear()
{
    clearHelper(root);
    root = nullptr;
}

bool AVLTree::isEmpty() { return root == nullptr; }

void AVLTree::visit(Node *node) { cout << node->key << " "; }

int AVLTree::getBalanceFactor(Node *node)
{
    if (node == nullptr)
        return 0;
    return (node->left->height) - (node->right->height);
}

Node *AVLTree::search(int &el)
{
    Node *p = root;
    while (p != 0)
    {
        if (el == p->key)
            return p;
        else if (el < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

// Breadth-First starts here
void AVLTree::breadthFirst()
{
    queue<Node *> queue;
    Node *p = root;
    if (p != 0)
    {
        queue.push(p);
        while (!queue.empty())
        {
            p = queue.front();
            queue.pop();
            visit(p);
            if (p->left != nullptr)
                queue.push(p->left);
            if (p->right != nullptr)
                queue.push(p->right);
        }
    }
}
// Breadth-First ends here

Node *nodeWithMinVal(Node *node)
{
    Node *current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Depth first traversal starts here
void AVLTree::inorder(Node *p)
{
    if (p != 0)
    {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

void AVLTree::preorder(Node *p)
{
    if (p != 0)
    {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

void AVLTree::postorder(Node *p)
{
    if (p != 0)
    {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}
// Depth first traversal starts here

Node *AVLTree::rightRotate(Node *node)
{
    Node *temp = node->left;
    Node *T2 = temp->right;
    temp->right = node;
    node->left = T2;
    node->height = max(node->left->height, node->right->height) + 1;
    temp->height = max(temp->left->height, temp->right->height) + 1;
    return node;
}

Node *AVLTree::leftRotate(Node *node)
{
    Node *temp = node->right;
    Node *T2 = temp->left;
    temp->left = node;
    node->right = T2;
    node->height = max(node->left->height, node->right->height) + 1;
    temp->height = max(temp->left->height, temp->right->height) + 1;
    return temp;
}

Node *AVLTree::insert(Node *node, int key)
{
    if (node == NULL)
        return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    // node->height = 1 + max(node->left->height, node->right->height);
    // int balanceFactor = getBalanceFactor(node);
    // if (balanceFactor > 1)
    // {
    //     if (key < node->left->key)
    //         return rightRotate(node);
    //     else if (key > node->left->key)
    //     {
    //         node->left = leftRotate(node->left);
    //         return rightRotate(node);
    //     }
    // }

    // if (balanceFactor < -1)
    // {
    //     if (key > node->right->key)
    //     {
    //         return leftRotate(node);
    //     }
    //     else if (key < node->right->key)
    //     {
    //         node->right = rightRotate(node->right);
    //         return leftRotate(node);
    //     }
    // }
    cout << "Inserted successfully.\n";
    return node;
}

Node *AVLTree::deleteNode(Node *root, int key)
{
    // Find the node and delete it
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = nodeWithMinVal(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,

                                     temp->key);
        }
    }
    root->height = 1 + max(root->left->height, root->right->height);
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1)
    {
        if (getBalanceFactor(root->left) >= 0)
            return rightRotate(root);
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1)
    {
        if (getBalanceFactor(root->right) <= 0)
            return leftRotate(root);
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

int main()
{
    AVLTree avlTree;
    avlTree.root = new Node(10);
    avlTree.inorder(avlTree.root);
    // avlTree.insert(new Node(20),20);
    // avlTree.root = avlTree.insert(avlTree.root, 20);
    // avlTree.root = avlTree.insert(avlTree.root, 30);
    // avlTree.root = avlTree.insert(avlTree.root, 40);
    // avlTree.root = avlTree.insert(avlTree.root, 50);
    // avlTree.root = avlTree.insert(avlTree.root, 25);

    // // Print the AVL tree in-order
    // cout << "In-order traversal of AVL tree before deletion: ";
    // avlTree.inorder(avlTree.root);
    // cout << endl;

    // Search for an element in the AVL tree
    // int searchKey = 30;
    // Node *searchResult = avlTree.search(searchKey);
    // if (searchResult)
    //     cout << "Element " << searchKey << " found in AVL tree!" << endl;
    // else
    //     cout << "Element " << searchKey << " not found in AVL tree." << endl;

    // // Delete an element from the AVL tree
    // int deleteKey = 40;
    // avlTree.root = avlTree.deleteNode(avlTree.root, deleteKey);

    // // Print the AVL tree in-order after deletion
    // cout << "In-order traversal of AVL tree after deletion: ";
    // avlTree.inorder(avlTree.root);
    // cout << endl;

    return 0;
}
