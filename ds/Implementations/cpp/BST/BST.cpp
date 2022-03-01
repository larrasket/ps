#include "BST.h"
#include "binNodeADT.h"
#include "pointerBinNode.h"
#include <iostream>
using std::cout;
using std::endl;
void pritn(int i) { cout << i << endl; }
int main() {

  BST<int> wkop;
  wkop.insert(12);
  wkop.insert(141);
  wkop.insert(3);
  wkop.insert(335);
  wkop.postorder(wkop.getroot(), pritn);
  cout << "work;";
}
