#ifndef ArrayList__
#define ArrayList__
#include "List.h"
#include <cassert>

template <typename t> class ArrayList : public List<t> {
private:
  int maxSize{};
  int size;
  int current;
  t *List;

public:
  explicit ArrayList(int maxSize = DEFAULTSIZE) {
    List = new t[maxSize];
    this->maxSize = maxSize;
    size = current = 0;
  }
  ~ArrayList() { delete[] List; }
  void clear() {
    delete[] List;
    List = new t[maxSize];
    current = size = 0;
  }
  void insert(const t &item) {
    assert(size < maxSize);
    for (int i = size; i > current; i--)
      List[i] = List[i - 1];
    List[current] = item;
    size++;
  }
  void append(const t &item) {
    assert(size < maxSize);
    List[size++] = item;
  }
  t remove() {
    assert(current >= 0);
    auto pastPosition = List[current];
    for (int i = current; i < size - 1; i++)
      List[i] = List[i + 1];
    size--;
    return pastPosition;
  }
  void moveToStart() { current = 0; }
  void moveToEnd() { current = size - 1; }
  void prev() { assert((current-- )> 0); }
  void next() { assert(current++ < size); }
  int length() const { return size; }
  int currPos() const { return current; }
  void moveToPos(const int &i) {
    assert(i < size);
    current = i;
  }
  const t &getValue() const { return List[current]; }
};
#endif
