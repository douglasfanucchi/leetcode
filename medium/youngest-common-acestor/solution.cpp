#include <vector>
using namespace std;

class AncestralTree {
 public:
  char name;
  AncestralTree* ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree*> descendants);
};

AncestralTree* getYoungestCommonAncestor(
  AncestralTree* topAncestor,
  AncestralTree* descendantOne,
  AncestralTree* descendantTwo
) { // Time: O(log(n)) | Space: O(1) where n is the number of nodes in the tree
    int d1 = 0, d2 = 0;
    AncestralTree *tmp = descendantOne;
    while (tmp != topAncestor) {
        tmp = tmp->ancestor;
        d1++;
    }
    tmp = descendantTwo;
    while (tmp != topAncestor) {
        tmp = tmp->ancestor;
        d2++;
    }
    if (d1 != d2) {
        tmp = descendantOne;
        if (d2 > d1) {
            tmp = descendantTwo;
        }
        for(int i = 0; i < abs(d1 - d2); i++) {
            tmp = tmp->ancestor;
        }
        if (d2 > d1) {
            descendantTwo = tmp;
        } else {
            descendantOne = tmp;
        }
    }
    while (descendantOne != descendantTwo) {
        descendantOne = descendantOne->ancestor;
        descendantTwo = descendantTwo->ancestor;
    }
    return descendantOne;
}
