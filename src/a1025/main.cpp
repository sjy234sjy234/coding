#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
using namespace std;


struct testee {
  long long id;
  int location;
  int score;
  int local_rank;
  int final_rank;
} g_testList [30005];

bool cmp(const testee &a, const testee &b) {
  if (a.score != b.score) {
    return a.score > b.score;
  }
  else {
    return a.id < b.id;
  }
}

int main() {

  int N, TotalK = 0;
  scanf("%d", &N);
  int jbase = 0;
  for (int i = 1; i <= N; ++i) {

    // read each location
    int loc = i;
    int K;
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
      int j_t = j + jbase;
      g_testList[j_t].location = loc;
      scanf("%lld %d", &g_testList[j_t].id, &g_testList[j_t].score);
    }

    // sort each location
    std::sort(g_testList + jbase, g_testList + jbase + K, cmp);

    // indexing each location rank
    int loc_rank = 1;
    for (int j = 0; j < K; ++j) {
      int j_t = j + jbase;
      if (j > 0 && g_testList[j_t].score != g_testList[j_t - 1].score) {
        loc_rank = j + 1;
      }
      g_testList[j_t].local_rank = loc_rank;
    }

    TotalK += K;
    jbase += K;
  }

  // sort all
  std::sort(g_testList, g_testList + TotalK, cmp);

  // indexing final rank
  int final_rank = 1;
  for (int i = 0; i < TotalK; ++i) {
    if (i > 0 && g_testList[i].score != g_testList[i - 1].score) {
      final_rank = i + 1;
    }
    g_testList[i].final_rank = final_rank;
  }

  printf("%d\n", TotalK);
  for (int i = 0; i < TotalK; ++i) {
    // printf("%013lld %d %d %d %d\n", g_testList[i].id, g_testList[i].score, g_testList[i].final_rank, g_testList[i].location, g_testList[i].local_rank);
    printf("%013lld %d %d %d\n", g_testList[i].id, g_testList[i].final_rank, g_testList[i].location, g_testList[i].local_rank);
  }


  return 0;
}