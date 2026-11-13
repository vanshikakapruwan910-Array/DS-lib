#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Tree
{
private:
    struct Node
    {
        // BST / AVL fields
        int data;
        int height;
        Node* left;
        Node* right;

        // B-Tree / B+ Tree fields
        vector<int> keys;
        vector<Node*> children;
        bool isLeaf;
        Node* next; // Used only to link B+ Tree leaf nodes

        // Constructor for BST / AVL nodes
        Node(int value)
            : data(value), height(1), left(nullptr), right(nullptr),
              isLeaf(true), next(nullptr) {}

        // Constructor for B-Tree / B+ Tree nodes
        Node(bool leaf)
            : data(0), height(1), left(nullptr), right(nullptr),
              isLeaf(leaf), next(nullptr) {}
    };

    // BST and AVL share this root.
    Node* bstRoot;

    // B-Tree and B+ Tree use separate roots, but the same Node type.
    static const int B_TREE_T = 3;       // B-Tree minimum degree
    Node* bRoot;

    static const int BPLUS_MAX_KEYS = 3;
    Node* bPlusRoot;

    // BST private helpers
    Node* insertHelper(Node* node, int value);
    void displayHelper(Node* node, int space) const;
    void inorderHelper(Node* node) const;
    void preorderHelper(Node* node) const;
    void postorderHelper(Node* node) const;
    void DFSHelper(Node* node) const;
    int countNodesHelper(Node* node) const;
    int countLeafNodesHelper(Node* node) const;
    int countNodesWithSiblingHelper(Node* node) const;
    int heightHelper(Node* node) const;
    int countOnlyLeftChildHelper(Node* node) const;
    void displayCommonParentHelper(Node* node) const;
    void deleteTreeHelper(Node* node);
    void collectInorder(Node* node, vector<int>& out) const;
    Node* findNode(int value) const;
    Node* minNode(Node* node) const;
    Node* deleteNodeHelper(Node* node, int value, bool& found);
    Node* deleteLeafHelper(Node* node, int& count);

    // AVL private helpers
    int getHeight(Node* node) const;
    int balanceFactor(Node* node) const;
    void updateHeight(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* avlInsertHelper(Node* node, int value);
    void avlDisplayHelper(Node* node, int space) const;
    void avlInorderHelper(Node* node) const;
    void avlDeleteTreeHelper(Node* node);

    // B-Tree private helpers
    void splitChild(Node* parent, int i);
    void insertNonFull(Node* node, int value);
    void bDisplayHelper(Node* node, int level) const;
    void bInorderHelper(Node* node) const;
    void bDeleteTreeHelper(Node* node);

    // B+ Tree private helpers
    bool bPlusInsertHelper(Node* node, int value, int& upKey, Node*& newChild);
    void bPlusDisplayHelper(Node* node, int level) const;
    void bPlusDeleteTreeHelper(Node* node);
    

public:
    Tree();
    ~Tree();
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    // BST public operations
    void insertNode(int value);
    void displayTree() const;
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void BFS() const;
    void DFS() const;
    bool checkCompleteTree() const;
    int countNodes() const;
    int countLeafNodes() const;
    bool findHighest(int& answer) const;
    bool findSecondHighest(int& answer) const;
    void displayCommonParentNodes() const;
    int countNodesWithSibling() const;
    int height() const;
    int countOnlyLeftChild() const;
    void searchNode(int value) const;
    void deleteTree();
    vector<int> toVector() const;
    void deleteNode(int value);
    void deleteLeftSubtree(int value);
    void deleteRightSubtree(int value);
    void deleteLeafNodes();

    // AVL public operations
    void convertToAVL(); // Balance the existing BST using the same nodes/root
    void avlInsertNode(int value);
    void avlDisplayTree() const;
    void avlInorder() const;
    int avlHeight() const;
    void avlDeleteTree();

    // B-Tree public operations
    void bInsertNode(int value);
    void bDisplayTree() const;
    void bInorder() const;
    int bHeight() const;
    void bDeleteTree();

    // B+ Tree public operations
    void bPlusInsertNode(int value);
    void bPlusDisplayTree() const;
    void bPlusDisplayLeaves() const;
    int bPlusHeight() const;
    void bPlusDeleteTree();
};

void operateTree();

#endif
