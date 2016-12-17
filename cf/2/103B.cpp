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

 */
int const MaxSize = 200;
int n, m;
bool adj[MaxSize][MaxSize];
bool visited[MaxSize];

void visit(int v) {
	if (visited[v])
		return;
	else
		visited[v] = true;

	LPE(u, 0, n)
	{
		if (adj[v][u])
			visit(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &m);

	LPE(i, 0, n)
		memset(adj[i], false, sizeof(adj[i]));

	LP(i, 0, m)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		adj[v1][v2] = true;
		adj[v2][v1] = true;
	}

	memset(visited, false, sizeof(visited));

	visit(1);

	int nc = 0;
	int ec = 0;

	LPE(v, 1, n)
	{
		if (visited[v])
			nc++;

		LPE(u, 1, n)
		{
			if (adj[u][v])
				ec++;
		}
	}

	ec /= 2;

	if (ec == n && nc == n)
		cout << "FHTAGN!" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
