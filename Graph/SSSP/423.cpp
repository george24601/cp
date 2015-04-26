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

//UVa 423  MPI Maelstrom
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

const L INF = 9223372036854775807;

const int MaxSize = 110;

int n;
WAL adj;
L dist[MaxSize];

void Process() {

	LP(v, 0 , n)
		dist[v] = INF;

	dist[0] = 0;

	LPE(pathLeng, 1, n - 1)
	{
		LP(v, 0 , n)
		{
			if (dist[v] == INF) //not connected yet
				continue;

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i].first;

				L uv = adj[v][i].second;
				L newDist = dist[v] + uv;

				if (newDist < dist[u]) {
					dist[u] = newDist;
				}
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	scanf("%d", &n);

	adj = WAL(n);

	LP(u, 1, n)
	{
		LP(v, 0, u)
		{
			char buff[20];
			scanf("%s", buff);

			if (strlen(buff) == 1 && buff[0] == 'x')
				continue;

			int cost = atoi(buff);

			adj[u].push_back(make_pair(v, cost));
			adj[v].push_back(make_pair(u, cost));
		}

	}

	Process();

	L max = 0;

	LP(i, 0, n)
		max = Max(max, dist[i]);

	printf("%llu\n", max);

	return 0;
}
