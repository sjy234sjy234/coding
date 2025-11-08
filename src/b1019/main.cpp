#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int main() {

	int num;
	scanf("%d", &num);

	do {
		int numList[4];
		int iterNum = num;
		for (int i = 0; i < 4; ++i) {
			numList[i] = iterNum % 10;
			iterNum /= 10;
		}
		std::sort(numList, numList + 4);
		
		int num1 = 0, num2 = 0;
		for (int i = 0; i < 4; ++i) {
			num1 = num1 * 10 + numList[3 - i];
			num2 = num2 * 10 + numList[i];
		}

		num = num1 - num2;
		printf("%04d - %04d = %04d\n", num1, num2, num);

	} while (num != 6174 && num != 0);

  return 0;
}