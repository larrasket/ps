#ifndef BST_H_
#define BST_H_
#include "BSTADT.h"
#include "binNodeADT.h"
#include "pointerBinNode.h"
template <typename t> class BST {
  BSTNode<t> *root;

public:
  BST() { root = nullptr; }
  void inorder(BSTNode<t> *n, void x(t i)) {
    if (!n)
      return;
    inorder(n->left(), x);
    x(n->element());
    inorder(n->right(), x);
  }
  void postorder(BSTNode<t> *n, void x(t i)) {
    if (!n)
      return;
    inorder(n->left(), x);
    inorder(n->right(), x);
    x(n->element());
  }
  void preorder(BSTNode<t> *n, void x(t i)) {
    if (!n)
      return;
    x(n->element());
    inorder(n->left(), x);
    inorder(n->right(), x);
  }
  BSTNode<t> *insert(t v) { return insert(v, find(v)); };
  BSTNode<t> *find(t v) {
    BSTNode<t> *h = root;
    while (h) {
      if (h->element() < v)
        h = h->right();
      else if (h->element() > v)
        h = h->left();
      else
        break;
    }
    return h;
  }
  BSTNode<t> *insert(t v, BSTNode<t> *pos) {
    if (!pos) {
      pos = new BSTNode<t>(v);
    } else if (pos->element() >= v) {
      insert(v, pos->left());
    }
    return pos;
  }
  BSTNode<t> *getroot() { return root; }
  bool remove(t v) {
    BSTNode<t> *x = find(v);
    return removep(x);
  }
  bool removep(BSTNode<t> *pos) {
    if (pos) {
      delete pos;
      return 1;
    }
    return 0;
  }
  BSTNode<t> *findMax() {
    BSTNode<t> *h = root;
    while (h->right()) {
      h = h->right();
    }
    return h;
  }
  BSTNode<t> *findMin() {
    BSTNode<t> *h = root;
    while (h->right()) {
      h = h->right();
    }
    return h;
  }
};

#endif // BST_H_
