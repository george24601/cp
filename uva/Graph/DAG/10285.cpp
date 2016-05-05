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

const int MaxSize = 110;

int board[MaxSize][MaxSize];
int best[MaxSize][MaxSize];

int R, C;

bool Valid(int row, int col, int curV) {
	if (row < 0 || row >= R)
		return false;
	if (col < 0 || col >= C)
		return false;

	if (board[row][col] >= curV)
		return false;

	return true;
}

int DP_r(int row, int col) {
	if (best[row][col] >= 0)
		return best[row][col]; //calced already
	else
		best[row][col] = 0;

	int curV = board[row][col];

	for (int i = -1; i <= 1; i++) {
		if(i == 0)
			continue;

		int newRow = row + i;

		if (Valid(newRow, col, curV))
			best[row][col] = max(best[row][col], DP_r(newRow, col));

		int newCol = col + i;
		if (Valid(row, newCol, curV))
			best[row][col] = max(best[row][col], DP_r(row, newCol));
	}

	best[row][col] += 1;

	return best[row][col];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;

	scanf("%d", &numCase);

	LPE(caseN, 1, numCase)
	{
		char name[1000];
		scanf("%s %d %d", name, &R, &C);

		LP(i, 0, R)
		{
			LP(j, 0, C)
			{
				scanf("%d", &board[i][j]);
				best[i][j] = -1;
			}
		}

		int maxV = 0;
		LP(i, 0, R)
		{
			LP(j, 0, C)
				maxV = max(maxV, DP_r(i, j));
		}

		printf("%s: %d\n", name, maxV);
	}

	return 0;
}
