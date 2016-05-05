#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 100;

bool target[MaxN][MaxN];
bool current[MaxN][MaxN];
int n, m, r, c;

//order of ops doesnt matter => so do it row by row
//if cell is not same as target => try apply the tool
//if can apply tool, apply, if can't apply, check if matches or not, if not, immediately return false

void Apply(int row, int col) {
	LP(i, row, row + r)
	{
		LP(j, col, col + c)
			current[i][j] = !current[i][j];
	}
}

int Run() {
	int endRowIndex = n - r;
	int endColIndex = m - c;

	int count = 0;

	LPE(i, 0, endRowIndex)
	{
		LPE(j, 0, endColIndex)
		{
			if (current[i][j] != target[i][j]) {
				Apply(i, j);
				count++;
			}

		}

		LP(j, endColIndex+1, m)
		{
			if (current[i][j] != target[i][j])
				return -1;
		}
	}

	LP(i, endRowIndex + 1, n)
	{
		LP(j, 0, m)
		{
			if (current[i][j] != target[i][j])
				return -1;
		}
	}

	return count;
}

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\annoying.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		scanf("%d %d %d %d", &n, &m, &r, &c);

		if((n + m + r + c) == 0)
			break;

		char buff[MaxN];
		LP(i, 0, n)
		{
			memset(current[i], false, sizeof(current[i]));

			scanf("%s", buff);
			LP(j, 0, m)
			{
				if(buff[j] == '1')
					target[i][j] = true;
				else
					target[i][j] = false;
			}
		}

		printf("%d\n", Run());
	}

	return 0;
}
