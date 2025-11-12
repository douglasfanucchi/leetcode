#include <vector>
#include <queue>

using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
 public:
  string name;
  vector<Node*> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string>* array) {
    queue<Node*> queue;
    Node *trav;

    queue.push(this);

    while (queue.size()) {
      trav = queue.front();
      array->push_back(trav->name);
      for(int i = 0; i < trav->children.size(); i++) {
        queue.push(trav->children[i]);
      }
      queue.pop();
    }

    return *array;
  }

  Node* addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }
};
