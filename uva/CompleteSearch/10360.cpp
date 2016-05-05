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

//UVa 10360 rat attack
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int N;
int d;
int curMax;
int maxRow;
int maxCol;

const int MaxSize = 1025;
int rats[MaxSize + 1][MaxSize + 1];
int results[MaxSize + 1][MaxSize + 1];

void PopResult(int row, int col) {
	for (int rowD = -d; rowD <= d; rowD++) {
		int rowToUpdate = row + rowD;

		if (rowToUpdate < 0 || rowToUpdate >= MaxSize)
			continue;
		for (int colD = -d; colD <= d; colD++) {
			int colToUpdate = col + colD;

			if (colToUpdate < 0 || colToUpdate >= MaxSize)
				continue;

			results[rowToUpdate][colToUpdate] += rats[row][col];

		}
	}
}

void Process() {

	LP(row, 0, MaxSize)
	{
		LP(col, 0, MaxSize)
		{
			if (rats[row][col] == 0)
				continue;

			PopResult(row, col);
		}
	}

	LP(row, 0, MaxSize)
	{
		LP(col, 0, MaxSize)
		{
			if (results[row][col] > curMax) {
				curMax = results[row][col];
				maxRow = row;
				maxCol = col;
			}
		}
	}

	printf("%d %d %d\n", maxRow, maxCol, curMax);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int C;
	scanf("%d", &C);

	LP(i, 0, C)
	{
		scanf("%d", &d);
		scanf("%d", &N);
		curMax = 0;

		LP(row, 0, MaxSize)
		{
			LP(col, 0, MaxSize)
			{
				rats[row][col] = 0;
				results[row][col] = 0;

			}
		}

		LP(line, 0, N)
		{
			int row, col, num;

			scanf("%d %d %d", &row, &col, &num);
			rats[row][col] = num;
		}

		Process();

	}

	return 0;
}

