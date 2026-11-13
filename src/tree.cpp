#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include "tree.h"

using namespace std;

Tree::Tree()
    : bstRoot(nullptr), bRoot(nullptr), bPlusRoot(nullptr)
{
}

Tree::~Tree()
{
    deleteTree();
    bDeleteTree();
    bPlusDeleteTree();
}

// Insert Helper

Tree::Node* Tree::insertHelper(Node* node, int value)

{

    if (node == nullptr)
        return new Node(value);
    if (value < node->data)
        node->left = insertHelper(node->left, value);
    else if (value > node->data)
        node->right = insertHelper(node->right, value);
    else
        cout << "Duplicate values are not inserted!\n";
    return node;

}



// Insert Node

void Tree::insertNode(int value)

{
    Node* current = bstRoot;
    while (current != nullptr)
    {
        if (value == current->data)

        {

            cout << "Duplicate values are not inserted!\n";

            return;

        }



        if (value < current->data)

            current = current->left;

        else

            current = current->right;

    }



    bstRoot = insertHelper(bstRoot, value);

}



// Display Helper (Tree Structure)

void Tree::displayHelper(Node* node, int space) const

{

    if (node == nullptr)

        return;



    space += 5;



    displayHelper(node->right, space);



    cout << endl;



    for (int i = 5; i < space; i++)

        cout << " ";



    cout << node->data << endl;



    displayHelper(node->left, space);

}



// Display Tree

void Tree::displayTree() const

{

    if (bstRoot == nullptr)

    {

        cout << "Tree is empty!\n";

        return;

    }



    cout << "\nTree Structure:\n";

    displayHelper(bstRoot, 0);

}



// Inorder Helper

void Tree::inorderHelper(Node* node) const

{

    if (node == nullptr)

        return;



    inorderHelper(node->left);

    cout << node->data << " ";

    inorderHelper(node->right);

}



// Inorder Traversal

void Tree::inorder() const

{

    if (bstRoot == nullptr)

    {

        cout << "Tree is empty!\n";

        return;

    }



    cout << "Inorder Traversal: ";

    inorderHelper(bstRoot);

    cout << endl;

}

void Tree::preorderHelper(Node* node) const

{

    if (node == nullptr)

        return;



    cout << node->data << " ";

    preorderHelper(node->left);

    preorderHelper(node->right);

}



void Tree::preorder() const

{

    if (bstRoot == nullptr)

    {

        cout << "Tree is empty!\n";

        return;

    }



    cout << "Preorder Traversal: ";

    preorderHelper(bstRoot);

    cout << endl;

}

void Tree::postorderHelper(Node* node) const

{
    if (node == nullptr)
        return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << node->data << " ";
}



// Postorder Traversal

void Tree::postorder() const

{

    if (bstRoot == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "Postorder Traversal: ";
    postorderHelper(bstRoot);
    cout << endl;
}



// Breadth First Search

void Tree::BFS() const
{
    if (bstRoot == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }



    queue<Node*> q;
    q.push(bstRoot);
    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    cout << endl;
}



// DFS Helper

void Tree::DFSHelper(Node* node) const

{

    if (node == nullptr)

        return;



    cout << node->data << " ";



    DFSHelper(node->left);

    DFSHelper(node->right);

}



// Depth First Search

void Tree::DFS() const

{

    if (bstRoot == nullptr)

    {

        cout << "Tree is empty!\n";

        return;

    }



    cout << "DFS Traversal (Preorder): ";

    DFSHelper(bstRoot);

    cout << endl;

}



// Check Complete Binary Tree

bool Tree::checkCompleteTree() const

{

    if (bstRoot == nullptr)

        return true;



    queue<Node*> q;

    q.push(bstRoot);



    bool nullFound = false;



    while (!q.empty())

    {

        Node* current = q.front();

        q.pop();



        if (current->left != nullptr)

        {

            if (nullFound)

                return false;



            q.push(current->left);

        }

        else

            nullFound = true;



        if (current->right != nullptr)

        {

            if (nullFound)

                return false;



            q.push(current->right);

        }

        else

            nullFound = true;

    }



    return true;

}



// Count Nodes Helper

int Tree::countNodesHelper(Node* node) const

{

    if (node == nullptr)

        return 0;



    return 1 + countNodesHelper(node->left)

             + countNodesHelper(node->right);

}





int Tree::countNodes() const

{

    return countNodesHelper(bstRoot);

}

int Tree::countLeafNodesHelper(Node* node) const

{

    if (node == nullptr)

        return 0;



    if (node->left == nullptr && node->right == nullptr)

        return 1;



    return countLeafNodesHelper(node->left)

         + countLeafNodesHelper(node->right);

}



// Count Leaf Nodes

int Tree::countLeafNodes() const

{

    return countLeafNodesHelper(bstRoot);

}



// Find Highest Node

bool Tree::findHighest(int& answer) const

{

    if (bstRoot == nullptr)

        return false;



    Node* current = bstRoot;



    while (current->right != nullptr)

        current = current->right;



    answer = current->data;



    return true;

}



// Find Second Highest Node

bool Tree::findSecondHighest(int& answer) const

{

    if (bstRoot == nullptr)

        return false;



    Node* current = bstRoot;

    Node* parent = nullptr;



    while (current->right != nullptr)

    {

        parent = current;

        current = current->right;

    }



    if (current->left != nullptr)

    {

        current = current->left;



        while (current->right != nullptr)

            current = current->right;



        answer = current->data;

        return true;

    }



    if (parent != nullptr)

    {

        answer = parent->data;

        return true;

    }



    return false;

}



// Display Nodes Having Common Parent

void Tree::displayCommonParentHelper(Node* node) const

{

    if (node == nullptr)

        return;



    if (node->left != nullptr && node->right != nullptr)

    {

        cout << node->left->data << " and "

             << node->right->data

             << " have common parent " << node->data << endl;

    }



    displayCommonParentHelper(node->left);

    displayCommonParentHelper(node->right);

}



// Display Common Parent Nodes

void Tree::displayCommonParentNodes() const

{

    if (bstRoot == nullptr)

    {

        cout << "Tree is empty!\n";

        return;

    }



    cout << "Nodes having a common parent:\n";

    displayCommonParentHelper(bstRoot);

}



// Count Nodes Having a Sibling

int Tree::countNodesWithSiblingHelper(Node* node) const

{

    if (node == nullptr)

        return 0;



    if (node->left != nullptr && node->right != nullptr)

    {

        return 2

             + countNodesWithSiblingHelper(node->left)

             + countNodesWithSiblingHelper(node->right);

    }



    return countNodesWithSiblingHelper(node->left)

         + countNodesWithSiblingHelper(node->right);

}



// Count Nodes Having Common Parent

int Tree::countNodesWithSibling() const

{

    return countNodesWithSiblingHelper(bstRoot);

}



// Height Helper

int Tree::heightHelper(Node* node) const

{

    if (node == nullptr)

        return 0;



    int leftHeight = heightHelper(node->left);

    int rightHeight = heightHelper(node->right);



    return 1 + max(leftHeight, rightHeight);

}



// Height of Tree

int Tree::height() const

{

    return heightHelper(bstRoot);

}



// Count Nodes Having Only Left Child

int Tree::countOnlyLeftChildHelper(Node* node) const

{

    if (node == nullptr)

        return 0;



    if (node->left != nullptr && node->right == nullptr)

    {

        return 1

             + countOnlyLeftChildHelper(node->left)

             + countOnlyLeftChildHelper(node->right);

    }



    return countOnlyLeftChildHelper(node->left)

         + countOnlyLeftChildHelper(node->right);

}



// Count Only Left Child Nodes

int Tree::countOnlyLeftChild() const

{

    return countOnlyLeftChildHelper(bstRoot);

}



// Search Node

void Tree::searchNode(int value) const

{

    Node* current = bstRoot;



    while (current != nullptr)

    {

        if (current->data == value)

        {

            cout << "Node found!\n";

            return;

        }



        if (value < current->data)

            current = current->left;

        else

            current = current->right;

    }



    cout << "Node not found!\n";

}



// Delete Tree Helper

void Tree::deleteTreeHelper(Node* node)

{

    if (node == nullptr)

        return;



    deleteTreeHelper(node->left);

    deleteTreeHelper(node->right);



    delete node;

}



// Delete Complete Tree

void Tree::deleteTree()

{

    deleteTreeHelper(bstRoot);

    bstRoot = nullptr;

}



// ====================================================================

//                NEW: BST helpers and delete functions

// ====================================================================



// Collect values in sorted order

void Tree::collectInorder(Node* node, vector<int>& out) const

{

    if (node == nullptr)

        return;



    collectInorder(node->left, out);

    out.push_back(node->data);

    collectInorder(node->right, out);

}



// All values of the tree as a sorted vector

vector<int> Tree::toVector() const

{

    vector<int> values;

    collectInorder(bstRoot, values);

    return values;

}



// Find a node by value (nullptr if missing)

Tree::Node* Tree::findNode(int value) const

{

    Node* current = bstRoot;



    while (current != nullptr && current->data != value)

    {

        if (value < current->data)

            current = current->left;

        else

            current = current->right;

    }



    return current;

}



// Smallest node of a subtree

Tree::Node* Tree::minNode(Node* node) const

{

    while (node != nullptr && node->left != nullptr)

        node = node->left;



    return node;

}



// Delete one node by value (handles leaf, one child, two children)

Tree::Node* Tree::deleteNodeHelper(Node* node, int value, bool& found)

{

    if (node == nullptr)

        return nullptr;



    if (value < node->data)

        node->left = deleteNodeHelper(node->left, value, found);



    else if (value > node->data)

        node->right = deleteNodeHelper(node->right, value, found);



    else

    {

        found = true;



        // No child or only right child

        if (node->left == nullptr)

        {

            Node* temp = node->right;

            delete node;

            return temp;

        }



        // Only left child

        if (node->right == nullptr)

        {

            Node* temp = node->left;

            delete node;

            return temp;

        }



        // Two children: replace with inorder successor

        Node* successor = minNode(node->right);

        node->data = successor->data;

        node->right = deleteNodeHelper(node->right, successor->data, found);

    }



    return node;

}



void Tree::deleteNode(int value)

{

    if (bstRoot == nullptr)

    {

        cout << "Tree is empty!\n";

        return;

    }



    bool found = false;

    bstRoot = deleteNodeHelper(bstRoot, value, found);



    if (found)

        cout << "Node " << value << " deleted successfully!\n";

    else

        cout << "Node not found!\n";

}



// Delete the left child of a node, together with everything below it

void Tree::deleteLeftSubtree(int value)

{

    Node* target = findNode(value);



    if (target == nullptr)

    {

        cout << "Node not found!\n";

        return;

    }



    if (target->left == nullptr)

    {

        cout << "Node " << value << " has no left child!\n";

        return;

    }



    int removed = countNodesHelper(target->left);

    deleteTreeHelper(target->left);

    target->left = nullptr;



    cout << "Left subtree of " << value << " deleted ("

         << removed << " node(s) removed).\n";

}



// Delete the right child of a node, together with everything below it

void Tree::deleteRightSubtree(int value)

{

    Node* target = findNode(value);



    if (target == nullptr)

    {

        cout << "Node not found!\n";

        return;

    }



    if (target->right == nullptr)

    {

        cout << "Node " << value << " has no right child!\n";

        return;

    }



    int removed = countNodesHelper(target->right);

    deleteTreeHelper(target->right);

    target->right = nullptr;



    cout << "Right subtree of " << value << " deleted ("

         << removed << " node(s) removed).\n";

}



// Delete every leaf node

Tree::Node* Tree::deleteLeafHelper(Node* node, int& count)

{

    if (node == nullptr)

        return nullptr;



    if (node->left == nullptr && node->right == nullptr)

    {

        delete node;

        count++;

        return nullptr;

    }



    node->left = deleteLeafHelper(node->left, count);

    node->right = deleteLeafHelper(node->right, count);



    return node;

}



void Tree::deleteLeafNodes()

{

    if (bstRoot == nullptr)

    {

        cout << "Tree is empty!\n";

        return;

    }



    int count = 0;

    bstRoot = deleteLeafHelper(bstRoot, count);



    cout << count << " leaf node(s) deleted successfully!\n";

}




// ====================================================================

//                              AVL TREE

// ====================================================================



int Tree::getHeight(Node* node) const

{

    return node == nullptr ? 0 : node->height;

}



int Tree::balanceFactor(Node* node) const

{

    return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);

}



void Tree::updateHeight(Node* node)

{

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

}



Tree::Node* Tree::rotateRight(Node* y)

{

    Node* x = y->left;

    Node* t2 = x->right;



    x->right = y;

    y->left = t2;



    updateHeight(y);

    updateHeight(x);



    return x;

}



Tree::Node* Tree::rotateLeft(Node* x)

{

    Node* y = x->right;

    Node* t2 = y->left;



    y->left = x;

    x->right = t2;



    updateHeight(x);

    updateHeight(y);



    return y;

}



Tree::Node* Tree::avlInsertHelper(Node* node, int value)

{

    if (node == nullptr)

        return new Node(value);



    if (value < node->data)

        node->left = avlInsertHelper(node->left, value);

    else if (value > node->data)

        node->right = avlInsertHelper(node->right, value);

    else

        return node;   // duplicates ignored



    updateHeight(node);



    int balance = balanceFactor(node);



    // Left Left

    if (balance > 1 && value < node->left->data)

        return rotateRight(node);



    // Right Right

    if (balance < -1 && value > node->right->data)

        return rotateLeft(node);



    // Left Right

    if (balance > 1 && value > node->left->data)

    {

        node->left = rotateLeft(node->left);

        return rotateRight(node);

    }



    // Right Left

    if (balance < -1 && value < node->right->data)

    {

        node->right = rotateRight(node->right);

        return rotateLeft(node);

    }



    return node;

}



void Tree::convertToAVL()
{
    vector<int> values;
    collectInorder(bstRoot, values);

    deleteTreeHelper(bstRoot);
    bstRoot = nullptr;

    for (int value : values)
        bstRoot = avlInsertHelper(bstRoot, value);
}

void Tree::avlInsertNode(int value)
{
    vector<int> values;
    collectInorder(bstRoot, values);

    if (find(values.begin(), values.end(), value) != values.end())
    {
        cout << "Duplicate values are not inserted!\n";
        return;
    }

    // First balance all existing BST values, then insert the new value.
    convertToAVL();
    bstRoot = avlInsertHelper(bstRoot, value);
}



void Tree::avlDisplayHelper(Node* node, int space) const

{

    if (node == nullptr)

        return;



    space += 5;



    avlDisplayHelper(node->right, space);



    cout << endl;



    for (int i = 5; i < space; i++)

        cout << " ";



    cout << node->data << endl;



    avlDisplayHelper(node->left, space);

}



void Tree::avlDisplayTree() const

{

    if (bstRoot == nullptr)

    {

        cout << "AVL Tree is empty!\n";

        return;

    }



    cout << "\nAVL Tree Structure:\n";

    avlDisplayHelper(bstRoot, 0);

}



void Tree::avlInorderHelper(Node* node) const

{

    if (node == nullptr)

        return;



    avlInorderHelper(node->left);

    cout << node->data << " ";

    avlInorderHelper(node->right);

}



void Tree::avlInorder() const

{

    cout << "AVL Inorder Traversal: ";

    avlInorderHelper(bstRoot);

    cout << endl;

}



int Tree::avlHeight() const

{

    return getHeight(bstRoot);

}



void Tree::avlDeleteTreeHelper(Node* node)

{

    if (node == nullptr)

        return;



    avlDeleteTreeHelper(node->left);

    avlDeleteTreeHelper(node->right);



    delete node;

}



void Tree::avlDeleteTree()

{

    avlDeleteTreeHelper(bstRoot);

    bstRoot = nullptr;

}




// ====================================================================

//                               B-TREE

// ====================================================================



// Split the full child parent->children[i] into two nodes

void Tree::splitChild(Node* parent, int i)

{

    Node* y = parent->children[i];

    Node* z = new Node(y->isLeaf);



    int median = y->keys[B_TREE_T - 1];



    z->keys.assign(y->keys.begin() + B_TREE_T, y->keys.end());



    if (!y->isLeaf)

    {

        z->children.assign(y->children.begin() + B_TREE_T, y->children.end());

        y->children.resize(B_TREE_T);

    }



    y->keys.resize(B_TREE_T - 1);



    parent->keys.insert(parent->keys.begin() + i, median);

    parent->children.insert(parent->children.begin() + i + 1, z);

}



void Tree::insertNonFull(Node* node, int value)

{

    int i = static_cast<int>(node->keys.size()) - 1;



    if (node->isLeaf)

    {

        node->keys.push_back(value);



        while (i >= 0 && node->keys[i] > value)

        {

            node->keys[i + 1] = node->keys[i];

            i--;

        }



        node->keys[i + 1] = value;

        return;

    }



    while (i >= 0 && node->keys[i] > value)

        i--;

    i++;



    if (static_cast<int>(node->children[i]->keys.size()) == 2 * B_TREE_T - 1)

    {

        splitChild(node, i);



        if (value > node->keys[i])

            i++;

    }



    insertNonFull(node->children[i], value);

}



void Tree::bInsertNode(int value)

{

    if (bRoot == nullptr)

    {

        bRoot = new Node(true);

        bRoot->keys.push_back(value);

        return;

    }



    if (static_cast<int>(bRoot->keys.size()) == 2 * B_TREE_T - 1)

    {

        Node* newRoot = new Node(false);

        newRoot->children.push_back(bRoot);

        splitChild(newRoot, 0);

        bRoot = newRoot;

    }



    insertNonFull(bRoot, value);

}



void Tree::bDisplayHelper(Node* node, int level) const

{

    if (node == nullptr)

        return;



    for (int i = 0; i < level * 6; i++)

        cout << " ";



    cout << "[";

    for (size_t i = 0; i < node->keys.size(); i++)

    {

        if (i > 0)

            cout << " | ";

        cout << node->keys[i];

    }

    cout << "]" << endl;



    if (!node->isLeaf)

    {

        for (size_t i = 0; i < node->children.size(); i++)

            bDisplayHelper(node->children[i], level + 1);

    }

}



void Tree::bDisplayTree() const

{

    if (bRoot == nullptr)

    {

        cout << "B-Tree is empty!\n";

        return;

    }



    cout << "\nB-Tree Structure (min degree " << B_TREE_T << "):\n";

    bDisplayHelper(bRoot, 0);

}



void Tree::bInorderHelper(Node* node) const

{

    if (node == nullptr)

        return;



    for (size_t i = 0; i < node->keys.size(); i++)

    {

        if (!node->isLeaf)

            bInorderHelper(node->children[i]);



        cout << node->keys[i] << " ";

    }



    if (!node->isLeaf)

        bInorderHelper(node->children[node->keys.size()]);

}



void Tree::bInorder() const

{

    cout << "B-Tree Inorder Traversal: ";

    bInorderHelper(bRoot);

    cout << endl;

}



int Tree::bHeight() const

{

    int h = 0;

    Node* current = bRoot;



    while (current != nullptr)

    {

        h++;

        if (current->isLeaf)

            break;

        current = current->children[0];

    }



    return h;

}



void Tree::bDeleteTreeHelper(Node* node)

{

    if (node == nullptr)

        return;



    if (!node->isLeaf)

    {

        for (size_t i = 0; i < node->children.size(); i++)

            bDeleteTreeHelper(node->children[i]);

    }



    delete node;   // vectors free their own memory

}



void Tree::bDeleteTree()

{

    bDeleteTreeHelper(bRoot);

    bRoot = nullptr;

}




// ====================================================================

//                              B+ TREE

// ====================================================================



// Returns true if 'node' was split; then upKey/newChild describe the new sibling

bool Tree::bPlusInsertHelper(Node* node, int value, int& upKey, Node*& newChild)

{

    if (node->isLeaf)

    {

        vector<int>::iterator pos = lower_bound(node->keys.begin(), node->keys.end(), value);



        if (pos != node->keys.end() && *pos == value)

            return false;   // duplicate



        node->keys.insert(pos, value);



        if ((int)node->keys.size() <= BPLUS_MAX_KEYS)

            return false;



        int mid = (int)node->keys.size() / 2;



        Node* sibling = new Node(true);

        sibling->keys.assign(node->keys.begin() + mid, node->keys.end());

        node->keys.resize(mid);



        sibling->next = node->next;

        node->next = sibling;



        upKey = sibling->keys[0];   // B+ tree: key is copied up, stays in the leaf

        newChild = sibling;

        return true;

    }



    int i = upper_bound(node->keys.begin(), node->keys.end(), value) - node->keys.begin();



    int childUp = 0;

    Node* childNew = nullptr;



    if (!bPlusInsertHelper(node->children[i], value, childUp, childNew))

        return false;



    node->keys.insert(node->keys.begin() + i, childUp);

    node->children.insert(node->children.begin() + i + 1, childNew);



    if ((int)node->keys.size() <= BPLUS_MAX_KEYS)

        return false;



    int mid = (int)node->keys.size() / 2;



    Node* sibling = new Node(false);

    sibling->keys.assign(node->keys.begin() + mid + 1, node->keys.end());

    sibling->children.assign(node->children.begin() + mid + 1, node->children.end());



    upKey = node->keys[mid];   // internal split: key is moved up



    node->keys.resize(mid);

    node->children.resize(mid + 1);



    newChild = sibling;

    return true;

}



void Tree::bPlusInsertNode(int value)

{

    if (bPlusRoot == nullptr)

    {

        bPlusRoot = new Node(true);

        bPlusRoot->keys.push_back(value);

        return;

    }



    int upKey = 0;

    Node* newChild = nullptr;



    if (bPlusInsertHelper(bPlusRoot, value, upKey, newChild))

    {

        Node* newRoot = new Node(false);

        newRoot->keys.push_back(upKey);

        newRoot->children.push_back(bPlusRoot);

        newRoot->children.push_back(newChild);

        bPlusRoot = newRoot;

    }

}



void Tree::bPlusDisplayHelper(Node* node, int level) const

{

    if (node == nullptr)

        return;



    for (int i = 0; i < level * 6; i++)

        cout << " ";



    cout << (node->isLeaf ? "(leaf) [" : "[");

    for (size_t i = 0; i < node->keys.size(); i++)

    {

        if (i > 0)

            cout << " | ";

        cout << node->keys[i];

    }

    cout << "]" << endl;



    if (!node->isLeaf)
    {
        for (size_t i = 0; i < node->children.size(); i++)
            bPlusDisplayHelper(node->children[i], level + 1);
    }

}

void Tree::bPlusDisplayTree() const
{

    if (bPlusRoot == nullptr)
    {
        cout << "B+ Tree is empty!\n";
        return;
    }



    cout << "\nB+ Tree Structure (max " << BPLUS_MAX_KEYS << " keys per node):\n";

    bPlusDisplayHelper(bPlusRoot, 0);

}



// Walk the leaf chain (this is what makes B+ trees good for range scans)

void Tree::bPlusDisplayLeaves() const

{

    if (bPlusRoot == nullptr)

        return;



    Node* current = bPlusRoot;



    while (!current->isLeaf)

        current = current->children[0];



    cout << "Leaf chain: ";



    while (current != nullptr)

    {

        cout << "[";

        for (size_t i = 0; i < current->keys.size(); i++)

        {

            if (i > 0)

                cout << " ";

            cout << current->keys[i];

        }

        cout << "]";



        if (current->next != nullptr)

            cout << " -> ";



        current = current->next;

    }



    cout << endl;

}



int Tree::bPlusHeight() const

{

    int h = 0;

    Node* current = bPlusRoot;



    while (current != nullptr)

    {

        h++;

        if (current->isLeaf)

            break;

        current = current->children[0];

    }



    return h;

}



// Do NOT follow 'next' here, or leaves would be deleted twice

void Tree::bPlusDeleteTreeHelper(Node* node)

{

    if (node == nullptr)

        return;



    if (!node->isLeaf)

    {

        for (size_t i = 0; i < node->children.size(); i++)

            bPlusDeleteTreeHelper(node->children[i]);

    }



    delete node;

}



void Tree::bPlusDeleteTree()

{

    bPlusDeleteTreeHelper(bPlusRoot);

    bPlusRoot = nullptr;

}




void operateTree()
{
    Tree tree;
    int mainChoice, choice, value, answer;

    do
    {
        cout << "\n========== TREE MENU ==========\n";
        cout << "1. Binary Search Tree (BST)\n";
        cout << "2. AVL Tree\n";
        cout << "3. B-Tree\n";
        cout << "4. B+ Tree\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1)
        {
            do
            {
                cout << "\n----- BST MENU -----\n"
                     << "1. Insert Node\n2. Display Tree\n3. Inorder\n4. Preorder\n5. Postorder\n"
                     << "6. BFS\n7. DFS\n8. Check Complete Tree\n9. Count Nodes\n"
                     << "10. Highest\n11. Second Highest\n12. Common Parent Nodes\n"
                     << "13. Count Nodes Having Sibling\n14. Count Leaf Nodes\n15. Height\n"
                     << "16. Count Only-Left-Child Nodes\n17. Search\n18. Delete Entire BST\n"
                     << "19. Delete Node\n20. Delete Left Subtree\n21. Delete Right Subtree\n"
                     << "22. Delete All Leaves\n0. Back\nChoice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1: 
                    cout << "Enter value: "; 
                    cin >> value; 
                    tree.insertNode(value); 
                    break;
                    case 2: 
                    tree.displayTree(); 
                    break;
                    case 3: 
                    tree.inorder(); 
                    break;
                    case 4: 
                    tree.preorder(); 
                    break;
                    case 5: 
                    tree.postorder(); 
                    break;
                    case 6: tree.BFS(); break;
                    case 7: tree.DFS(); break;
                    case 8: cout << (tree.checkCompleteTree() ? "Complete Binary Tree\n" : "Not a Complete Binary Tree\n"); break;
                    case 9: cout << "Total nodes = " << tree.countNodes() << endl; break;
                    case 10: if (tree.findHighest(answer)) cout << "Highest = " << answer << endl; else cout << "Tree is empty!\n"; break;
                    case 11: if (tree.findSecondHighest(answer)) cout << "Second highest = " << answer << endl; else cout << "Second highest does not exist!\n"; break;
                    case 12: tree.displayCommonParentNodes(); break;
                    case 13: cout << "Nodes having sibling = " << tree.countNodesWithSibling() << endl; break;
                    case 14: cout << "Leaf nodes = " << tree.countLeafNodes() << endl; break;
                    case 15: cout << "Height = " << tree.height() << endl; break;
                    case 16: cout << "Only-left-child nodes = " << tree.countOnlyLeftChild() << endl; break;
                    case 17: cout << "Enter value to search: "; cin >> value; tree.searchNode(value); break;
                    case 18: tree.deleteTree(); cout << "BST deleted.\n"; break;
                    case 19: cout << "Enter value to delete: "; cin >> value; tree.deleteNode(value); break;
                    case 20: cout << "Enter parent value: "; cin >> value; tree.deleteLeftSubtree(value); break;
                    case 21: cout << "Enter parent value: "; cin >> value; tree.deleteRightSubtree(value); break;
                    case 22: tree.deleteLeafNodes(); break;
                    case 0: break;
                    default: cout << "Invalid choice!\n";
                }
            } while (choice != 0);
        }
        else if (mainChoice == 2)
        {
            do
            {
                cout << "\n----- AVL TREE MENU -----\n1. Insert\n2. Display\n3. Inorder\n4. Height\n5. Delete Entire AVL Tree\n0. Back\nChoice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1: cout << "Enter value: "; cin >> value; tree.avlInsertNode(value); break;
                    case 2: tree.avlDisplayTree(); break;
                    case 3: tree.avlInorder(); break;
                    case 4: cout << "AVL height = " << tree.avlHeight() << endl; break;
                    case 5: tree.avlDeleteTree(); cout << "AVL Tree deleted.\n"; break;
                    case 0: break;
                    default: cout << "Invalid choice!\n";
                }
            } while (choice != 0);
        }
        else if (mainChoice == 3)
        {
            do
            {
                cout << "\n----- B-TREE MENU -----\n1. Insert\n2. Display\n3. Inorder\n4. Height\n5. Delete Entire B-Tree\n0. Back\nChoice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1: cout << "Enter value: "; cin >> value; tree.bInsertNode(value); break;
                    case 2: tree.bDisplayTree(); break;
                    case 3: tree.bInorder(); break;
                    case 4: cout << "B-Tree height = " << tree.bHeight() << endl; break;
                    case 5: tree.bDeleteTree(); cout << "B-Tree deleted.\n"; break;
                    case 0: break;
                    default: cout << "Invalid choice!\n";
                }
            } while (choice != 0);
        }
        else if (mainChoice == 4)
        {
            do
            {
                cout << "\n----- B+ TREE MENU -----\n1. Insert\n2. Display Structure\n3. Display Leaf Chain\n4. Height\n5. Delete Entire B+ Tree\n0. Back\nChoice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1: cout << "Enter value: "; cin >> value; tree.bPlusInsertNode(value); break;
                    case 2: tree.bPlusDisplayTree(); break;
                    case 3: tree.bPlusDisplayLeaves(); break;
                    case 4: cout << "B+ Tree height = " << tree.bPlusHeight() << endl; break;
                    case 5: tree.bPlusDeleteTree(); cout << "B+ Tree deleted.\n"; break;
                    case 0: break;
                    default: cout << "Invalid choice!\n";
                }
            } while (choice != 0);
        }
        else if (mainChoice != 0)
            cout << "Invalid choice!\n";

    } while (mainChoice != 0);
}
