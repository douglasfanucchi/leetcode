using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) {
  int size = 0;
  LinkedList *trav = linkedList;

  while (trav) {
    size++;
    trav = trav->next;
  }

  trav = linkedList;
  for(int i = 0; i < size / 2; i++) {
    trav = trav->next;
  }

  return trav;
}
