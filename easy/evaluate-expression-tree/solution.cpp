using namespace std;

class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int evaluateExpressionTree(BinaryTree* tree) {
  if (!tree) {
    return 0;
  }

  int n1 = evaluateExpressionTree(tree->left);
  int n2 = evaluateExpressionTree(tree->right);

  switch(tree->value) {
    case -1:
      return n1 + n2;
    case -2:
      return n1 - n2;
    case -3:
      return n1 / n2;
    case -4:
      return n1 * n2;
  }

  return tree->value;
}
