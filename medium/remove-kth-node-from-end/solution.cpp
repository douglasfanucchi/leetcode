#include <vector>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList* next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
  LinkedList *trav = head;
  LinkedList *prev;

  int size = 0;
  while (trav) {
    size++;
    trav = trav->next;
  }

  trav = head;
  for(int i = 1; i < size - k + 1; i++) {
    prev = trav;
    trav = trav->next;
  }

  while (trav->next) {
    prev = trav;
    trav->value = trav->next->value;
    trav = trav->next;
  }

  delete prev->next;
  prev->next = nullptr;
}
