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

const int MaxSize = 210;

int n, m;
WAL adj;
int dist[MaxSize];

void Process() {

	LP(v, 0 , n)
		dist[v] = INF;

	dist[0] = 0;

	LPE(pathLeng, 1, n - 1)
	{
		bool hasChange = false;

		LP(v, 0 , n)
		{
			if (dist[v] == INF)
				continue;

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i].first;

				int newDist = dist[v] + adj[v][i].second;

				if (newDist < dist[u]) {
					dist[u] = newDist;
					hasChange = true;
				}
			}

		}

		if (!hasChange)
			break;
	}

	LPE(pathLeng, 1, n - 1)
	{
		bool hasChange = false;

		LP(v, 0 , n)
		{
			if (dist[v] == INF)
				continue;

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i].first;

				if (dist[v] == -INF) {

					if (dist[u] != -INF) {
						dist[u] = -INF;
						hasChange = true;

					}
				} else if (dist[u] == -INF) {
					continue;
				}

				int newDist = dist[v] + adj[v][i].second;

				if (newDist < dist[u]) {
					dist[u] = -INF;
					hasChange = true;
				}
			}
		}

		if (!hasChange)
			break;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		if (scanf("%d", &n) != 1)
			break;

		caseNum++;
		int busy[MaxSize];
		LP(i, 0, n)
			scanf("%d", &busy[i]);

		adj = WAL(n);

		memset(dist, 0, sizeof(dist));

		int r;
		scanf("%d", &r);

		LP(e, 0, r)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			from -= 1;
			to -= 1;

			int time = busy[to] - busy[from];
			time = time * time * time;

			adj[from].push_back(make_pair(to, time));
		}

		Process();

		int q;
		scanf("%d", &q);

		printf("Set #%d\n", caseNum);

		LP(i, 0, q)
		{
			int v;
			scanf("%d", &v);

			v -= 1;

			if (v < 0 || v >= n) {
				printf("?\n");
				continue;
			}

			int cost = dist[v];

			if (dist[v] == INF || dist[v] == -INF || dist[v] < 3)
				printf("?\n");
			else
				printf("%d\n", cost);
		}

	}

	return 0;
}
