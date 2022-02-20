#include <bits/stdc++.h>
#include <bits/types/cookie_io_functions_t.h>
#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class mainlist {
public:
  virtual void mylo() { cout << "MAIN LSIT"; }

protected:
  virtual void lol() { cout << "MAIN LSIT"; }
};
class anotherclass : public mainlist {
  // public:
  // void lol() { cout << "Another LSIT"; }
};

int main() {
  int i = 3;
  int *k = &i;
  auto p = k;
  int r = 4;
  k = &r;

  cout << *p << endl;
}
