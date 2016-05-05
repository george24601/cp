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
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;

const int INF = 2147483647;

const int MaxSize = 110;

int n;
WAL adj;
int dist[MaxSize][MaxSize];

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

			dist[v][u] = min(dist[v][u], adj[v][i].second);
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

				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}

		}
	}
}

bool SameDist(int choice)
{
	int initDist = dist[choice][0];

	LP(i,0, 5)
	{
		if(initDist != dist[choice][i])
			return false;
	}

	return true;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		int D;
		scanf("%d %d", &n, &D);

		adj = WAL(n);
		LP(i, 0, D)
		{
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			from -= 1;
			to -= 1;

			adj[from].push_back(PII(to, cost));
			adj[to].push_back(PII(from, cost));
		}

		Process();

		int minMax = INF;
		LP(choice, 0, n)
		{
			if(!SameDist(choice))
				continue;

			int maxDist = 0;
			LP(dest, 0, n)
				maxDist = max(maxDist, dist[choice][dest]);

			minMax = min(maxDist, minMax);
		}

		if(minMax == INF)
			printf("Map %d: -1\n", caseNum);
		else
			printf("Map %d: %d\n", caseNum, minMax);
	}

	return 0;
}
