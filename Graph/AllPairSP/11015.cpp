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

const int MaxSize = 23;

int n;
WAL adj;
int dist[MaxSize][MaxSize];
char names [MaxSize][MaxSize];

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
		caseNum++;

		int m;
		scanf("%d %d", &n, &m);

		if(n == 0)
			break;

		LP(i,0, n)
			scanf("%s", &names[i]);

		adj = WAL(n);

		LP(i,0, m)
		{
			int from, to, cost;

			scanf("%d %d %d", &from, &to, &cost);

			from -= 1;
			to -= 1;

			if(from == to)
				continue;

			adj[from].push_back(PII(to, cost));
			adj[to].push_back(PII(from, cost));
		}

		Process();

		int minTotal = INF;
		int minChoice;

		LP(choice, 0, n)
		{
			int total = 0;

			LP(i, 0, n)
				total += dist[choice][i];

			if(total < minTotal)
			{
				minTotal = total;
				minChoice = choice;
			}
		}

		printf("Case #%d : %s\n", caseNum, names[minChoice]);
	}

	return 0;
}
