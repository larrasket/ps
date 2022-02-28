#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;

void printArr(int arr[], int n) {
  for (int i = 0; i < 10; i++)
    cout << arr[i] << endl;
}

void yastShuffle(int arr[], int n) {
  srand(time(NULL));
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    std::swap(arr[i], arr[j]);
  }
}

int main() {
  int arr[] = {10, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int n = sizeof(arr) / sizeof(arr[0]);
  yastShuffle(arr, n);
  printArr(arr, n);
  return 0;
}
