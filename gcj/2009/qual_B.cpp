#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
#define INF 2000000000
#define Ep 1e-9

/*
 */

int H, W, T;
int const MaxH = 100;
int const MaxW = 100;

int height[MaxH][MaxW];
int label[MaxH][MaxW];
int from[MaxH][MaxW];
int to[MaxH][MaxW];

int curLabel;

/*
 problems i run into:
 1. unsuccessfully try to reverse the precedence
 2. try both going down and up => going down alone is enough to summerize it
 */

PII lowest(int i, int j) {
	int curLow = height[i][j];
	PII winner = PII(-1, -1);

	int nextI = i + 1;
	int nextJ = j;
	if (i < H - 1 && height[nextI][nextJ] < curLow) {
		curLow = height[nextI][nextJ];
		winner = PII(nextI, nextJ);
	}

	nextI = i;
	nextJ = j + 1;
	if (j < W - 1 && height[nextI][nextJ] < height[i][j] && height[nextI][nextJ] <= curLow) {
		curLow = height[nextI][nextJ];
		winner = PII(nextI, nextJ);
	}

	nextI = i;
	nextJ = j - 1;
	if (j > 0 && height[nextI][nextJ] < height[i][j] && height[nextI][nextJ] <= curLow) {
		curLow = height[nextI][nextJ];
		winner = PII(nextI, nextJ);
	}

	nextI = i - 1;
	nextJ = j;
	if (i > 0 && height[nextI][nextJ] < height[i][j] && height[nextI][nextJ] <= curLow) {
		curLow = height[nextI][nextJ];
		winner = PII(nextI, nextJ);
	}

	return winner;
}

void tryLabel(int i, int j) {
	if (label[i][j])
		return;

	PII next = lowest(i, j);

	if (next.first < 0) {
		label[i][j] = curLabel;
		curLabel++;
	} else {
		tryLabel(next.first, next.second);
		label[i][j] = label[next.first][next.second];
	}
}

int main() {
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/qual_B.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	cin >> T;

	LPE(cn, 1, T)
	{
		cin >> H >> W;

		LP(i, 0, H)
		{
			memset(height[i], 0, sizeof(height[i]));
			memset(label[i], 0, sizeof(label[i]));

			LP(j, 0, W)
				cin >> height[i][j];
		}

		curLabel = 1;

		LP(i, 0, H)
		{
			LP(j, 0, W)
				tryLabel(i, j);
		}

		printf("Case #%d:\n", cn);
		LP(i, 0, H)
		{
			LP(j, 0, W)
			{
				printf("%c", label[i][j] - 1 + 'a');
				if (j == W - 1)
					printf("\n");
				else
					printf(" ");
			}
		}
	}

	return 0;
}
