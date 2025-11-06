# pragma

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cstring>

const double g_eps = 1e-8;
const double g_pi = acos(-1.0);

struct StudentInfo {
  int id;
  char gender;
  char name[20];
  char major[20];
  StudentInfo() {};
  StudentInfo(const int _id, const char _gender, const char _name[],const char _major[]) {
    id = _id;
    gender = _gender;
    strcpy(name, _name);
    strcpy(major, _major);
  }
}Alice, Bob, stu[1000];


bool isFloatEqual(const float a, const float b) {
  return abs(a - b) < g_eps;
}

bool isFloatMore(const float a, const float b) {
  return a - b > g_eps;
}

bool isFloatMoreEqu(const float a, const float b) {
  return a - b > -g_eps;
}

bool isFloatLess(const float a, const float b) {
  return a - b < - g_eps;
}

bool isFloatLessEqu(const float a, const float b) {
  return a - b < g_eps;
}


int test_io() {
  // scanf:  %d, %lld, %f, %lf, %c, %s
  // printf: %d, %lld, %f,  %f, %c, %s, %md, %0md, %.mf

  //int a, b;
  //scanf("%d%d", &a, &b);
  //printf("%d\n", a+b);

  //char str[10];
  //scanf("%s", str);
  //printf("str: %s\n", str);

  char str2[5][5];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      str2[i][j] = getchar();
    }
    getchar();
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      putchar(str2[i][j]);
    }
    putchar('\n');
  }

  return 0;
}

int test_io_char() {
  char c1, c2, c3;
  c1 = getchar();
  getchar();
  c2 = getchar();
  c3 = getchar();
  putchar(c1);
  putchar(c2);
  putchar(c3);
  return 0;
}

int test_variale() {
  int num = 5;
  long long longnum = 123456789012345LL;
  printf("num: %d, longnum: %lld\n", num, longnum);
  float fl = 3.1415;
  double db = 3.1415926536;
  printf("float: %.6f, double: %.12f\n", fl, db);
  char c1 = 'z', c2 = 'j', c3 = 117;
  printf("c1: %c, c2: %c, c3: %c\n", c1, c2, c3);
  char str1[25] = "Wo ai de ren bu ai wo";
  char str2[25] = "so sad a story it is.";
  printf("str1: %s, str2: %s\n", str1, str2);
  bool flag1 = 0, flag2 = true;
  int a = 1, b = 1;
  printf("flag1: %d, flag2: %d, a==b: %d", flag1, flag2, a == b);
  return 0;
}

int test_var_trans() {
  double r = 12.56;
  int a = 3, b = 5;
  printf("%d\n", (int)r);
  printf("%d\n", a / b);
  printf("%.1f\n", (double)a / (double)b);
  return 0;
}

int test_var_bitop() {
  // ^位异或、~位取反
  const int INF0 = 0x3fffffff;
  const int INF1 = (1 << 30) - 1;
  const int INF2 = (1 << 31) - 1;
  const int INF3 = INT_MAX;
  const long long INF4 = 1LL << 31;
  printf("INF0: %d, INF1: %d, INF2: %d, INF3: %d, INF4: %lld\n", INF0, INF1, INF2, INF3, INF4);
  return 0;
}

int test_math() {
  // fabs(double x);
  // floor(double x);
  // ceil(double x);
  // pow(double r, double p);
  // sqrt(double x);
  // log(double x);
  // sin(double x);
  // cos(double x);
  // tan(double x);
  // asin(double x);
  // acos(double x);
  // atan(double x);
  // round(double x);
  printf("g_pi: %.10f\n", g_pi);
  return 0;
}

int test_array() {
  int a[10] = { 1 };
  int b[10];
  int c[5][6] = { {3, 1, 2}, {8, 4}, {}, {1, 2, 3, 4, 5} };
  char str[15] = { 'G', 'o', 'o', 'd' };
  for (int i = 0; i < 10; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n\n");
  for (int i = 0; i < 10; ++i) {
    printf("%d ", b[i]);
  }
  printf("\n\n");
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  printf("%s\n", str);
  return 0;
}

int test_sort_bubble() {
  int a[10] = { 3, 1, 4, 5, 2 };
  for (int i = 1; i < 10; ++i) {
    for (int j = i; j > 0; --j) {
      if (a[j] < a[j - 1]) {
        int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
    }
  }
  for (int i = 1; i < 10; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

int test_memset() {
  // only used with 0, -1 for int array, or used for char array
  int a[5] = { 1, 2, 3, 4, 5 };
  for (int i = 0; i < 5; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 5; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  memset(a, -1, sizeof(a));
  for (int i = 0; i < 5; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("sizeof(a): %d, sizeof(float): %d.\n", sizeof(a), sizeof(float));
  return 0;
}

int test_cstring() {
  // strlen()
  // strcmp() -1(<), 0(==), 1(>)
  // strcpy()
  // strcat()
  return 0;
}

void change(int a[], int b[][5]) {
  a[0] = 1;
  a[1] = 3;
  a[2] = 5;
  b[0][0] = 1;
}

int test_func_array() {
  int a[10] = {};
  int b[6][5] = {};
  change(a, b);
  for (int i = 0; i < 10; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n\n");
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 5; ++j) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}

int fibonacci(int n) {
  if (n < 2) {
    return n;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int test_func_recursive() {
  //int n = 10;
  int n = 2;
  int res = fibonacci(n);
  printf("%d\n%d\n", n, res);
  return 0;
}

int test_struct() {
  Alice = { 5, 'F', "Alice", "Math" };
  Bob = { 1, 'M', "Bob", "English" };
  StudentInfo Jack(2, 'M', "Jack", "Physics");
  stu[0] = Alice;
  stu[1] = Bob;
  stu[2] = Jack;
  for (int i = 0; i < 4; ++i) {
    printf("%d, %c, %s, %s\n", stu[i].id, stu[i].gender, stu[i].name, stu[i].major);
  }
  return 0;
}

int test_cmp_float() {
  float a = 0.3, b = 0.3;
  printf("%d, %d\n", a == b, isFloatEqual(a, b));
  // after complex calculation, == becomes unreliable
  double db1 = 4 * asin(sqrt(2.0) / 2);
  double db2 = 3 * asin(sqrt(3.0) / 2);
  printf("%d, %d\n", db1 == db2, isFloatEqual(db1, db2));
  return 0;
}


int test_cbasic() {
  //return test_io();
  //return test_io_char();
  //return test_variale();
  //return test_var_trans();
  //return test_var_bitop();
  return test_math();
  //return test_array();
  //return test_sort_bubble();
  //return test_memset();
  //return test_func_array();
  //return test_func_recursive();
  //return test_struct();
  //return test_cmp_float();
}