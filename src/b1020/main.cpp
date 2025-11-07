#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const double g_eps = 1e-8;

struct MoonCake{
  double supply;
  double total_price;
  double price;

  bool operator < (const MoonCake &b) {
    return price > b.price + g_eps;
  }
} g_mooncakeList[1005];

int main() {

  int N, D;
  scanf("%d %d", &N, &D);

  for (int i = 0; i < N; ++i) {
    scanf("%lf", &g_mooncakeList[i].supply);
  }
  for (int i = 0; i < N; ++i) {
    scanf("%lf", &g_mooncakeList[i].total_price);
  }
  for (int i = 0; i < N; ++i) {
    g_mooncakeList[i].price = g_mooncakeList[i].total_price / g_mooncakeList[i].supply;
  }

  std::sort(g_mooncakeList, g_mooncakeList + N);

  double iterD = D;
  double res = 0.0;
  int j = 0;
  while (iterD > g_eps && j < N) {
    double supply = min(iterD, g_mooncakeList[j].supply);
    res += supply * g_mooncakeList[j].price;
    iterD -= supply;
    //printf("%.2f", res);
    ++j;
  }
  printf("%.2f", res);

  return 0;
}