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

const int MaxSize = 8;

#define NumPos 64

int dist[NumPos][NumPos];

void TryLink(int i, int row, int col) {
	if (row < 0 || row >= MaxSize)
		return;

	if (col < 0 || col >= MaxSize)
		return;

	dist[i][(row * MaxSize) + col] = 1;
}

void PreCompute() {
	LP(i, 0, NumPos)
	{
		LP(j, 0, NumPos)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}

	}

	LP(i, 0, NumPos)
	{
		int row = i / MaxSize;
		int col = i % MaxSize;

		TryLink(i, row + 1, col + 2);
		TryLink(i, row + 1, col - 2);
		TryLink(i, row - 1, col + 2);
		TryLink(i, row - 1, col - 2);
		TryLink(i, row + 2, col + 1);
		TryLink(i, row + 2, col - 1);
		TryLink(i, row - 2, col + 1);
		TryLink(i, row - 2, col - 1);
	}

	LP(i, 0, NumPos)
	{
		LP(from, 0, NumPos)
		{
			LP(to, 0, NumPos)
			{
				int firstDist = dist[from][i];
				int secondDist = dist[i][to];

				if (firstDist == INF || secondDist == INF)
					continue;

				dist[from][to] = min(dist[from][to], firstDist + secondDist);
			}
		}

	}

}

int ToIndex(char * b) {
	int row = b[0] - 'a';
	int col = b[1] - '1';

	return (row * MaxSize) + col;
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	PreCompute();

	char b1[10], b2[10];
	while (scanf("%s %s", b1, b2) == 2)
		printf("To get from %s to %s takes %d knight moves.\n", b1, b2,
				dist[ToIndex(b1)][ToIndex(b2)]);

	return 0;
}
