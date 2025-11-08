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


int gcd(const int a, const int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int test_num_gcd() {
	//int a = 4, b = 6;
	int a = 3, b = 9;
	int res_gcd = gcd(a, b);
	int res_lcm = a * b / res_gcd;
	printf("%d %d -> %d %d \n", a, b, res_gcd, res_lcm);
	return 0;
}

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

int test_num_isprime() {
	for (int i = 0; i < 100; ++i) {
		printf("%d %d\n", i, isprime(i));
	}
	return 0;
}

int test_num_primefilter() {
	const int N = 100;
	bool flagList[N] = {};
	bool isConfirm[N] = {};
	for (int i = 0; i < 100; ++i) {
		if (!isConfirm[i]) {
			flagList[i] = isprime(i);
			if (flagList[i]) {
				int j = i << 1;
				while (j < N) {
					flagList[j] = false;
					isConfirm[j] = true;
					j += i;
				}
			}
		}
		isConfirm[i] = true;
	}
	for (int i = 0; i < N; ++i) {
		printf("%d %d\n", i, flagList[i]);
	}
	return 0;
}


int test_num() {
	//return test_num_gcd();
	//return test_num_isprime();
	return test_num_primefilter();
}