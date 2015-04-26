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

//UVa 11463 Commandos
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

				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d", &n);
		int m;
		scanf("%d", &m);

		adj = WAL(n);

		LP(i,0, m)
		{
			int from, to;

			scanf("%d %d", &from, &to);

			if (from == to)
				continue;

			adj[from].push_back(PII(to, 1));
			adj[to].push_back(PII(from, 1));
		}

		int start, end;
		scanf("%d %d", &start, &end);

		Process();

		int maxValue = 0;

		LP(choice, 0, n)
		{
			int total = dist[start][choice] + dist[choice][end];

			maxValue = max(maxValue, total);
		}

		printf("Case %d: %d\n", caseNum, maxValue);
	}

	return 0;
}
