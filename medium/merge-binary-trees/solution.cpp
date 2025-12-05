using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) { // Time: O(n) | Space: O(logn). Where n is the number of nodes in the smaller tree
    tree1->value += tree2->value;
    if (tree1->left && tree2->left) {
        mergeBinaryTrees(tree1->left, tree2->left);
    } else if (tree2->left) {
        tree1->left = tree2->left;
    }

    if (tree1->right && tree2->right) {
        mergeBinaryTrees(tree1->right, tree2->right);
    } else if (tree2->right) {
        tree1->right = tree2->right;
    }

    return tree1;
}
