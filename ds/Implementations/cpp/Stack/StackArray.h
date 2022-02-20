#ifndef STACKARRAY_H
#define STACKARRAY_H
#include "Stack.h"
#include <cassert>
template <typename E> class AStack : public Stack<E> {
private:
  int maxSize;
  // Maximum size of stack
  int top;
  // Index for top element
  E *listArray;
  // Array holding stack elements
public:
  AStack(int size = DEFAULTSIZE)
  // Constructor
  {
    maxSize = size;
    top = 0;
    listArray = new E[size];
  }
  ~AStack() { delete[] listArray; } // Destructor
  void clear() { top = 0; }         // Reinitialize
  void push(const E &it) {
    // Put "it" on stack
    assert(top != maxSize);
    listArray[top++] = it;
  }
  E pop() {
    // Pop top element
    assert(top != 0);
    return listArray[--top];
  }
  const E &topValue() const {
    // Return top element
    assert(top != 0);
    return listArray[top - 1];
  }
  int length() const { return top; }
};

#endif /* STACKARRAY_H */
