#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);

  std::vector<int> scoreList(N + 1, 0);
  int max_idx = 0;
  int max_score = -1;
  while (N-- > 0)
  {
    int idx, score;
    scanf("%d %d", &idx, &score);
    scoreList[idx] += score;
    if (scoreList[idx] > max_score) {
      max_idx = idx;
      max_score = scoreList[idx];
    }
  }
  printf("%d %d", max_idx, max_score);

  return 0;
}