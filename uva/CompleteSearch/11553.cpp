#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11553  grid game
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 1000;

int grid[8][8];
int sumRow[8];
int sumCol[8];
int pos[8];
int n;

int maxVal;

void Process_r(int colIndex, int used) {

	if (colIndex >= n) {
		int total = 0;

		LP(i, 0, n)
			total += grid[pos[i]][i];

		maxVal = Min(maxVal, total);

		return;
	}

	LP(i, 0, n)
	{
		if (((used >> i) & 1) == 1)
			continue;

		pos[colIndex] = i;


		Process_r(colIndex + 1, (used | (1 << i)));
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	LP(caseN, 0, t)
	{
		scanf("%d", &n);

		LP(i, 0, n)
		{
			LP(j, 0, n)
				scanf("%d", &grid[i][j]);
		}

		LP(i, 0, n)
		{
			sumRow[i] = 0;
			sumCol[i] = 0;

			LP(j, 0, n)
			{
				sumRow[i] += grid[i][j];
				sumCol[i] += grid[j][i];
			}
		}

		maxVal = 2000000000;
		Process_r(0, 0);

		printf("%d\n", maxVal);
	}

	return 0;
}
