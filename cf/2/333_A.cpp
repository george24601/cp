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

int n, m;
int const MaxSize = 410;
int adj[MaxSize][MaxSize];
int dist[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &m);

	LPE(i, 0, n)
		memset(adj[i], 0, sizeof(adj[i]));

	bool hasRailDir = false;

	LP(i, 0, m)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u][v] = 1;
		adj[v][u] = 1;

		if ((u == 1 && v == n) || (u == n && v == 1))
			hasRailDir = true;
	}

	if (hasRailDir) {

		LPE(i, 0, n)
		{
			LPE(j, 0, n)
					adj[i][j] = 1 - adj[i][j];
		}
	}


	LPE(i, 1, n)
		dist[i] = -1;

	dist[1] = 0;

	queue<int> toProcess;
	toProcess.push(1);

	while(toProcess.size()){
		int current = toProcess.front();
		toProcess.pop();

		LPE(i, 1, n){
			if(adj[current][i] && dist[i] < 0){
				dist[i] = dist[current] + 1;
				toProcess.push(i);
			}
		}
	}

	cout << dist[n] << endl;

	return 0;
}

