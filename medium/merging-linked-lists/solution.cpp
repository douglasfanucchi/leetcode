using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* mergingLinkedLists(
  LinkedList* linkedListOne, LinkedList* linkedListTwo
) {
  LinkedList *trav;

  while (linkedListOne) { // O(n * m) n = length of linkedListOne and m = length of linkedListTwo
    trav = linkedListTwo;
    while (trav) {
      if (trav == linkedListOne) {
        return trav;
      }
      trav = trav->next;
    }
    linkedListOne = linkedListOne->next;
  }

  return nullptr;
}
