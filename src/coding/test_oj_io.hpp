# pragma

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;


int test_oj_single() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", a + b);
  return 0;
}

int test_oj_multi_eof() {
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF) {
    printf("%d\n", a + b);
  }
  return 0;
}

int test_oj_multi_break() {
  int a, b;
  while (scanf("%d%d", &a, &b) != EOF) {
    if (a == 0 && b == 0) {
      break;
    }
    printf("%d\n", a + b);
  }
  return 0;
}

int test_oj_multi_counting() {
  int T, a, b;
  cin >> T;
  while (T-- > 0)
  {
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);
  }
  return 0;
}


int test_oj_io() {
  //return test_oj_single();
  //return test_oj_multi_eof();
  //return test_oj_multi_break();
  return test_oj_multi_counting();
}