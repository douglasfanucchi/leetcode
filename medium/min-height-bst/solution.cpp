#include <vector>

using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *createSubtreeMinHeight(vector<int> array, int start, int end)
{
  BST *node;

  int middle = (start + end) / 2;
  node = new BST(array[middle]);
  node->left = nullptr;
  node->right = nullptr;

  if (middle + 1 <= end) {
    node->right = createSubtreeMinHeight(array, middle + 1, end);
  }

  if (middle - 1 >= start) {
    node->left = createSubtreeMinHeight(array, start, middle - 1);
  }

  return node;
}

BST* minHeightBst(vector<int> array) {
  return createSubtreeMinHeight(array, 0, array.size() - 1);
}
