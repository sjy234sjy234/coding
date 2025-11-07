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

double square(const double x) {
  return x * x;
}

int test_binary_func() {
  // find sqrt(2) using binary search
  double low = 1.0;
  double high = 2.0;
  double target_square = 2.0;
  while (abs(low - high) > 1e-5) {
    double mid = (low + high) / 2.0;
    double mid_square = square(mid);
    if (mid_square > target_square) {
      high = mid;
    }
    else
    {
      low = mid;
    }
  }
  printf("test_binary_func \nlow: %.5f, high: %.5f\n", low, high);
  return 0;
}


long long binary_fastpow_recursive(const int a, const int b, const int m) {
  if (b == 0) {
    return 1;
  }
  else if (b == 1) {
    return a % m;
  }
  else if (b % 2) {
    return binary_fastpow_recursive(a, b - 1, m) * binary_fastpow_recursive(a, 1, m) % m;
  }
  else {
    return binary_fastpow_recursive(a, b / 2, m) * binary_fastpow_recursive(a, b / 2, m) % m;
  }
}

int test_binary_fastpow() {

  //// bruteforce (a < 1e9, b < 1e6, 1 < m < 1e9)
  //long long a, b, m;
  //long long res = 1;
  //scanf("%lld %lld %lld", &a, &b, &m);
  //for (int i = 0; i < b; ++i) {
  //  res = res * a % m;
  //}
  //printf("%lld %lld %lld %lld\n", a, b, m, res);

  //// binary (a < 1e9, b < 1e18, 1 < m < 1e9)
  //long long a, b, m;
  //long long res = 1;
  //scanf("%lld %lld %lld", &a, &b, &m);
  //std::vector<std::pair<long long, long long>> binaryRecord;  // pair<cnt, val>
  //long long iterB = b;
  //while (iterB > 0) {
  //  // get val
  //  int val;
  //  if (binaryRecord.empty()) {
  //    val = a % m;
  //  }
  //  else {
  //    val = binaryRecord.back().second * binaryRecord.back().second;
  //  }
  //  // set cnt & val
  //  if (iterB % 2) {
  //    binaryRecord.push_back({ 1, val });
  //  }
  //  else {
  //    binaryRecord.push_back({ 0, val });
  //  }
  //  // iter
  //  iterB >>= 1;
  //}
  //// get mod
  //for (int i = 0; i < binaryRecord.size(); ++i) {
  //  if (binaryRecord[i].first) {
  //    res = res * binaryRecord[i].second % m;
  //  }
  //}
  //printf("%lld %lld %lld %lld\n", a, b, m, res);

  // binary recursive (a < 1e9, b < 1e18, 1 < m < 1e9)
  long long a, b, m;
  long long res = 1;
  scanf("%lld %lld %lld", &a, &b, &m);
  res = binary_fastpow_recursive(a, b, m);
  printf("%lld %lld %lld %lld\n", a, b, m, res);

  return 0;
}

int test_binary() {
  //return test_binary_func();
  return test_binary_fastpow();
}