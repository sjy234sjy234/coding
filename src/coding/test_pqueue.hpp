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


struct fruit {
	string name;
	int price;

	bool operator < (const fruit& b) const {
		return price < b.price;
	}

	bool operator > (const fruit& b) const {
		return price > b.price;
	}

	bool operator == (const fruit& b) const {
		return price == b.price;
	}
};


int test_pqueue_int() {
	//std::priority_queue<int> pqueue;
	//std::priority_queue<int, vector<int>, less<int>> pqueue;
	std::priority_queue<int, vector<int>, greater<int>> pqueue;
	pqueue.push(1);
	pqueue.push(4);
	pqueue.push(4);
	pqueue.push(3);

	while (!pqueue.empty())
	{
		printf("%d\n", pqueue.top());
		pqueue.pop();
	}
	
	return 0;
}

int test_pqueue_struct() {

	//std::priority_queue<fruit> pqueue;
	//std::priority_queue<fruit, vector<fruit>, less<fruit>> pqueue;
	std::priority_queue<fruit, vector<fruit>, greater<fruit>> pqueue;

	pqueue.push({ "00", 1 });
	pqueue.push({ "01", 4 });
	pqueue.push({ "02", 4 });
	pqueue.push({ "03", 3 });

	while (!pqueue.empty())
	{
		printf("%s %d\n", pqueue.top().name.c_str(), pqueue.top().price);
		pqueue.pop();
	}

	return 0;
}


int test_pqueue() {
	//return test_pqueue_int();
	return test_pqueue_struct();
}