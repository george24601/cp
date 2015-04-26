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
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int n;
	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		int interval = 1;
		while (true) {
			m = interval;

			LPE(i, 1, n)
				memset(state, 0, sizeof(state));

			int result = DP_r(12, n - 1);

			if (result == 2) {
				printf("%d\n", interval);
				break;
			} else
				interval++;
		}
	}

	return 0;
}
