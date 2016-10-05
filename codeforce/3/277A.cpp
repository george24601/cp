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

#define INF 2000000000

/*
 populate graph,

 find # of components
 ans nc -1
 */

int const MaxSize = 110;
int n, m;

bool visited[MaxSize];
bool adj[MaxSize][MaxSize];

SAL lang;

void fill(int p) {
	if (visited[p])
		return;

	visited[p] = true;

	LPE(l, 1, n)
	{
		if (adj[p][l])
			fill(l);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> m;

	lang = SAL(m + 10);

	memset(visited, false, sizeof(visited));

	bool allLearn = true;
	LPE(p, 1, n)
	{
		memset(adj[p], false, sizeof(adj[p]));

		int nm;
		cin >> nm;

		if(nm)
			allLearn = false;

		LP(j, 0, nm)
		{
			int ln;
			cin >> ln;

			lang[ln].push_back(p);
		}
	}

	LPE(l, 1, m)
	{
		int sSize = lang[l].size();
		LP(i, 0, sSize )
		{
			int from = lang[l][i];
			LP(j, 0, sSize)
			{
				int to = lang[l][j];
				adj[from][to] = true;
			}
		}
	}

	int nc = 0;

	LPE(i, 1, n)
	{
		if (visited[i])
			continue;

		nc++;
		fill(i);
	}

	if(allLearn)
		cout << n << endl;
	else
		cout << nc - 1 << endl;

	return 0;
}
