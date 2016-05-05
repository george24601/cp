#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 10354 avoiding your boss
//SSSP
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxSize = 151;

int state[MaxSize][MaxSize];

int m;

int DP_r(int p, int n) {
	if (state[p][n] != 0)
		return state[p][n];

	if (n == 1)
		return 2;

	int next = (m - 1) % n + 1;

	if (p == next)
		return 1;
	else if (p > next)
		return DP_r(p - next, n - 1);
	else
		return DP_r(p - next + n, n - 1);
}

int main() {
	//freopen("C:\\Test\\out.txt", "w", stdout);
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int ans[147] = { 2, 5, 2, 4, 3, 11, 2, 3, 8, 16, 4, 21, 6, 5, 2, 11, 20, 34,
			8, 15, 10, 7, 13, 11, 13, 45, 18, 23, 8, 3, 2, 25, 75, 42, 13, 5,
			23, 13, 50, 16, 18, 89, 38, 8, 39, 30, 29, 38, 7, 45, 23, 137, 46,
			63, 17, 48, 5, 46, 34, 140, 33, 39, 2, 28, 29, 79, 33, 48, 3, 10,
			46, 120, 6, 37, 17, 8, 44, 15, 160, 20, 35, 144, 104, 179, 153, 24,
			8, 265, 19, 9, 62, 7, 139, 19, 44, 93, 182, 27, 158, 185, 193, 17,
			82, 3, 11, 43, 55, 21, 41, 146, 29, 80, 59, 8, 29, 66, 19, 160, 59,
			28, 129, 127, 120, 72, 45, 157, 2, 63, 127, 81, 318, 513, 98, 28,
			32, 231, 236, 411, 26, 45, 5, 303, 228, 66, 9, 205, 65 };

	int n;
	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%d\n", ans[n - 3]);
		/*
		 int interval = 1;
		 while (true) {
		 m = interval;

		 LPE(i, 1, n)
		 memset(state, 0, sizeof(state));

		 int result = DP_r(1, n - 1);

		 if (result == 2) {
		 printf("%d\n", interval);
		 break;
		 } else
		 interval++;
		 }
		 */
	}

	return 0;
}
