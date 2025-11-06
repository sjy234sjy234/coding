#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int N;
  char c;
  scanf("%d %c", &N, &c);

  int numRows = round(N / 2.0);
  int numCols = N;
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (i == 0 || i == numRows - 1) {
        printf("%c", c);
      }
      else {
        if (j == 0 || j == numCols - 1) {
          printf("%c", c);
        }
        else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
  //printf("\n");

  return 0;
}