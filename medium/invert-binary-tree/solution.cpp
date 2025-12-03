#include <vector>
using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree* tree) { // Time: O(n) | Space: O(logn)
    BinaryTree *tmp;

    if (!tree->left && !tree->right) {
        return;
    }
    if (tree->left) {
        invertBinaryTree(tree->left);
    }
    if (tree->right) {
        invertBinaryTree(tree->right);
    }
    tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;
}
