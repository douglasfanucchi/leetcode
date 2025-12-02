#include <deque>

using namespace std;

// This is an input class. Do not edit.
class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

int findKthLargestValueInBst(BST* tree, int k) { // Time: O(logn + k) | Space: O(logn)
    deque<BST*> nodes;
    vector<int> ans;
    BST* aux;

    while (tree) {
      nodes.push_front(tree);
      tree = tree->right;
    }

    while (nodes.size() && k > 0) {
        k--;
        tree = nodes.front();

        nodes.pop_front();
        if (tree->left) {
            aux = tree->left;
            while (aux) {
              nodes.push_front(aux);
              aux = aux->right;
            }
        }
    }

    return tree->value;
}
