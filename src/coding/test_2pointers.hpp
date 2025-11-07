# pragma

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;


int test_2pointers_temp() {
  int numList[6] = {1, 2, 3, 4, 5, 6};  // increasing array
  int M;
  scanf("%d", &M);
  int i = 0;
  int j = 5;

  std::vector<std::pair<int, int>> res;
  while (i < j) {
    int tempSum = numList[i] + numList[j];
    if (tempSum == M) {
      res.push_back({numList[i], numList[j]});
      ++i;
      --j;
    }
    else if(tempSum < M) {
      ++i;
    }
    else {
      --j;
    }
  }
  for (int k = 0; k < res.size(); ++k) {
    printf("(%d, %d)\n", res[k].first, res[k].second);
  }

  return 0;
}


int test_2pointers() {
  return test_2pointers_temp();
}