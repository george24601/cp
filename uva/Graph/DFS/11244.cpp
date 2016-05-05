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

//UVa 11244 Counting Stars
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

int r, c;

const int MaxSize = 110;
bool visited[MaxSize][MaxSize];

bool pixel[MaxSize][MaxSize];

bool Valid(int x, int y) {
	if (x < 0 || x >= r)
		return false;
	if (y < 0 || y >= c)
		return false;

	return pixel[x][y];
}

int V_r(int row, int col) {
	if (visited[row][col])
		return 0;
	else
		visited[row][col] = true;

	int nextRows[13] = { row - 1, row - 1, row - 1, row, row, row + 1, row + 1,
			row + 1 };
	int nextCols[13] = { col - 1, col, col + 1, col + 1, col - 1, col - 1, col,
			col + 1 };
	int choices = 8;
	int toReturn = 1;

	LP(i, 0, choices)
	{
		int nRow = nextRows[i];
		int nCol = nextCols[i];

		if (Valid(nRow, nCol))
			toReturn += V_r(nRow, nCol);
	}

	return toReturn;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d", &r, &c);

		if (r == 0 && c == 0)
			break;

		LP(row, 0, r)
		{
			char line[c + 1];
			scanf("%s", line);

			LP(col, 0, c)
			{
				pixel[row][col] = (line[col] == '*');
				visited[row][col] = false;
			}
		}

		int count = 0;
		LP(row, 0, r)
		{
			LP(col, 0, c)
			{
				if (!visited[row][col] && pixel[row][col]) {

					int size = V_r(row, col);

					if (size == 1)
						count++;

				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

