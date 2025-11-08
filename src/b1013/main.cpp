#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

bool isprime(const int n) {
	if (n < 2) {
		return false;
	}

	int n_sqrt = sqrt(n);
	for (int i = 2; i <= n_sqrt; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {

	int M, N;
	scanf("%d %d", &M, &N);


	std::vector<int> res;
	int i = 0;
	int cnt = 0;
	while (cnt < N) {
		if (isprime(i)) {
			++cnt;
			if (cnt >= M) {
				res.push_back(i);
			}
		}
		++i;
	}

	for (int j = 0; j < res.size(); ++j) {
		printf("%d", res[j]);
		if ((j + 1) % 10 == 0) {
			if (j != res.size() - 1) {
				printf("\n");
			}
		}
		else
		{
			if (j != res.size() - 1) {
				printf(" ");
			}
		}
	}

  return 0;
}