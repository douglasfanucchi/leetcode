#include <limits.h>

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

bool validateRecursive(BST *tree, int min, int max)
{
  bool isLeftValid = true, isRightValid = true;

  if (tree->value >= max || tree->value < min) {
    return false;
  }

  if (tree->left) {
    isLeftValid = validateRecursive(tree->left, min, tree->value);
  }

  if (tree->right) {
    isRightValid = validateRecursive(tree->right, tree->value, max);
  }

  return isLeftValid && isRightValid;
}

bool validateBst(BST* tree) {
  return validateRecursive(
    tree,
    INT_MIN,
    INT_MAX
  );
}
