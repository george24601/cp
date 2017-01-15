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
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e18

/*

 */

string s, t;
int n, m, k;
int const MaxSize = 1005;

int best[MaxSize][MaxSize][11][2];

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m >> k >> s >> t;

	LPE(sl, 1, n)
	{
		LPE(tl, 1, m)
		{
			LPE(ns, 1, k)
			{
				if (s[sl - 1] == t[tl - 1]) {
					best[sl][tl][ns][1] = max(best[sl - 1][tl - 1][ns][1],
							best[sl - 1][tl - 1][ns - 1][0]) + 1;
				}

				best[sl][tl][ns][0] = max(best[sl][tl][ns][0],
						best[sl - 1][tl][ns][0]);
				best[sl][tl][ns][0] = max(best[sl][tl][ns][0],
						best[sl][tl - 1][ns][0]);
				best[sl][tl][ns][0] = max(best[sl][tl][ns][0],
						best[sl][tl][ns][1]);
			}
		}
	}
	cout << best[n][m][k][0] << endl;

	return 0;
}

