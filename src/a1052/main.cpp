#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;


struct Node {
  int idx = -1;
  int key = -1;
  int next = -1;
} g_nodeList[100010];


int main() {

  int N, head;
  scanf("%d %d", &N, &head);

  for (int i = 0; i < N; ++i) {
    int idx, key, next;
    scanf("%d %d %d", &idx, &key, &next);
    g_nodeList[idx] = {idx, key, next};
  }

  int iter = head;
  std::vector<std::pair<int, int>> keyIdxList; // key, idx
  while (iter >= 0) {
    keyIdxList.push_back({ g_nodeList[iter].key, g_nodeList[iter].idx });
    iter = g_nodeList[iter].next;
  }

  // there may be outsiders in the input node list, first tranverse as a linked list
  sort(keyIdxList.begin(), keyIdxList.end());
  for (int i = 0; i < keyIdxList.size(); ++i) {
    //printf("%05d %d\n", keyIdxList[i].second, keyIdxList[i].first);
    if (i < keyIdxList.size() - 1) {
      g_nodeList[keyIdxList[i].second].next = keyIdxList[i + 1].second;
    }
    else {
      g_nodeList[keyIdxList[i].second].next = -1;
    }
  }

  // there may be no valid node in the linked list
  if (keyIdxList.empty()) {
    printf("0 -1\n");
  }
  else {
    int newN = keyIdxList.size();
    int newHead = keyIdxList[0].second;
    printf("%d %05d\n", newN, newHead);
    iter = newHead;
    while (iter >= 0) {
      if (g_nodeList[iter].next >= 0) {
        printf("%05d %d %05d\n", g_nodeList[iter].idx, g_nodeList[iter].key, g_nodeList[iter].next);
      }
      else
      {
        printf("%05d %d %d\n", g_nodeList[iter].idx, g_nodeList[iter].key, g_nodeList[iter].next);
      }
      iter = g_nodeList[iter].next;
    }
  }
  
  return 0;
}