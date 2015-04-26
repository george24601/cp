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

const int MaxN = 80;
const int MaxK = 6;

#define maxWin 20

int n, k;

int grid[MaxN][MaxN];

int total[MaxN][MaxN][MaxK][2][2];

int DFS(int row, int col, int canLeft, int canRight, int negSoFar) {
	int calced = total[row][col][negSoFar][canLeft][canRight];

	if (-INF != calced)
		return calced;

	int toReturn = -INF;

	if (row == n - 1) {

		int total = 0;
		int totalNeg = 0;
		LP(i, col, n)
		{
			if (grid[row][i] < 0)
				totalNeg++;

			total += grid[row][i];
		}

		if (totalNeg + negSoFar > k)
			toReturn = INF;
		else
			toReturn = total;

	} else {

		int newNegSoFar = grid[row][col] < 0 ? negSoFar + 1 : negSoFar;

		if (newNegSoFar <= k) {

			if (canLeft && col > 0) {
				int goLeft = DFS(row, col - 1, canLeft, 0, newNegSoFar);

				if (goLeft != INF)
					toReturn = max(toReturn, goLeft + grid[row][col]);
			}

			if (canRight && col < n - 1) {
				int goLeft = DFS(row, col + 1, 0, canRight, newNegSoFar);
				if (goLeft != INF)
					toReturn = max(toReturn, goLeft + grid[row][col]);
			}

			if (row < n - 1) {
				int goLeft = DFS(row + 1, col, 1, 1, newNegSoFar);
				if (goLeft != INF)
					toReturn = max(toReturn, goLeft + grid[row][col]);
			}
		}
	}

	if(-INF == toReturn)
		toReturn = INF;

	total[row][col][negSoFar][canLeft][canRight] = toReturn;
	return toReturn;
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseN = 0;

	while (scanf("%d %d", &n, &k)) {

		if (n == 0 && k == 0)
			break;

		caseN++;

		LP(i, 0,n)
		{
			LP(j, 0, n)
				scanf("%d", &grid[i][j]);
		}

		LP(i, 0, n)
		{
			LP(j, 0, n)
			{
				LPE(nn, 0, k)
				{
					total[i][j][nn][0][1] = -INF;
					total[i][j][nn][1][0] = -INF;
					total[i][j][nn][0][0] = -INF;
					total[i][j][nn][1][1] = -INF;
				}
			}
		}

		int result = DFS(0, 0, 0, 1, 0);

		if (result == INF)
			printf("Case %d: impossible\n", caseN);
		else
			printf("Case %d: %d\n", caseN, result);

	}

	return 0;
}
