#include <ctype.h>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>
int main() {
  int i = 3;
  switch (i) {
  case 1 ... 4:
    std::cout << "EQQE";
  }
}
