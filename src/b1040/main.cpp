#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int main() {

	char str[100005];
	scanf("%s", str);
	int len = strlen(str);

	int cntList[3] = {};

	for (int i = 0; i < len; ++i) {
		if (str[i] == 'P') {
			cntList[0] = (cntList[0] + 1) % 1000000007;
		}
		else if (str[i] == 'A') {
			cntList[1] = (cntList[0] + cntList[1]) % 1000000007;
		}
		else {
			cntList[2] = (cntList[1] + cntList[2]) % 1000000007;
		}
	}
	printf("%d", cntList[2]);

  return 0;
}