
#include <iostream>
#include<algorithm>
#include <queue>
#include "tree.h"

using namespace std;

// Constructor
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

// Destructor
BinarySearchTree::~BinarySearchTree()
{
    deleteTree();
}

// Insert Helper
BinarySearchTree::Node* BinarySearchTree::insertHelper(Node* node, int value)
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
void BinarySearchTree::insertNode(int value)
{
    Node* current = root;

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

    root = insertHelper(root, value);
}

// Display Helper (Tree Structure)
void BinarySearchTree::displayHelper(Node* node, int space) const
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
void BinarySearchTree::displayTree() const
{
    if (root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "\nTree Structure:\n";
    displayHelper(root, 0);
}

// Inorder Helper
void BinarySearchTree::inorderHelper(Node* node) const
{
    if (node == nullptr)
        return;

    inorderHelper(node->left);
    cout << node->data << " ";
    inorderHelper(node->right);
}

// Inorder Traversal
void BinarySearchTree::inorder() const
{
    if (root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "Inorder Traversal: ";
    inorderHelper(root);
    cout << endl;
}

// Preorder Helper
void BinarySearchTree::preorderHelper(Node* node) const
{
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
}

// Preorder Traversal
void BinarySearchTree::preorder() const
{
    if (root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "Preorder Traversal: ";
    preorderHelper(root);
    cout << endl;
}

// Postorder Helper
void BinarySearchTree::postorderHelper(Node* node) const
{
    if (node == nullptr)
        return;

    postorderHelper(node->left);
    postorderHelper(node->right);
    cout << node->data << " ";
}

// Postorder Traversal
void BinarySearchTree::postorder() const
{
    if (root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "Postorder Traversal: ";
    postorderHelper(root);
    cout << endl;
}

// Breadth First Search
void BinarySearchTree::BFS() const
{
    if (root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

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
void BinarySearchTree::DFSHelper(Node* node) const
{
    if (node == nullptr)
        return;

    cout << node->data << " ";

    DFSHelper(node->left);
    DFSHelper(node->right);
}

// Depth First Search
void BinarySearchTree::DFS() const
{
    if (root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "DFS Traversal (Preorder): ";
    DFSHelper(root);
    cout << endl;
}

// Check Complete Binary Tree
bool BinarySearchTree::checkCompleteTree() const
{
    if (root == nullptr)
        return true;

    queue<Node*> q;
    q.push(root);

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
int BinarySearchTree::countNodesHelper(Node* node) const
{
    if (node == nullptr)
        return 0;

    return 1 + countNodesHelper(node->left)
             + countNodesHelper(node->right);
}

// Count Total Nodes
int BinarySearchTree::countNodes() const
{
    return countNodesHelper(root);
}

// Count Leaf Nodes Helper
int BinarySearchTree::countLeafNodesHelper(Node* node) const
{
    if (node == nullptr)
        return 0;

    if (node->left == nullptr && node->right == nullptr)
        return 1;

    return countLeafNodesHelper(node->left)
         + countLeafNodesHelper(node->right);
}

// Count Leaf Nodes
int BinarySearchTree::countLeafNodes() const
{
    return countLeafNodesHelper(root);
}

// Find Highest Node
bool BinarySearchTree::findHighest(int& answer) const
{
    if (root == nullptr)
        return false;

    Node* current = root;

    while (current->right != nullptr)
        current = current->right;

    answer = current->data;

    return true;
}

// Find Second Highest Node
bool BinarySearchTree::findSecondHighest(int& answer) const
{
    if (root == nullptr)
        return false;

    Node* current = root;
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
void BinarySearchTree::displayCommonParentHelper(Node* node) const
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
void BinarySearchTree::displayCommonParentNodes() const
{
    if (root == nullptr)
    {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "Nodes having a common parent:\n";
    displayCommonParentHelper(root);
}

// Count Nodes Having a Sibling
int BinarySearchTree::countNodesWithSiblingHelper(Node* node) const
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
int BinarySearchTree::countNodesWithSibling() const
{
    return countNodesWithSiblingHelper(root);
}

// Height Helper
int BinarySearchTree::heightHelper(Node* node) const
{
    if (node == nullptr)
        return 0;

    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);

    return 1 + max(leftHeight, rightHeight);
}

// Height of Tree
int BinarySearchTree::height() const
{
    return heightHelper(root);
}

// Count Nodes Having Only Left Child
int BinarySearchTree::countOnlyLeftChildHelper(Node* node) const
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
int BinarySearchTree::countOnlyLeftChild() const
{
    return countOnlyLeftChildHelper(root);
}

// Search Node
void BinarySearchTree::searchNode(int value) const
{
    Node* current = root;

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
void BinarySearchTree::deleteTreeHelper(Node* node)
{
    if (node == nullptr)
        return;

    deleteTreeHelper(node->left);
    deleteTreeHelper(node->right);

    delete node;
}

// Delete Complete Tree
void BinarySearchTree::deleteTree()
{
    deleteTreeHelper(root);
    root = nullptr;
}

void operateTree()
{
    BinarySearchTree tree;

    int choice, value, answer;

    do
    {
        cout << "\n========== TREE MENU ==========\n";

        cout << "1. Insert Node\n";
        cout << "2. Display Tree\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Breadth First Search (BFS)\n";
        cout << "7. Depth First Search (DFS)\n";
        cout << "8. Check Complete Binary Tree\n";
        cout << "9. Count Total Nodes\n";
        cout << "10. Find Highest Node\n";
        cout << "11. Find Second Highest Node\n";
        cout << "12. Display Nodes Having Common Parent\n";
        cout << "13. Count Nodes Having Common Parent\n";
        cout << "14. Count Leaf Nodes\n";
        cout << "15. Find Height of Tree\n";
        cout << "16. Count Nodes Having Only Left Child\n";
        cout << "17. Search Node\n";
        cout << "18. Delete Complete Tree\n";
        cout << "0. Back to Main Menu\n";

        cout << "\nEnter your choice: ";
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

            case 6:
                tree.BFS();
                break;

            case 7:
                tree.DFS();
                break;

            case 8:
                if (tree.checkCompleteTree())
                    cout << "Tree is a Complete Binary Tree!\n";
                else
                    cout << "Tree is not a Complete Binary Tree!\n";
                break;

            case 9:
                cout << "Total number of nodes = "
                     << tree.countNodes() << endl;
                break;

            case 10:
                if (tree.findHighest(answer))
                    cout << "Highest node = " << answer << endl;
                else
                    cout << "Tree is empty!\n";
                break;

            case 11:
                if (tree.findSecondHighest(answer))
                    cout << "Second highest node = "
                         << answer << endl;
                else
                    cout << "Second highest node does not exist!\n";
                break;

            case 12:
                tree.displayCommonParentNodes();
                break;

            case 13:
                cout << "Total nodes having a sibling = "
                     << tree.countNodesWithSibling() << endl;
                break;

            case 14:
                cout << "Total leaf nodes = "
                     << tree.countLeafNodes() << endl;
                break;

            case 15:
                cout << "Height of tree = "
                     << tree.height() << endl;
                break;

            case 16:
                cout << "Nodes having only left child = "
                     << tree.countOnlyLeftChild() << endl;
                break;

            case 17:
                cout << "Enter value to search: ";
                cin >> value;
                tree.searchNode(value);
                break;

            case 18:
                tree.deleteTree();
                cout << "Tree deleted successfully!\n";
                break;

            case 0:
                cout << "Returning to Main Menu...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);
}
