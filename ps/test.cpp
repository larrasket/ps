#include <ctype.h>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>
// using namespace std;
int main() {
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
