#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST& insert(int val) {
    BST *root = this;

    if (value > val && this->left) {
      this->left->insert(val);
      return *this;
    }

    if (value > val) {
      this->left = new BST(val);
      return *this;
    }

    if (this->right) {
      this->right->insert(val);
      return *this;
    }

    this->right = new BST(val);

    return *this;
  }

  bool contains(int val) {
    if (val == this->value) {
      return true;
    }

    if (this->value > val && this->left) {
      return this->left->contains(val);
    }

    if (this->value > val) {
      return false;
    }

    if (this->right) {
      return this->right->contains(val);
    }

    return false;
  }

  BST& remove(int val) {
    if (this->isLeaf()) {
      return *this;
    }

    this->recursiveRemove(val, nullptr);

    return *this;
  }

  void recursiveRemove(int val, BST *parent) {
    BST *tmp, *prev;

    if (this->value == val) {
      if (this->isLeaf() && parent->left == this) {
        tmp = this;
        parent->left = nullptr;
      } else if (this->isLeaf() && parent->right == this) {
        tmp = this;
        parent->right = nullptr;
      } else if (!this->right) {
        tmp = this->left;
        this->value = this->left->value;
        this->right = this->left->right;
        this->left = this->left->left;
      } else {
        prev = this;
        tmp = this->right;
        while (tmp->left) {
          prev = tmp;
          tmp = tmp->left;
        }
        this->value = tmp->value;
        if (prev == this) {
          this->right = tmp->right;
        } else {
          prev->left = nullptr;
        }
      }

      delete tmp;
      return;
    }

    if (val < this->value && this->left) {
      return this->left->recursiveRemove(val, this);
    }

    if (this->right) {
      this->right->recursiveRemove(val, this);
    }
  }

  bool isLeaf() {
    return !this->left && !this->right;
  }
};
