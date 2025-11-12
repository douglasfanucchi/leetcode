#include <vector>

using namespace std;

// This is the class of the input root. Do not edit it.
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

void branchSumsRecursive(
  BinaryTree *root,
  int total,
  vector<int> &result
)
{
  if (root->left) {
    branchSumsRecursive(root->left, total + root->value, result);
  }
  if (root->right) {
    branchSumsRecursive(root->right, total + root->value, result);
  }
  if (!root->left && !root->right) {
    result.push_back(total + root->value);
  }
}

vector<int> branchSums(BinaryTree* root) {
  vector<int> result;

  if (!root) {
    return {};
  }

  branchSumsRecursive(root, 0, result);

  return result;
}
