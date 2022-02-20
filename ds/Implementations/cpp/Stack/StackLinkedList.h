#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H
#include "../Lists/Link.h"
#include "Stack.h"
template <typename E> class LStack : public Stack<E> {
private:
  Link<E> *top;
  // Pointer to first element
  int size;
  // Number of elements
public:
  LStack(int sz = DEFAULTSIZE) // Constructor
  {
    top = nullptr;
    size = 0;
  }
  ~LStack() { clear(); } // Destructor
  void clear() {
    while (top != nullptr) {
      Link<E> *temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  } // Reinitialize
  // Delete link nodes
  void push(const E &it) { // Put "it" on stack
    top = new Link<E>(it, top);
    size++;
  }
  E pop() {
    // Remove "it" from stack
    Assert(top != nullptr, "Stack is empty");
    E it = top->element;
    Link<E> *ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return it;
  }
  const E &topValue() const { // Return top value
    Assert(top != 0, "Stack is empty");
    return top->element;
  }
  int length() const { return size; } // Return length
};

#endif /* STACKLINKEDLIST_H */
