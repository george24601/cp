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

//UVa 260  Il Gioco dell'X
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

bool visited[201][201];

bool black[201][201];

bool Valid(int row, int col) {
	if (row < 0 || row >= N)
		return false;
	if (col < 0 || col >= N)
		return false;

	if (black[row][col])
		return false;

	return true;
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
	int nextXs[10] = { row - 1, row - 1, row, row, row + 1, row + 1 };
	int nextYs[10] = { col - 1, col, col - 1, col + 1, col, col + 1 };
	int choices = 6;

	LP(i, 0, choices)
	{
		if (Valid(nextXs[i], nextYs[i]))
			V_r(nextXs[i], nextYs[i]);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while (true) {
		scanf("%d", &N);

		if(N == 0)
			break;

		caseNum++;

		LP(i, 0, N)
		{
			char line[201];

			scanf("%s", line);

			LP(j, 0, N)
			{
				if (line[j] == 'b')
					black[i][j] = true;
				else
					black[i][j] = false;

				visited[i][j] = false;
			}
		}

		LP(i, 0, N)
		{
			if (!black[i][0])
				V_r(i, 0);
		}

		LP(i, 0, N)
		{
			if (visited[i][N - 1]) {
				printf("%d W\n", caseNum);
				goto Next;
			}

		}

		printf("%d B\n", caseNum);
		Next: continue;
	}

	return 0;
}

