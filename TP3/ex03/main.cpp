#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

class Node {
 public:
  int value;
  Node* next;
  Node(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class LinkedList {
 public:
  LinkedList() : head(nullptr) {}

  void addBack(int value) {
    Node* newNode = new Node(value);
    if (this->head == nullptr) {
      this->head = newNode;
    } else {
      this->getLast()->next = newNode;
    }
  }

  Node* getLast() {
    if (this->head == nullptr) return this->head;
    Node* tmp = this->head;

    while (tmp->next != nullptr) {
      tmp = tmp->next;
    }
    return tmp;
  }

  void display() {
    Node* tmp = this->head;
    while (tmp != nullptr) {
      cout << tmp->value << endl;
      tmp = tmp->next;
    }
  }

  ~LinkedList() {
    Node* tmp = this->head;
    while (tmp != nullptr) {
      Node* next = tmp->next;
      delete tmp;
      tmp = next;
    }
  }

 private:
  Node* head;
};

static void fillList(LinkedList& list, int size) {
  for (int i = 0; i < size; i++) {
    list.addBack(rand() % 100);
  }
}

int main() {
  srand(time(nullptr));

  LinkedList list;

  fillList(list, 20);
  list.display();
  return EXIT_SUCCESS;
}
