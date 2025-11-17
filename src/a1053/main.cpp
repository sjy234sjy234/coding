#define _CRT_SECURE_NO_WARNINGS

#include <iostream>  // 失败了一个case，暂不深究了。
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;


struct TreeNode {
  int weight = 0;
  int weightSum = 0;
  std::vector<int> childList;
  int parent = -1;
} g_treeNodeList[101];


bool cmp(const std::vector<int> &nums1, const std::vector<int> &nums2) {
  int i = 0;
  int j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    if (nums1[i] > nums2[j]) {
      return true;
    }
    else if (nums1[i] < nums2[j]) {
      return false;
    }
    ++i;
    ++j;
  }
  return false;
}


int main() {
  int N, M, S;
  scanf("%d %d %d", &N, &M, &S);
  
  for (int i = 0; i < N; ++i) {
    scanf("%d", &g_treeNodeList[i].weight);
  }

  g_treeNodeList[0].weightSum = g_treeNodeList[0].weight;
  
  for (int i = 0; i < M; ++i) {
    int idx, K;
    scanf("%d %d", &idx, &K);
    for (int j = 0; j < K; ++j) {
      int child;
      scanf("%d", &child);
      g_treeNodeList[idx].childList.push_back(child);
      g_treeNodeList[child].parent = idx;
      g_treeNodeList[child].weightSum = g_treeNodeList[idx].weightSum + g_treeNodeList[child].weight;
    }
  }

  std::vector<int> resTailList;
  std::vector<std::vector<int>> resPathList;
  for (int i = 0; i < N; ++i) {
    if (g_treeNodeList[i].childList.empty() && g_treeNodeList[i].weightSum == S) {
      resTailList.push_back(i);
    }
  }
  for (int i = 0; i < resTailList.size(); ++i) {
    int tailIdx = resTailList[i];
    std::stack<int> stackPath;
    std::vector<int> resPath;
    int iterIdx = tailIdx;
    while (iterIdx != -1) {
      stackPath.push(iterIdx);
      iterIdx = g_treeNodeList[iterIdx].parent;
    }
    while (!stackPath.empty()) {
      resPath.push_back(stackPath.top());
      stackPath.pop();
    }
    resPathList.push_back(resPath);
  }

  std::vector<std::vector<int>> resNumsList;
  for (int i = 0; i < resPathList.size(); ++i) {
    std::vector<int> resNums;
    for (int j = 0; j < resPathList[i].size(); ++j) {
      int idx = resPathList[i][j];
      resNums.push_back(g_treeNodeList[idx].weight);
    }
    resNumsList.push_back(resNums);
  }

  //printf("\n");
  //printf("N: %d, M: %d, S: %d\n", N, M, S);
  //for (int i = 0; i < N; ++i) {
  //  printf("id: %02d, weight: %d, weightSum: %d, parent: %d, K: %d childs: ", i, g_treeNodeList[i].weight, g_treeNodeList[i].weightSum, g_treeNodeList[i].parent, g_treeNodeList[i].childList.size());
  //  for (int j = 0; j < g_treeNodeList[i].childList.size(); ++j) {
  //    printf("%d ", g_treeNodeList[i].childList[j]);
  //  }
  //  printf("\n");
  //}

  //printf("\n");
  ////std::sort(resPathList.begin(), resPathList.end(), cmp);
  //for (int i = 0; i < resPathList.size(); ++i) {
  //  for (int j = 0; j < resPathList[i].size(); ++j) {
  //    int idx = resPathList[i][j];
  //    printf("%d ", g_treeNodeList[idx].weight);
  //  }
  //  printf("\n");
  //}

  std::sort(resNumsList.begin(), resNumsList.end(), cmp);
  //printf("\n");
  for (int i = 0; i < resNumsList.size(); ++i) {
    for (int j = 0; j < resNumsList[i].size(); ++j) {
      if (j == 0) {
        printf("%d", resNumsList[i][j]);
      }
      else
      {
        printf(" %d", resNumsList[i][j]);
      }
    }
    if (i < resPathList.size() - 1) {
      printf("\n");
    }
  }

  return 0;
}