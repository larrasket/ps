#ifndef POINTERBINNODE_H
#define POINTERBINNODE_H
#include "binNodeADT.h"
template <typename t> class BSTNode : public BinNode<t> {
private:
  t value;
  BSTNode *lp; // left pointer
  BSTNode *rp; // right pointer
public:
  BSTNode(t v) {
    lp = rp = nullptr;
    value = v;
  }
  BSTNode *left() const { return lp; }
  BSTNode(t v, BSTNode *l, BSTNode *r) {
    lp = l;
    rp = r;
    value = v;
  }
  t &element() { return value; }
  void setElement(const t &value) { this->value = value; }
  void setLeft(BSTNode *lp) { this->lp = lp; };
  BSTNode *right() const { return rp; }
  void setRight(BSTNode *rp) { this->rp = rp; };
  bool isLeaf() { return (lp == nullptr && rp == nullptr); }
};

#endif /* POINTERBINNODE_H */
