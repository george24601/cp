#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
using namespace std;

//UVa 558 wormholes
//Bellman-Ford
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int INF = 1000000000;

int n, m;
WAL adj;

void Process() {

	map<int, int> dist;

	LP(v, 0 , n)
		dist[v] = INF;

	dist[0] = 0;

	LPE(pathLeng, 1, n - 1)
	{
		LP(v, 0 , n)
		{
			if (dist[v] == INF)
				continue;

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i].first;

				int newDist = dist[v] + adj[v][i].second;

				if (newDist < dist[u])
					dist[u] = newDist;
			}

		}

	}

	LP(v, 0 , n)
	{
		if (dist[v] == INF)
			continue;

		LP(i, 0, adj[v].size())
		{
			int u = adj[v][i].first;

			int newDist = dist[v] + adj[v][i].second;

			if (newDist < dist[u]) {
				printf("possible\n");
				return;
			}
		}

	}

	printf("not possible\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d %d", &n, &m);

		adj = WAL(n);

		LP(e, 0, m)
		{
			int from, to, time;
			scanf("%d %d %d", &from, &to, &time);

			adj[from].push_back(make_pair(to, time));
		}

		Process();
	}

	return 0;
}
