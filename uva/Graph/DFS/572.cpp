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

//UVa 572  Oil Deposits
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

int m, n;

bool visited[101][101];

bool black[101][101];

bool Valid(int row, int col) {
	if (row < 0 || row >= m)
		return false;
	if (col < 0 || col >= n)
		return false;

	return black[row][col];
}

void V_r(int row, int col) {
	if (visited[row][col])
		return;
	else
		visited[row][col] = true;

	/*
	 *  (i-1 , j-1 ) , ( i-1 ,  j  )
	 (  i  , j-1 ) , (  i  , j+1 )
	 ( i+1 ,  j  ) , ( i+l , j+1 )
	 */
	int nextXs[13] = { row - 1, row - 1, row - 1, row, row, row + 1, row + 1,
			row + 1 };
	int nextYs[13] = { col - 1, col, col + 1, col - 1, col + 1, col - 1, col,
			col + 1 };
	int choices = 8;

	LP(i, 0, choices)
	{
		if (Valid(nextXs[i], nextYs[i]))
			V_r(nextXs[i], nextYs[i]);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {

		scanf("%d %d", &m, &n);

		if (m == 0)
			break;

		LP(i, 0, m)
		{
			char line[101];

			scanf("%s", line);

			LP(j, 0, n)
			{
				black[i][j] = (line[j] == '@');
				visited[i][j] = false;
			}
		}

		int count = 0;

		LP(i, 0, m)
		{
			LP(j, 0, n)
			{
				if (black[i][j] && !visited[i][j]) {
					count++;
					V_r(i, j);
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

