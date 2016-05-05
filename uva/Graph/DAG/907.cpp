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

const int MaxN = 610;
const int MaxK = 310;

int dist[MaxN][MaxK];

int consDist[MaxN];
int accuDist[MaxN];
int n;

int DFS_r(int curStop, int k) {
	if (dist[curStop][k] >= 0)
		return dist[curStop][k];

	if (k == 0) {
		dist[curStop][k] = accuDist[n + 1] - accuDist[curStop];
	} else if (curStop + k > n) {
		dist[curStop][k] = INF;
	} else {

		dist[curStop][k] = INF;

		LPE(i, curStop + 1, n)
		{
			int secondPart = DFS_r(i, k - 1);

			if (secondPart == INF)
				continue;

			int firstPart = accuDist[i] - accuDist[curStop];

			dist[curStop][k] = min(dist[curStop][k], max(secondPart, firstPart));
		}
	}

	return dist[curStop][k];

}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int k;
	while (scanf("%d %d", &n, &k) == 2) {
		consDist[0] = 0;

		LPE(i, 0, n+ 1)
		{
			LPE(j, 0, k)
				dist[i][j] = -1;
		}

		LPE(i, 1, n+ 1)
		{
			scanf("%d", &consDist[i]);

			accuDist[i] = accuDist[i - 1] + consDist[i];
		}

		int result = DFS_r(0, k);
		printf("%d\n", result);

	}

	return 0;
}
