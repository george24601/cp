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

const int MaxN = 50;
const int MaxM = 30;

#define maxWin 20
int n, m, k;

int good[MaxN][MaxM];
SAL adj;

int DFS(int city, int given) {
	if (good[city][given] >= 0) {

	} else if (given == maxWin) {
		good[city][given] = city == n - 1 ? 1 : 0;
	} else if (city == n - 1 && given >= k) {
		good[city][given] = 1;
	} else {

		good[city][given] = 0;

		LP(i, 0, adj[city].size())
		{
			int to = adj[city][i];

			if (DFS(to, given + 1) == 1) {
				good[city][given] = 1;
			}
		}
	}

	return good[city][given];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d %d", &n, &m, &k)) {

		if (n == 0 && m == 0 && k == 0)
			break;

		SAL newAdj(n);

		adj = newAdj;

		LP(i, 0, n)
			memset(good[i], -1, sizeof(good[i]));

		LP(i,0, m)
		{
			int from, to;
			scanf("%d %d", &from, &to);

			adj[from].push_back(to);
		}

		DFS(0, 1);

		LPE(i, k, maxWin)
		{
			if (good[n - 1][i] == 1) {
				printf("%d\n", i);
				goto Next;
			}
		}

		printf("LOSER\n");

		Next: continue;
	}

	return 0;
}
