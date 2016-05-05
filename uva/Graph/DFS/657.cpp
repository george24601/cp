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

//UVa 657 the die is cast
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

int w, h;

const int MaxSize = 51;
bool visited[MaxSize][MaxSize];
bool dotVisited[MaxSize][MaxSize];

int pixel[MaxSize][MaxSize];

vector<int> dotCount;

bool Valid(int row, int col) {
	if (row < 0 || row >= h)
		return false;
	if (col < 0 || col >= w)
		return false;

	return (pixel[row][col] > 0);
}

void VisitDot_r(int row, int col) {
	if (dotVisited[row][col])
		return;
	else
		dotVisited[row][col] = true;

	int nextXs[13] = { row - 1, row, row, row + 1 };
	int nextYs[13] = { col, col + 1, col - 1, col };
	int choices = 4;

	LP(i, 0, choices)
	{
		int nX = nextXs[i];
		int nY = nextYs[i];
		if (Valid(nX, nY) && pixel[nX][nY] == 2)
			VisitDot_r(nX, nY);
	}

}

void V_r(int row, int col, int cNum) {
	if (visited[row][col])
		return;
	else
		visited[row][col] = true;

	if (pixel[row][col] == 2 && !dotVisited[row][col]) {
		dotCount[cNum] += 1;
		VisitDot_r(row, col);
	}

	int nextXs[13] = { row - 1, row, row, row + 1 };
	int nextYs[13] = { col, col + 1, col - 1, col };
	int choices = 4;

	LP(i, 0, choices)
	{
		if (Valid(nextXs[i], nextYs[i]))
			V_r(nextXs[i], nextYs[i], cNum);
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {

		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0)
			break;

		caseNum++;

		dotCount.clear();

		LP(i, 0, h)
		{
			char line[MaxSize];

			scanf("%s", line);

			LP(j, 0, w)
			{
				if (line[j] == '.')
					pixel[i][j] = -1;
				else if (line[j] == '*')
					pixel[i][j] = 1;
				else if (line[j] == 'X')
					pixel[i][j] = 2;

				visited[i][j] = false;
				dotVisited[i][j] = false;
			}
		}

		int count = 0;

		LP(i, 0, h)
		{
			LP(j, 0, w)
			{
				if ((pixel[i][j] > 0) && !visited[i][j]) {

					dotCount.push_back(0);

					V_r(i, j, count);
					count++;
				}
			}
		}

		printf("Throw %d\n", caseNum);
		sort(dotCount.begin(), dotCount.end());

		printf("%d", dotCount[0]);

		LP(i, 1, dotCount.size())
			printf(" %d", dotCount[i]);

		printf("\n\n");
	}

	return 0;
}

