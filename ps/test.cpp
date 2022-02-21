#include <bits/stdc++.h>
#include <bits/types/cookie_io_functions_t.h>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
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
  std::list<std::string> mylist;
  mylist.push_back("qweq");
  mylist.push_back("2");
  mylist.push_back("wjijijeq");
  auto k = mylist.begin();
  std::advance(k, 2);
  std::advance(k, -2);

  cout << *(k);
}
