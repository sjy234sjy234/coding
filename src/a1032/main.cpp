#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
using namespace std;


struct Node {
  char c;
  std::vector<int> priors;
  int next = -1;
} nodeList[100001];


int main() {
  int head1, head2, N;
  scanf("%d %d %d", &head1, &head2, &N);
  //printf("%d %d %d\n", head1, head2, N);
  for (int i = 0; i < N; ++i) {
    int idx, next;
    char c;
    scanf("%d %c %d", &idx, &c, &next);
    nodeList[idx].c = c;
    nodeList[idx].next = next;
    if (next >= 0) {
      nodeList[next].priors.push_back(idx);
    }
  }

  // find tail1
  int iter1 = head1;
  while (iter1 >= 0 && nodeList[iter1].next >= 0) {
    iter1 = nodeList[iter1].next;
  }

  // find tail2
  int iter2 = head2;
  while (iter2 >= 0 && nodeList[iter2].next >= 0) {
    iter2 = nodeList[iter2].next;
  }

  if (iter1 != iter2) {
    printf("-1");
  }
  else {
    int iterCommon = iter1;
    while (nodeList[iterCommon].priors.size() == 1) {
      iterCommon = nodeList[iterCommon].priors[0];
    }
    printf("%05d", iterCommon);
  }

  return 0;
}