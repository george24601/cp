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

//UVa 10354 avoiding your boss
//SSSP
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int INF = 2147483647;

const int MaxSize = 110;

int n;
WAL adj;
int dist[MaxSize][MaxSize];
char names[MaxSize][MaxSize];
bool onSP[MaxSize];

void Process() {

	LP(v, 0 , n)
	{
		LP(u, 0, n)
			dist[v][u] = INF;
	}

	LP(v, 0 , n)
	{
		dist[v][v] = 0;
		LP(i, 0, adj[v].size())
		{
			int u = adj[v][i].first;

			dist[v][u] = adj[v][i].second;
		}
	}

	LP(k, 0, n)
	{
		LP(i, 0 , n)
		{
			LP(j, 0, n)
			{
				if (dist[i][k] == INF || dist[k][j] == INF)
					continue;

				if (onSP[i] || onSP[j] || onSP[k])
					continue;

				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int P, R, BH, OF, YH, M;
	while (scanf("%d %d %d %d %d %d", &P, &R, &BH, &OF, &YH, &M) == 6) {
		BH -= 1;
		OF -= 1;
		YH -= 1;
		M -= 1;

		n = P;

		adj = WAL(P);

		memset(onSP, false, sizeof(onSP));

		LP(i, 0, R)
		{
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			from -= 1;
			to -= 1;

			adj[from].push_back(PII(to, cost));
			adj[to].push_back(PII(from, cost));
		}

		Process();

		int minDist = dist[OF][BH];

		LP(choice, 0, P)
		{
			int pDist = dist[OF][choice] + dist[choice][BH];

			if (pDist == minDist)
				onSP[choice] = true;
		}

		Process();

		int newDist = dist[YH][M];

		if (newDist == INF || onSP[YH] || onSP[M])
			printf("MISSION IMPOSSIBLE.\n");
		else
			printf("%d\n", newDist);
	}

	return 0;
}
