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


int test_gcd() {
	int a = 4, b = 6;
	//int a = 3, b = 9;
	int res_gcd = gcd(a, b);
	int res_lcm = a * b / res_gcd;
	printf("%d %d -> %d %d \n", a, b, res_gcd, res_lcm);
	return 0;
}