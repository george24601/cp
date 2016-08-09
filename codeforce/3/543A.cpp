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
#define INF 2000000000
#define Ep 1e-8

/*
 ways[i][j][k] = ways[i-1][j][k] + ways[i][i - 1] [k - a]

 */

int const MaxSize = 510;
int n, m, b, mod;
int ways[MaxSize][MaxSize];
int a[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d %d", &n, &m, &b, &mod);

	LP(i, 0, n)
	{
		scanf("%d", &a[i]);
		memset(ways[i], 0, sizeof(ways[i]));
	}

	for (int l = 0; l <= m && l * a[0] <= b; l++)
		ways[l][l * a[0]] = 1;

	LP(i, 1, n)
	{
		LPE(l, 1, m)
		{
			LPE(nb,a[i], b)
			{
				int noWrite = ways[l][nb];
				int writeOne = ways[l - 1][nb - a[i]];

				ways[l][nb] = (noWrite + writeOne) % mod;
			}
		}
	}

	int total = 0;

	LPE(nb,0, b)
	{
		total += ways[m][nb];
		total %= mod;
	}

	cout << total << endl;

	return 0;
}

