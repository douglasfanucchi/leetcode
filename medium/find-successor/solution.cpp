#include <vector>
#include <deque>
#include <iostream>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;
  BinaryTree* parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void inOrderTraverse(BinaryTree *tree, vector<BinaryTree*> &nodes) {
    if (tree->left) {
        inOrderTraverse(tree->left, nodes);
    }
    nodes.push_back(tree);
    if (tree->right) {
        inOrderTraverse(tree->right, nodes);
    }
}

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) { // Time: O(n) | Space: O(n)
    vector<BinaryTree*> nodes;
    deque<BinaryTree*> stack;
    BinaryTree *right;
    int i;
    
    inOrderTraverse(tree, nodes);
    for(i = 0; i < nodes.size() && nodes[i] != node; i++);
    if (i == nodes.size() || i == nodes.size() - 1) {
        return nullptr;
    }
    return nodes[i + 1];
}
