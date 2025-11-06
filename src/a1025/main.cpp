#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int a, b, d;
  scanf("%d %d %d", &a, &b, &d);

  int sumIter = a + b;
  if (sumIter == 0){
    printf("0");
    return 0;
  }

  std::stack<int> s;
  while (sumIter > 0) {
    int mod = sumIter % d;
    s.push(mod);
    sumIter /= d;
  }
  while (!s.empty())
  {
    printf("%d", s.top());
    s.pop();
  }

  return 0;
}