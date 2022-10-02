
#ifndef LinkedList__
#define LinkedList__

#include "Link.h"
#include "List.h"
#include <cassert>
#include <stack>

template <typename t> class LinkedList : public List<t> {
protected:
  Link<t> *head;
  Link<t> *current;
  Link<t> *tail;
  int count;

  void init(const t &input) {
    head = current = tail = new Link<t>(input, nullptr);
    count++;
  }

  void removeAll() {
    while (head != nullptr) {
      current = head;
      head = head->next;
      delete current;
    }
  }

public:
  explicit LinkedList(int size = DEFAULTSIZE) {
    head = current = tail = nullptr;
    count = 0;
  }

  ~LinkedList() { removeAll(); }

  void clear() { removeAll(); }

  void insert(const t &item) {
    if (head == nullptr) {
      init(item);
    } else {
      current->next = new Link<t>(item, current->next);
      if (tail == current)
        tail = current->next;
      count++;
    }
  }

  void append(const t &item) {
    if (head == nullptr)
      init(item);
    else {
      tail = tail->next = new Link<t>(item, nullptr);
      count++;
    }
  }

  void moveToStart() { current = head; }

  void moveToEnd() { current = tail; }

  void prev() {
    assert(current != head);
    Link<t> *temp = head;
    while (temp->next != current)
      temp = temp->next;
    current = temp;
  }

  void next() {
    //      if(current != tail)
    current = current->next;
  }

  int length() const { return count; }

  int currPos() const {
    int counter;
    Link<t> *temp = head;
    for (counter = 0; temp != current; ++counter) {
      temp = temp->next;
    }
    return counter;
  }

  void moveToPos(const int &pos) {
    assert(pos < count && pos > 0);
    current = head;
    for (int i = 0; i < pos; ++i) {
      current = current->next;
    }
  }

  const t &getValue() const { return current->element; }

  t remove() {
    assert(current != nullptr);
    if (current == head) {
      Link<t> *temphead = head;
      auto val = head->element;
      head = head->next;
      delete temphead;
      return val;
    }
    Link<t> *temp = current;
    t val = current->element;
    prev();
    current->next = temp->next;
    delete temp;
    count--;
    return val;
  }
  void interchange() {
    assert(current != tail && count > 2);
    t temp = current->element; // remember current val
    current->element = current->next->element;
    current->next->element = temp;
  }

  void reverse() {
    Link<t> *current = head, *prev = nullptr, *next = nullptr;
    head = tail;
    tail = current;
    while (current) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
  }
};

#endif
