#include <ctype.h>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>
using namespace std;

void rr();
int main() { rr(); }

void rr() {
  vector<int> e{1, 2, 3, 4, 5};
  for (auto &i : e) {
    i = -1;
  }

  for (auto &i : e) {
    std::cout << i << std::endl;
  }
}

void r() {
  try {
    int nage = 15;
    if (nage >= 18) {
      std::cout << "Access granted - you are old enough.";
    } else {
      throw(nage);
    }
  } catch (int myNum) {
    std::cout << "Access denied - You must be at least 18 years old.\n";
    std::cout << "Age is: " << myNum;
  }
}
