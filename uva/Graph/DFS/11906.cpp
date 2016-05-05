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
using namespace std;

//UVa 11906 Knight in war grid
//graph - DFS
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

int R, C, M, N;

bool visited[101][101];
int neighbors[101][101];
bool water[101][101];

bool Valid(int x, int y) {
	if (x < 0 || x >= R)
		return false;

	if (y < 0 || y >= C)
		return false;

	if (water[x][y])
		return false;

	return true;
}

void v_r(int x, int y) {
	if (visited[x][y])
		return;
	else
		visited[x][y] = true;

	if (M == N) {
		int nextXs[10] = { x + M, x + M, x - M, x - M };
		int nextYs[10] = { y + M, y - M, y + M, y - M };
		int choices = 4;

		int neighborCount = 0;

		LP(i, 0, choices)
		{
			if (Valid(nextXs[i], nextYs[i])) {
				neighborCount++;
				v_r(nextXs[i], nextYs[i]);
			}
		}

		neighbors[x][y] = neighborCount;

	} else if (M == 0) {
		int nextXs[10] = { x, x, x + N, x - N };
		int nextYs[10] = { y + N, y - N, y, y };
		int choices = 4;
		int neighborCount = 0;

		LP(i, 0, choices)
		{
			if (Valid(nextXs[i], nextYs[i])) {
				neighborCount++;
				v_r(nextXs[i], nextYs[i]);
			}
		}

		neighbors[x][y] = neighborCount;

	} else if (N == 0) {
		int nextXs[10] = { x, x, x + M, x - M };
		int nextYs[10] = { y + M, y - M, y, y };
		int choices = 4;
		int neighborCount = 0;

		LP(i, 0, choices)
		{
			if (Valid(nextXs[i], nextYs[i])) {
				neighborCount++;
				v_r(nextXs[i], nextYs[i]);
			}
		}

		neighbors[x][y] = neighborCount;

	} else {
		int nextXs[10] = { x + N, x + N, x - N, x - N, x + M, x + M, x - M, x
				- M };
		int nextYs[10] = { y + M, y - M, y + M, y - M, y + N, y - N, y + N, y
				- N };
		int choices = 8;
		int neighborCount = 0;

		LP(i, 0, choices)
		{
			if (Valid(nextXs[i], nextYs[i])) {
				neighborCount++;
				v_r(nextXs[i], nextYs[i]);
			}
		}

		neighbors[x][y] = neighborCount;
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		scanf("%d %d %d %d", &R, &C, &M, &N);

		LP(i, 0, R)
		{
			LP(j, 0, C)
			{
				visited[i][j] = false;
				neighbors[i][j] = -1;
				water[i][j] = false;
			}
		}

		int W;
		scanf("%d", &W);

		LP(i, 0, W)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			water[x][y] = true;
		}

		v_r(0, 0);
		int odd = 0;
		int even = 0;

		LP(i, 0, R)
		{
			LP(j, 0, C)
			{
				int neighborC = neighbors[i][j];

				if (neighborC < 0)
					continue;
				else if (neighborC % 2 == 0)
					even++;
				else
					odd++;
			}
		}

		printf("Case %d: %d %d\n", caseNum, even, odd);
	}

	return 0;
}

