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

int const MaxSize = 15;

char board[MaxSize][MaxSize];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\A.3.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		scanf("%s", board[0]);

		if (strcmp(board[0], "END") == 0)
			break;

		LP(i, 1, MaxSize)
			scanf("%s", board[i]);

		int maxS = 1 << MaxSize;

		int ans = MaxSize;
		LP(set, 1, maxS)
		{
			bool colHas[MaxSize];
			memset(colHas, false, sizeof(colHas));

			int rowNum = 0;
			LP(r, 0, MaxSize)
			{
				if ((set >> r) & 1) {
					rowNum++;
					continue;
				}

				LP(c,0, MaxSize)
				{
					if (board[r][c] == '#')
						colHas[c] = true;
				}

			}

			int colNum = 0;
			LP(c,0, MaxSize)
			{
				if (colHas[c])
					colNum++;
			}

			ans = min(ans, max(colNum, rowNum));
		}

		printf("%d\n", ans);
	}

	return 0;
}
