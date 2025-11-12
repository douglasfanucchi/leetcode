using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) {
  LinkedList *unique, *tmp, *head;

  head = linkedList;
  while (linkedList) {
    unique = linkedList;

    while (
      linkedList->next &&
      linkedList->next->value == unique->value
    ) {
      tmp = linkedList->next->next;
      delete linkedList->next;
      linkedList->next = tmp;
    }

    linkedList = linkedList->next;
  }

  return head;
}
