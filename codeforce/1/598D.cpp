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

LL const INF = LL(1e18);
int const MaxSize = 1010;
int n, m, k;

char ma[MaxSize][MaxSize];
bool visited[MaxSize][MaxSize];
int ci[MaxSize][MaxSize];

int ans[MaxSize * MaxSize];
int cci;

int deltaR[] = { 0, 1, 0, -1 };
int deltaC[] = { 1, 0, -1, 0 };

int dfs(int r, int c) {
	if (visited[r][c])
		return 0;
	else
		visited[r][c] = true;

	ci[r][c] = cci;

	int thisV = 0;

	LP(i, 0, 4)
	{
		int newR = r + deltaR[i];
		int newC = c + deltaC[i];

		if (newR < 0 || newR >= n)
			continue;

		if (newC < 0 || newC >= m)
			continue;

		if (ma[newR][newC] == '*')
			thisV++;
		else
			thisV += dfs(newR, newC);
	}

	//cout << r << " " << c << " " << thisV << endl;
	return thisV;
}

void precompute() {

	cci = 0;

	LP(i, 0, n)
	{
		LP(j, 0, m)
		{
			if (visited[i][j] || ma[i][j] == '*')
				continue;

			cci++;

			int total = dfs(i, j);

			ans[cci] = total;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);

	LP(i, 0, n)
	{
		scanf("%s", ma[i]);
		memset(visited[i], false, sizeof(visited[i]));
	}

	memset(ans, 0, sizeof(ans));

	precompute();

	LP(i, 0, k)
	{
		int r, c;
		scanf("%d %d", &r, &c);
		cout << ans[ci[r - 1][c - 1]] << endl;
	}
}

