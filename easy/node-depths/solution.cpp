#include <vector>

using namespace std;

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

typedef struct s_register {
  BinaryTree *node;
  int depth;
} t_register;

int nodeDepths(BinaryTree* root) {
  vector<t_register> stack;
  int result = 0;
  t_register rootReg, left, right;

  if (root) {
    rootReg.node = root;
    rootReg.depth = 0;
    stack.push_back(rootReg);
  }

  while (stack.size()) {
    rootReg = stack.back();
    stack.pop_back();
    left.node = rootReg.node->left;
    right.node = rootReg.node->right;
    left.depth = right.depth = rootReg.depth + 1;
    if (rootReg.node->right) {
      stack.push_back(right);
    }
    if (rootReg.node->left) {
      stack.push_back(left);
    }

    result += rootReg.depth;
  }

  return result;
}
