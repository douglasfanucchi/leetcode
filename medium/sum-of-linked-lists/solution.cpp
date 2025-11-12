using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList* sumOfLinkedLists(
  LinkedList* linkedListOne, LinkedList* linkedListTwo
) {
  LinkedList *head = nullptr;
  LinkedList *trav = head;

  int sum;
  int n1 = 0;
  int n2 = 0;
  int carry = 0;
  while (linkedListOne || linkedListTwo) {
    if (!head) {
      head = new LinkedList(0);
      trav = head;
    } else {
      trav->next = new LinkedList(0);
      trav = trav->next;
    }

    if (linkedListOne) {
      n1 = linkedListOne->value;
      linkedListOne = linkedListOne->next;
    }
    if (linkedListTwo) {
      n2 = linkedListTwo->value;
      linkedListTwo = linkedListTwo->next;
    }

    sum = n1 + n2 + carry;

    trav->value = sum % 10;
    carry = sum / 10;

    n1 = n2 = 0;
  }

  if (carry) {
    trav->next = new LinkedList(carry);
  }
  
  return head;
}
