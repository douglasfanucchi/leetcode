using namespace std;

class Node {
 public:
  int value;
  Node* prev;
  Node* next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void setHead(Node* node) {
    if (!this->head) {
      this->head = this->tail = node;
      return;
    }

    this->insertBefore(this->head, node);
  }

  void setTail(Node* node) {
    if (!this->tail) {
      return this->setHead(node);
    }

    this->insertAfter(this->tail, node);
  }

  void insertBefore(Node* node, Node* nodeToInsert) {
    Node* trav = this->head;

    if (!head) {
      this->head = this->tail = nodeToInsert;
      return;
    }

    if (nodeToInsert == this->head) {
      this->head = this->head->next;
    }

    if (nodeToInsert == this->tail) {
      this->tail = this->tail->prev;
    }

    if (nodeToInsert->prev) {
      nodeToInsert->prev->next = nodeToInsert->next;
    }
    if (nodeToInsert->next) {
      nodeToInsert->next->prev = nodeToInsert->prev;
    }

    if (node == this->head) {
      nodeToInsert->next = this->head;
      nodeToInsert->prev = nullptr;
      this->head->prev = nodeToInsert;
      this->head = nodeToInsert;
      return;
    }

    while(trav->next && trav->next != node) {
      trav = trav->next;
    }

    nodeToInsert->prev = trav;
    nodeToInsert->next = trav->next;

    if (trav->next) {
      trav->next->prev = nodeToInsert;
    } else {
      this->tail = nodeToInsert;
    }

    trav->next = nodeToInsert;
  }

  void insertAfter(Node* node, Node* nodeToInsert) {
    Node* trav = head;

    if (!head) {
      head = tail = nodeToInsert;
      return;
    }

    if (nodeToInsert == this->head) {
      this->head = this->head->next;
    }

    if (nodeToInsert == this->tail) {
      this->tail = this->tail->prev;
    }

    if (nodeToInsert->prev) {
      nodeToInsert->prev->next = nodeToInsert->next;
    }

    if (nodeToInsert->next) {
      nodeToInsert->next->prev = nodeToInsert->prev;
    }

    while (trav && trav != node) {
      trav = trav->next;
    }

    if (!trav) {
      trav = this->tail;
    }

    if(trav == this->tail) {
      this->tail = nodeToInsert;
    }

    nodeToInsert->next = trav->next;
    nodeToInsert->prev = trav;
    if (trav->next) {
      trav->next->prev = nodeToInsert;
    }
    trav->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node* nodeToInsert) {
    if (position == 1) {
      return this->setHead(nodeToInsert);
    }

    Node *trav = this->head;

    for(int i = 1; i < position; i++) {
      trav = trav->next;
    }

    this->insertBefore(trav, nodeToInsert);
  }

  void removeNodesWithValue(int value) {
    Node *trav = this->head;
    Node *next;

    while (trav) {
      if (trav->value == value) {
        next = trav->next;
        this->remove(trav);
        trav = next;
      } else {
        trav = trav->next;
      }
    }
  }

  void remove(Node* node) {
    if (node == this->head) {
      this->head = node->next;
    }

    if (node == this->tail) {
      this->tail = node->prev;
    }

    if (node->prev) {
      node->prev->next = node->next;
    }

    if (node->next) {
      node->next->prev = node->prev;
    }

    node->next = nullptr;
    node->prev = nullptr;
  }

  bool containsNodeWithValue(int value) {
    Node *trav = this->head;

    while (trav) {
      if (trav->value == value) {
        return true;
      }
      trav = trav->next;
    }

    return false;
  }
};
