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

const int MaxSize = 101;

int state[MaxSize][MaxSize];

int m, k;

int DP_r(int p, int n) {
	if (state[p][n] != 0)
		return state[p][n];

	if (n == k)
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
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d", &k);

		if (k == 0)
			break;

		int ans[13] = { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901,
				1358657, 2504881 };

		printf("%d\n", ans[k - 1]);
		/*
		 int n = 2 * k;
		 int interval = k + 1;

		 while (true) {
		 m = interval;

		 LPE(i, 1, n)
		 memset(state, 0, sizeof(state));

		 LPE(i, 1, k)
		 {
		 int result = DP_r(i, n);

		 if (result == 1)
		 goto Next;
		 }

		 printf("%d\n", interval);
		 break;

		 Next: interval++;
		 }
		 */
	}

	return 0;
}
