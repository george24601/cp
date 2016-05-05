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

//UVa 10557 XYZZY
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

const int MaxSize = 110;

int n, m;
SAL adj;
int dist[MaxSize];
int energyLevel[MaxSize];

void Process() {

	LP(v, 0 , n)
		dist[v] = INF;

	dist[0] = 0;

	LPE(pathLeng, 1, n - 1)
	{
		bool hasChange = false;

		LP(v, 0 , n)
		{
			if (dist[v] == INF) //not connected yet
				continue;

			if (dist[v] >= 100)
				continue; //no energy, cant proceed

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i];

				int uv = -energyLevel[u];
				int newDist = dist[v] + uv;

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

			if (dist[v] >= 100)
				continue; //no energy, cant proceed

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i];

				if (dist[v] == -INF) {

					if (dist[u] != -INF) {
						dist[u] = -INF;
						hasChange = true;

					}
				} else if (dist[u] == -INF) {
					continue;
				}

				int newDist = dist[v] - energyLevel[u];

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

	while (true) {
		if (scanf("%d", &n) != 1)
			break;

		if (n < 0)
			break;

		adj = SAL(n);
		memset(dist, 0, sizeof(dist));

		LP(i, 0, n)
		{
			int energy, numE;

			scanf("%d %d", &energy, &numE);
			energyLevel[i] = energy;

			LP(e, 0, numE)
			{
				int next;
				scanf("%d", &next);
				next -= 1;

				adj[i].push_back(next);
			}

		}

		Process();

		int cost = dist[n - 1];

		if (cost == INF)
			printf("hopeless\n");
		else
			printf("winnable\n");

	}

	return 0;
}
