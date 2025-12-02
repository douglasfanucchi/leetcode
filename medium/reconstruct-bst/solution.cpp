#include <vector>
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

BST* reconstructBst(vector<int> preOrderTraversalValues) { // Time: O(n) | Space: O(n)
    deque<BST*> stack;
    int v;
    BST *trav, *root;
    stack.push_front(root = new BST(preOrderTraversalValues[0]));

    for(int i = 1; i < preOrderTraversalValues.size(); i++) {
        v = preOrderTraversalValues[i];
        if (v < stack.front()->value) {
            stack.push_front(stack.front()->left = new BST(v));
        } else {
            while (stack.size() && v >= stack.front()->value) {
                trav = stack.front();
                stack.pop_front();
            }
            stack.push_front(trav->right = new BST(v));
        }
    }

    return root;
}
