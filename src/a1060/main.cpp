#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;



void transfer(const int N, string str, string &strRes) {
  int k = 0;
  while (k < str.length() - 1 && str[k] == '0') {
    ++k;
  }
  str = str.substr(k);
  if (str[0] == '.') {
    str = "0" + str;
  }
  //printf("remove prior 0: %s, k: %d\n", str.c_str(), k);

  int floatPos = str.find(".");
  int numPow = -1;
  int i = 0;
  while (i < str.length()) {
    if (str[i] >= '1' && str[i] <= '9') {
      break;
    }
    ++i;
  }

  if (floatPos == string::npos) {
    numPow = str.length();
  }
  else {
    //numPow = floatPos;
    if (i < floatPos) {
      numPow = floatPos;
    }
    else {
      numPow = floatPos - i + 1;
    }
  }
  // 此题有一个深坑,就是当输入是0的时候,必须输出0.0000...*10^0;
  if (i >= str.length()) {
    numPow = 0;
  }
 
  int cnt = 0;
  vector<int> numRes;
  while (i < str.length() && cnt < N) {
    if (i != floatPos) {
      numRes.push_back(str[i] - '0');
      ++cnt;
    }
    ++i;
  }
  while (cnt < N) {
    numRes.push_back(0);
    ++cnt;
  }

  if (N > 0) {
    strRes = "0.";
  }
  else {
    strRes = "0";
  }
  for (int j = 0; j < numRes.size(); ++j) {
    strRes += numRes[j] + '0';
  }

  strRes += "*10^" + to_string(numPow);
}


int main() {

  int N;
  string str1, str2;
  string str1Res, str2Res;
  cin >> N >> str1 >> str2;
  //printf("inputs: %d %s %s\n", N, str1.c_str(), str2.c_str());

  transfer(N, str1, str1Res);
  transfer(N, str2, str2Res);

  if (str1Res == str2Res) {
    printf("YES %s", str1Res.c_str());
  }
  else {
    printf("NO %s %s", str1Res.c_str(), str2Res.c_str());
  }

  return 0;
}