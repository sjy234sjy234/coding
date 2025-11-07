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
using namespace std;

void sort_merge_recursive(int nums[], const int start, const int end) {
	if (start >= end) {
		return;
	}
	else {
		// merge left & right separately
		int mid = (start + end) / 2;
		sort_merge_recursive(nums, start, mid);
		sort_merge_recursive(nums, mid + 1, end);

		// merge together
		int i = start;
		int j = mid + 1;
		const int len = end - start + 1;
		std::vector<int> tempNums(len);
		int k = 0;
		while (i <= mid && j <= end) {
			if (nums[i] < nums[j]) {
				//printf("selecting i %d\n", nums[i]);
				tempNums[k++] = nums[i++];
			}
			else {
				//printf("selecting j %d\n", nums[j]);
				tempNums[k++] = nums[j++];
			}
		}
		while (i <= mid) {
			//printf("selecting ip %d\n", nums[i]);
			tempNums[k++] = nums[i++];
		}
		while (j <= end) {
			//printf("selecting jp %d\n", nums[j]);
			tempNums[k++] = nums[j++];
		}

		//k = 0;
		//while (k < len) {
		//	nums[start + k] = tempNums[k];
		//	printf("%d ", tempNums[k]);
		//	++k;
		//}
		//printf("\n");

		k = 0;
		while (k < len) {
			nums[start + k] = tempNums[k];
			++k;
		}
	}
}


void sort_merge_nonrecursive(int nums[], const int len) {
	int merge_size = 2;
	while (merge_size / 2 < len) {
		//printf("merge_size: %d\n", merge_size);
		for (int start = 0; start < len; start += merge_size) {
			int mid = start + merge_size / 2;
			int end = min(len, mid + merge_size / 2);
			int tempLen = end - start;

			//printf("start: %d, mid: %d, end: %d, tempLen: %d\n", start, mid, end, tempLen);
			std::vector<int> tempNums(tempLen);
			int i = start;
			int j = mid;
			int k = 0;
			while (i < mid && j < end) {
				if (nums[i] < nums[j]) {
					//printf("set i: %d %d\n", i, nums[i]);
					tempNums[k++] = nums[i++];
				}
				else {
					//printf("set j: %d %d\n", j, nums[j]);
					tempNums[k++] = nums[j++];
				}
			}
			while (i < mid) {
				//printf("set it: %d %d\n", i, nums[i]);
				tempNums[k++] = nums[i++];
			}
			while (j < end) {
				//printf("set jt: %d %d\n", j, nums[j]);
				tempNums[k++] = nums[j++];
			}

			k = 0;
			while (k < tempLen) {
				//printf("start + k: %d, k: %d, tempNum: %d\n", start + k, k, tempNums[k]);
				nums[start + k] = tempNums[k];
				++k;
			}

			//for (int i = 0; i < len; ++i) {
			//	printf("%d ", nums[i]);
			//}
			//printf("\n");

		}

		merge_size *= 2;
	}
}

int test_sort_merge() {
	printf("test_sort_merge\n");

	int nums[7] = { 66, 12, 33, 57, 64, 27, 18 };
	//sort_merge_recursive(nums, 0, 6);
	sort_merge_nonrecursive(nums, 7);
	for (int i = 0; i < 7; ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}


int test_sort() {
  return test_sort_merge();
}