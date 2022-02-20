#ifndef QUEUELINKED_H
#define QUEUELINKED_H
#include "Queue.h"
#include <cassert>
template <typename E> class AQueue : public Queue<E> {
private:
  int maxSize;
  // Maximum size of queue
  int front;
  // Index of front element
  int rear;
  // Index of rear element
  E *listArray;
  // Array holding queue elements
public:
  AQueue(int size = DEFAULTSIZE) { // Constructor
    // Make list array one position larger for empty slot
    maxSize = size + 1;
    rear = 0;
    front = 1;
    listArray = new E[maxSize];
  }
  ~AQueue() { delete[] listArray; } // Destructor
  void clear() {
    rear = 0;
    front = 1;
  } // Reinitialize
  void enqueue(const E &it) {
    // Put "it" in queue
    assert(((rear + 2) % maxSize) != front);
    rear = (rear + 1) % maxSize;
    // Circular increment
    listArray[rear] = it;
  }
  E dequeue() {
    // Take element out
    Assert(length() != 0, "Queue is empty");
    E it = listArray[front];
    front = (front + 1) % maxSize;
    // Circular increment
    return it;
  }
  const E &frontValue() const { // Get front value
    Assert(length() != 0, "Queue is empty");
    return listArray[front];
  }
  virtual int length() const
  // Return length
  {
    return ((rear + maxSize) - front + 1) % maxSize;
  }
};
#endif /* QUEUELINKED_H */
