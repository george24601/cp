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

//UVa 567  Risk
//floyd Warshall
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

const int INF = 2147483647;

const int MaxSize = 20;

int n;
WAL adj;
int dist[MaxSize][MaxSize];

void Process() {

	LP(v, 0 , n)
	{
		LP(u, 0, n)
		{
			dist[v][u] = INF;
		}
	}

	LP(v, 0 , n)
	{
		LP(i, 0, adj[v].size())
		{
			int u = adj[v][i].first;

			dist[v][u] = 1;
		}
	}

	LP(k, 0, n)
	{
		LP(i, 0 , n)
		{
			LP(j, 0, n)
			{
				if(dist[i][k] == INF || dist[k][j] == INF)
					continue;

				dist[i][j] = Min(dist[i][j], dist[i][k] + dist[k][j]);
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		n = 20;
		caseNum++;

		adj = WAL(n);

		LP(u, 0, n -1)
		{
			int numE;
			if (scanf("%d", &numE) != 1)
				return 0;

			LP(i, 0, numE)
			{
				int v;
				scanf("%d", &v);
				v -= 1;

				adj[u].push_back(make_pair(v, 1));
				adj[v].push_back(make_pair(u, 1));

			}

		}

		Process();

		printf("Test Set #%d\n", caseNum);

		int numT;
		scanf("%d", &numT);
		LP(i, 0, numT)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			int cost = dist[from - 1][to - 1];

			if (from < 10)
				printf(" ");

			printf("%d to ", from);

			if (to < 10)
				printf(" ");

			printf("%d: %d\n", to, cost);
		}

		printf("\n");
	}

	return 0;
}
