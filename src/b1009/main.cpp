#define _CRT_SECURE_NO_WARNINGS

#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main() {

  std::stack<std::string> s;
  std::string str;

  while (cin >> str)
  {
    //printf("%s\n", str.c_str());
    s.push(str);
    if (getchar() == '\n') {
      break;
    }
  }

  while (!s.empty()) {
    printf("%s", s.top().c_str());
    s.pop();
    if (!s.empty()) {
      printf(" ");
    }
  }

  return 0;
}