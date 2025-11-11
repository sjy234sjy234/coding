# pragma

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;



int test_algorithm_reverse() {
	int a[10] = { 10, 11, 12, 13, 14, 15 };
	vector<int> b = { 10, 11, 12, 13, 14, 15 };

	reverse(a + 1, a + 4);
	for (int i = 0; i < 6; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	reverse(b.begin() + 1, b.end() - 2);
	for (int i = 0; i < b.size(); ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}

int test_algorithm_npermute() {
	int a[10] = { 1, 2, 3 };
	//int a[10] = { 3, 2, 1 };
	//int a[10] = { 1, 1, 1 };
	do {
		printf("%d %d %d\n", a[0], a[1], a[2]);
	} while (next_permutation(a, a + 3));
	return 0;
}

bool cmp(const int a, const int b) {
	return a > b;
}

int test_algorithm_sort() {
	int a[5] = { 3, 1, 4, 2 };
	std::vector<int> b = { 3, 1, 4, 2 };

	//sort(a, a + 4);
	sort(a, a + 4, cmp);
	for (int i = 0; i < 4; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	sort(b.begin() + 1, b.end());
	//sort(b.begin() + 1, b.end(), cmp);
	for (int i = 0; i < b.size(); ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");

	return 0;
}


int test_algorithm() {
	//return test_algorithm_reverse();
	//return test_algorithm_npermute();
	return test_algorithm_sort();
}