#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main() {
  int n;

  scanf("%d", &n);
  int cnt = 0;
  long long iter = n;
  while (iter != 1) {
    if (iter % 2) {
      iter = (iter * 3 + 1) >> 1;
    }
    else {
      iter = iter >> 1;
    }
    ++cnt;
  }
  printf("%d\n", cnt);

  return 0;
}