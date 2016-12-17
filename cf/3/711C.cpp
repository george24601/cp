#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int N = 101;
const LL INF = LL(1e18);

int n, m, k, c[N];
LL ans[N][N][N], p[N][N], bestC[N][N], best[N][N], best2[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> m >> k;

	LPE(i,1, n)
		cin >> c[i];

	LPE(i, 0, n)
	{
		LPE(nb, 0, k)
		{
			best[i][nb] = INF;
			bestC[i][nb] = -1;
			best2[i][nb] = INF;

			LPE(color, 0, m)
				ans[i][nb][color] = INF;
		}
	}

	LPE(i, 1, n)
	{
		LPE(color, 1, m)
			cin >> p[i][color];
	}

	if (c[1]) {
		ans[1][1][c[1]] = 0;
		best[1][1] = 0;
		bestC[1][1] = c[1];
	} else {

		LPE(color, 1, m)
		{
			ans[1][1][color] = p[1][color];
			LL curC = p[1][color];

			if (curC <= best[1][1]) {

				if (curC == best[1][1])
					bestC[1][1] = -1;
				else
					bestC[1][1] = color;

				best2[1][1] = best[1][1];
				best[1][1] = curC;
			} else if (curC <= best2[1][1]) {
				best2[1][1] = curC;
			}
		}
	}

	LPE(i, 2,n)
	{
		LPE(nb, 1, k)
		{
			int minLastC = bestC[i - 1][nb - 1];
			LL minLast = best[i - 1][nb - 1];
			LL min2Last = best2[i - 1][nb - 1];

			if (c[i]) {
				LL keepCost = ans[i - 1][nb][c[i]];

				LL changeCost = c[i] == minLastC ? min2Last : minLast;

				ans[i][nb][c[i]] = min(ans[i][nb][c[i]],
						min(keepCost, changeCost));
			} else {
				LPE(lc, 1, m)
				{
					LL keepCost = ans[i - 1][nb][lc] + p[i][lc];

					LL changeCost = (lc == minLastC ? min2Last : minLast)
							+ p[i][lc];

					ans[i][nb][lc] = min(ans[i][nb][lc],
							min(keepCost, changeCost));
				}
			}

			LPE(lc, 1, m)
			{
				if (ans[i][nb][lc] <= best[i][nb]) {
					if (ans[i][nb][lc] == best[i][nb])
						bestC[i][nb] = -1;
					else
						bestC[i][nb] = lc;

					best2[i][nb] = best[i][nb];
					best[i][nb] = ans[i][nb][lc];
				} else if (ans[i][nb][lc] <= best2[i][nb])
					best2[i][nb] = ans[i][nb][lc];
			}
		}
	}

	LL finalAns = INF;

	LPE(lc, 1, m)
		finalAns = min(finalAns, ans[n][k][lc]);

	if (finalAns >= INF)
		finalAns = -1;

	cout << finalAns << endl;

}

