#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {

  int cnt[10];
  int minIdx = -1;
  for (int i = 0; i < 10; ++i) {
    scanf("%d", &cnt[i]);
    if (i && cnt[i] && minIdx < 0) {
      minIdx = i;
    }
  }

  printf("%d", minIdx);
  --cnt[minIdx];

  for (int i = 0; i < 10; ++i) {
    while (cnt[i]--) {
      printf("%d", i);
    }
  }

  return 0;
}