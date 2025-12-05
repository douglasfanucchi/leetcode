#include <vector>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void traverse(BinaryTree *tree, int &sum) {
    if (tree->left) {
        traverse(tree->left, sum);
    }
    sum += tree->value;
    if (tree->right) {
        traverse(tree->right, sum);
    }
}

vector<int> hasSubtreeSumUpToHalfOfTotal(BinaryTree *tree, int total) {
    vector<int> left = {0, 0}, right = {0, 0};
    bool hasSum = 0;

    if (tree->left) {
        left = hasSubtreeSumUpToHalfOfTotal(tree->left, total);
    }
    if (tree->right) {
        right = hasSubtreeSumUpToHalfOfTotal(tree->right, total);
    }

    hasSum = left[1] || right[1];
    hasSum = hasSum || (left[0] + tree->value) == total / 2;
    hasSum = hasSum || (right[0] + tree->value) == total / 2;
    hasSum = hasSum || (left[0] + right[0] + tree->value) == total / 2;
    
    return {left[0] + right[0] + tree->value, (int)hasSum};
}

int splitBinaryTree(BinaryTree* tree) { // Time: O(n) | Space: O(logn)
    int sum = 0;
    traverse(tree, sum);

    if (sum % 2) {
        return 0;
    }

    vector<int> ans = hasSubtreeSumUpToHalfOfTotal(tree, sum);

    if (ans[1]) {
        return sum / 2;
    }

    return 0;
}
