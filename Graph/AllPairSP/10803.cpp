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

//UVa 10803 Thunder Mountain
//floyd Warshall
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, double> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, double> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int INF = 2147483641;

const int MaxSize = 101;

int n;
WAL adj;
double dist[MaxSize][MaxSize];

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
			double uv = adj[v][i].second;

			dist[v][u] = uv;
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

				dist[i][j] = Min(dist[i][j], dist[i][k] + dist[k][j]);
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
		adj = WAL(n);

		int xs[MaxSize];
		int ys[MaxSize];

		LP(i, 0, n)
			scanf("%d %d", &xs[i], &ys[i]);

		LP(i, 0, n)
		{
			LP(j, 0, n)
			{
				if (i == j)
					continue;

				double xDiff = xs[i] - xs[j];
				xDiff = xDiff * xDiff;
				double yDiff = ys[i] - ys[j];
				yDiff = yDiff * yDiff;

				double dist = sqrt(xDiff + yDiff);

				if(dist <= 10.0)
					adj[i].push_back(make_pair(j, dist));

			}
		}

		Process();

		printf("Case #%d:\n", caseNum);

		double maxD = 0;

		LP(i, 0, n)
		{
			LP(j, i+1, n)
				maxD = Max(maxD, dist[i][j]);
		}

		if(maxD == INF)
			printf("Send Kurdy\n\n");
		else
			printf("%.4lf\n\n", maxD);

	}

	return 0;
}
