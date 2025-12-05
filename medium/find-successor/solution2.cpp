using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;
  BinaryTree* parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) { // Time: O(logn) | Space: O(1)
    if (node->right) {
        node = node->right;
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    while (node != tree && node->parent->right == node) {
        node = node->parent;
    }

    if (node == tree) {
        return nullptr;
    }

    return node->parent;
}
