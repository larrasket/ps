#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

template <typename E> class BinNode {
public:
  virtual ~BinNode() {} // Base destructor
  // Return the node’s value
  virtual E &element() = 0;
  // Set the node’s value
  // Return the node’s left child
  virtual void setElement(const E &) = 0;
  virtual BinNode *left() const = 0;
  // Set the node’s left child
  // virtual void setLeft(BinNode *lp) = 0;
  // virtual void setRight(BinNode<E> *l) = 0;
  virtual BinNode *right() const = 0;
  // Set the node’s right child
  // Return true if the node is a leaf, false otherwise
  virtual bool isLeaf() = 0;
};

#endif // BINARYTREENODE_H_
