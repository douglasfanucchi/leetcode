#include <algorithm>
#include <vector>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> binaryTreeDiameterRecursive(BinaryTree *tree) { // Time: O(n) | Space: O(logn)
    vector<int> left = {0, 0}, right = {0, 0};
    int height, diameter, edge = 0;

    if (!tree->left && !tree->right) {
        return {0, 0};
    }

    if (tree->left) {
        edge++;
        left = binaryTreeDiameterRecursive(tree->left);
    }

    if (tree->right) {
        edge++;
        right = binaryTreeDiameterRecursive(tree->right);
    }

    height = max(left[0], right[0]) + 1;
    diameter = max(max(left[1], right[1]), left[0] + right[0] + edge);

    return {height, diameter};
}

int binaryTreeDiameter(BinaryTree* tree) {
    vector<int> ans = binaryTreeDiameterRecursive(tree);

    return ans[1];
}
