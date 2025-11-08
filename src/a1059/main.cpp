#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;


bool isprime(const int n) {
	if (n < 2) {
		return false;
	}
	int sqrt_n = sqrt(n);
	for (int i = 2; i <= sqrt_n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {

	long long N;
	scanf("%lld", &N);

	long long sqrtN = sqrt(N);


	long long iterN = N;
	std::vector<std::pair<int, int>> resList;
	for (int i = 2; i <= sqrtN; ++i) {
		if (iterN <= 1) {
			break;
		}
		if (iterN % i == 0 && isprime(i)) {

			resList.push_back({ i, 0 });
			do {
				++resList.back().second;
				iterN /= i;
			} while (iterN % i == 0);

		}
	}

	if (resList.empty()) {
		printf("%d=%d", N, N);
	}
	else {
		printf("%d=", N);
		for (int i = 0; i < resList.size(); ++i) {
			if (i > 0) {
				printf("*");
			}
			if (resList[i].second > 1) {
				printf("%d^%d", resList[i].first, resList[i].second);
			}
			else {
				printf("%d", resList[i].first);
			}
		}
	}
	
  return 0;
}