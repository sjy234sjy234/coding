#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <queue>
using namespace std;



int g_N;
std::vector<int> g_postNumList;
std::vector<int> g_inNumList;

struct TreeNode {
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
};


void buildTreeRecursive(TreeNode* root, const int postI, const int postJ, const int inI, const int inJ) {

  root->val = g_postNumList[postJ];

  int k = inI;
  while (k <= inJ) {
    if (g_inNumList[k] == root->val) {
      break;
    }
    ++k;
  }

  if (k > inI) {
    root->left = new TreeNode();
    buildTreeRecursive(root->left, postI, postI + k - 1 - inI, inI, k - 1);
  }
  if (k < inJ) {
    root->right = new TreeNode();
    buildTreeRecursive(root->right, postI + k - inI, postJ - 1, k + 1, inJ);
  }
}


int main() {
  // get input
  scanf("%d", &g_N);
  for (int i = 0; i < g_N; ++i) {
    int num;
    scanf("%d", &num);
    g_postNumList.push_back(num);
  }
  for (int i = 0; i < g_N; ++i) {
    int num;
    scanf("%d", &num);
    g_inNumList.push_back(num);
  }
  //printf("%d\n", g_N);
  //for (int i = 0; i < g_N; ++i) {
  //  printf("%d ", g_postNumList[i]);
  //}
  //printf("\n");
  //for (int i = 0; i < g_N; ++i) {
  //  printf("%d ", g_inNumList[i]);
  //}
  //printf("\n");

  // build tree recursively
  TreeNode* root = new TreeNode();
  buildTreeRecursive(root, 0, g_N - 1, 0, g_N - 1);

  // tranverse level sequence
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* p = q.front();
    q.pop();
    printf("%d", p->val);
    {
      if (p->left != nullptr) {
        q.push(p->left);
      }
      if (p->right != nullptr) {
        q.push(p->right);
      }
      delete p;
    }
    if (!q.empty()) {
      printf(" ");
    }
  }

  return 0;
}