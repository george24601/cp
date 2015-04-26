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
using namespace std;

//UVa 11561 Getting Gold
//DFS
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

int W, H;

const int MaxSize = 51;

char pixels[MaxSize][MaxSize];

bool visited[MaxSize][MaxSize];

bool Valid(int row, int col) {
	if (row < 0 || row >= H)
		return false;
	if (col < 0 || col >= W)
		return false;

	return true;
}

int V_r(int h, int w) {
	if (visited[h][w])
		return 0;
	else
		visited[h][w] = true;

	int toReturn = (pixels[h][w] == 'G') ? 1 : 0;

	int nextHs[13] = { h - 1, h, h, h + 1 };
	int nextWs[13] = { w, w + 1, w - 1, w };
	int choices = 4;

	LP(i, 0, choices)
	{
		int nextH = nextHs[i];
		int nextW = nextWs[i];

		if (Valid(nextH, nextW) && pixels[nextH][nextW] == 'T')
			return toReturn;
	}

	LP(i, 0, choices)
	{
		int nextH = nextHs[i];
		int nextW = nextWs[i];

		if (Valid(nextH, nextW) && pixels[nextH][nextW] != '#')
			toReturn += V_r(nextH, nextW);
	}

	return toReturn;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &W, &H) == 2) {

		LP(h, 0, H)
		{
			scanf("%s", pixels[h]);

			LP(w, 0, W)
				visited[h][w] = false;
		}

		int count = 0;
		LP(h, 0, H)
		{
			LP(w, 0, W)
			{
				if (pixels[h][w] == 'P')
					count = V_r(h, w);
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

