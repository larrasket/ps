#include <bits/stdc++.h>
#include <bits/types/cookie_io_functions_t.h>
#include <iostream>

using std::cout;
using std::endl;

void myfun(int i) { cout << "I adress in `myfun is`" << &i << endl; }
void myfunc(int &i) { cout << "I adress in `myfunc is`" << &i << endl; }
int main() {
  int a = 10;
  cout << "A Adress is " << &a << endl;
}
