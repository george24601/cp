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
typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 20010;

#define maxWin 20

int n;

int ls[MaxN];
int rs[MaxN];

int dist[MaxN][2];

int DFS(int row, int left) {

	if (dist[row][left] >= 0) {

	} else if (row == n) {
		dist[row][1] = n - ls[n];
		dist[row][0] = n - ls[n] + rs[n] - ls[n];
	} else {
		int curDist = rs[row] - ls[row];

		int ending = 1 == left ? rs[row] : ls[row];

		int leftDist = abs(ending - ls[row + 1]) + 1  + curDist + DFS(row + 1, 1);
		int rightDist = abs(ending - rs[row + 1]) + 1 + curDist + DFS(row + 1, 0);

		dist[row][left] = min(leftDist, rightDist);
	}

	return dist[row][left];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d", &n)) {

		if (n == 0)
			break;

		LPE(i, 1, n)
		{
			scanf("%d %d", &ls[i], &rs[i]);

			memset(dist[i], -1, sizeof(dist[i]));
		}

		int goLeft = (ls[1] - 1) + DFS(1, 1);

		int goRight = (rs[1] - 1) + DFS(1, 0);

		printf("%d\n", min(goLeft, goRight));
	}

	return 0;
}
