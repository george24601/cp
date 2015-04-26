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

const int MaxSize = 40;

int m, n;

bool calced [MaxSize][MaxSize];
L ways[MaxSize][MaxSize];
bool canGo[MaxSize][MaxSize][2]; //0 is North, 1 is East
int startX, startY, endX, endY;

L DP_r(int x, int y)
{
	if(calced[x][y])
		return ways[x][y];
	else
		calced[x][y] = true;

	if (x == endX && y == endY)
	{
		ways[x][y] = 1;
		return ways[x][y];
	}
	else
		ways[x][y] = 0;

	if(canGo[x][y][0])
		ways[x][y] += DP_r(x, y+ 1);

	if(canGo[x][y][1])
		ways[x][y] += DP_r(x + 1, y);

	return ways[x][y];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d", &n);

		LPE(i, 1, n)
		{
			LPE(j, 1, n)
			{
				canGo[i][j][0] = true;
				canGo[i][j][1] = true;
				calced[i][j] = false;
			}
		}

		LPE(i, 1, n)
		{
			canGo[n][i][1] = false;
			canGo[i][n][0] = false;
		}

		scanf("%d %d", &startX, &startY);
		scanf("%d %d", &endX, &endY);
		int W;
		scanf("%d", &W);

		LP(i, 0, W)
		{
			int x, y;
			char c;
			scanf("%d %d %c", &x, &y, &c);

			if (c == 'N')
				canGo[x][y][0] = false;
			else if (c == 'S' && y > 1)
				canGo[x][y - 1][0] = false;
			else if (c == 'E')
				canGo[x][y][1] = false;
			else if (c == 'W' && x > 1)
				canGo[x - 1][y][1] = false;
		}

		L result = DP_r(startX, startY);
		printf("%llu\n", result);
	}

	return 0;
}
