#include <deque>

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

bool symmetricalTreeRecursive(BinaryTree* tree1, BinaryTree* tree2) {
    bool first = false, second = false;
    if (tree1->left && tree2->right) {
        first = symmetricalTreeRecursive(tree1->left, tree2->right);
    } else if (!tree1->left && !tree2->right) {
        first = true;
    }

    if (tree1->right && tree2->left) {
        second = symmetricalTreeRecursive(tree1->right, tree2->left);
    } else if (!tree1->right && !tree2->left) {
        second = true;
    }

    return first && second && tree1->value == tree2->value;
}

bool symmetricalTree(BinaryTree* tree) { // Time: O(n) | Space: O(logn)
    if (!tree->left && !tree->right) {
        return true;
    }

    if ((tree->left && !tree->right) || (!tree->left && tree->right)) {
        return false;
    }

    return symmetricalTreeRecursive(tree->left, tree->right);
}
