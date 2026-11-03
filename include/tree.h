
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
using namespace std;

class BinarySearchTree
{
private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(int value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };
    Node* root;

    // Private helper functions
    Node* insertHelper(Node* node, int value);
    void inorderHelper(Node* node) const;
    void preorderHelper(Node* node) const;
    void postorderHelper(Node* node) const;
    void displayHelper(Node* node, int space) const;
    void DFSHelper(Node* node) const;
    int countNodesHelper(Node* node) const;
    int countLeafNodesHelper(Node* node) const;
    int countNodesWithSiblingHelper(Node* node) const;
    int heightHelper(Node* node) const;
    int countOnlyLeftChildHelper(Node* node) const;
    void displayCommonParentHelper(Node* node) const;
    void deleteTreeHelper(Node* node);

public:

    BinarySearchTree();
    ~BinarySearchTree();

    // Prevent accidental shallow copies
    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

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
};

void operateTree();

#endif
