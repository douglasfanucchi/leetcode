class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};

int abs(int x)
{
  if (x < 0) {
    return x * -1;
  }
  return x;
}

void findClosesValueInBstRecursive(BST *tree, int target, int *min, int *result)
{
  if (!tree) {
    return;
  }

  if (*min < 0 || abs(tree->value - target) < *min) {
    *min = abs(tree->value - target);
    *result = tree->value;
  }

  findClosesValueInBstRecursive(tree->left, target, min, result);
  findClosesValueInBstRecursive(tree->right, target, min, result);
}

int findClosestValueInBst(BST* tree, int target) {
  int min = -1;
  int result = 0;

  findClosesValueInBstRecursive(tree, target, &min, &result);

  return result;
}
