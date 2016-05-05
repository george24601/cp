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
typedef pair<int, int> FT;
#define Ep 1e-9

int const MaxSize = 20;

char m [MaxSize][MaxSize];
int r, c;

int step[MaxSize][MaxSize];

void DFS_r(int row, int col, int s)
{
	step[row][col] = s;

	int nextRow = row, nextCol = col;
	if(m[row][col] == 'E')
		nextCol++;
	else if(m[row][col] == 'W')
		nextCol--;
	else if(m[row][col] == 'N')
		nextRow--;
	else if(m[row][col] == 'S')
		nextRow++;

	if(nextRow < 0 ||nextRow >= r || nextCol < 0 || nextCol >= c)
		printf("%d step(s) to exit\n", s + 1);
	else if(step[nextRow][nextCol] != -1)
		printf("%d step(s) before a loop of %d step(s)\n", step[nextRow][nextCol], s - step[nextRow][nextCol] + 1);
	else
		DFS_r(nextRow, nextCol, s+1);

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);

	int sc;
	while (scanf("%d %d %d", &r, &c, &sc))
	{
		if(r==0 && c== 0 && sc ==0)
			break;

		LP(i, 0, r)
		{
			scanf("%s", m[i]);
			memset(step[i], -1, sizeof(step[i]));
		}

		DFS_r(0, sc-1, 0);
	}

	return 0;
}
