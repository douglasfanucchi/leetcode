#include <vector>
#include <algorithm>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

vector<int> heightBalancedBinaryTreeRecursive(BinaryTree *tree) { // Time: O(n) | Space: O(logn)
    vector<int> left = {0, 1}, right = {0, 1};
    bool isBalanced = false;

    if (!tree->left && !tree->right) {
        return {0, 1};
    }

    if (tree->left) {
        left = heightBalancedBinaryTreeRecursive(tree->left);
        left[0]++;
    }
    
    if (tree->right) {
        right = heightBalancedBinaryTreeRecursive(tree->right);
        right[0]++;
    }

    isBalanced = left[1] && right[1] && abs(left[0] - right[0]) < 2;

    return {max(left[0], right[0]), (int)(isBalanced)};
}

bool heightBalancedBinaryTree(BinaryTree* tree) {
    vector<int> ans = heightBalancedBinaryTreeRecursive(tree);

    return (bool)ans[1];
}
