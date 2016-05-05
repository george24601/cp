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

//UVa 341  Non-Stop Travel
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

const int MaxSize = 20;

int n;
WAL adj;
int dist[MaxSize];
int prev[MaxSize];

void Process(int start) {

	LP(v, 0 , n)
		dist[v] = INF;

	dist[start] = 0;

	LPE(pathLeng, 1, n - 1)
	{
		LP(v, 0 , n)
		{
			if (dist[v] == INF) //not connected yet
				continue;

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i].first;

				int uv = adj[v][i].second;
				int newDist = dist[v] + uv;

				if (newDist < dist[u]) {
					dist[u] = newDist;
					prev[u] = v;
				}
			}

		}
	}
}

void P_r(int start, int cur) {
	if (start == cur) {
		printf("%d", start + 1);
		return;
	}

	P_r(start, prev[cur]);

	printf(" %d", cur + 1);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		scanf("%d", &n);

		if (n <= 0)
			break;

		caseNum++;

		adj = WAL(n);

		LP(i, 0, n)
		{
			int numE;

			scanf("%d", &numE);

			LP(j, 0, numE)
			{
				int neighbor, cost;
				scanf("%d %d", &neighbor, &cost);
				neighbor -= 1;

				adj[i].push_back(make_pair(neighbor, cost));
			}

		}

		int start, end;
		scanf("%d %d", &start, &end);

		start -= 1;
		end -= 1;

		Process(start);

		printf("Case %d: Path = ", caseNum);

		P_r(start, end);

		printf("; %d second delay\n", dist[end]);
	}

	return 0;
}
