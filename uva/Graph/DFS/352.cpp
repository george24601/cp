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

//UVa 352  The Seasonal War
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

int N;

bool visited[30][30];

bool black[30][30];

bool Valid(int row, int col) {
	if (row < 0 || row >= N)
		return false;
	if (col < 0 || col >= N)
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
	int choices = 12;

	LP(i, 0, choices)
	{
		if (Valid(nextXs[i], nextYs[i]))
			V_r(nextXs[i], nextYs[i]);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while (scanf("%d", &N) == 1) {

		caseNum++;

		LP(i, 0, N)
		{
			char line[30];

			scanf("%s", line);

			LP(j, 0, N)
			{
				if (line[j] == '1')
					black[i][j] = true;
				else
					black[i][j] = false;

				visited[i][j] = false;
			}
		}

		int count = 0;

		LP(i, 0, N)
		{
			LP(j, 0, N)
			{
				if (black[i][j] && !visited[i][j]) {
					count++;
					V_r(i, j);
				}
			}
		}

		printf("Image number %d contains %d war eagles.\n", caseNum, count);
	}

	return 0;
}

