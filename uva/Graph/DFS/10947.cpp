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
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, double> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

const int INF = 2000000000;

const int MaxSize = 110;

int n;
WAL adj;
double dist[MaxSize];

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

				double uv = adj[v][i].second;

				double newDist = dist[v] + uv;

				if (newDist < dist[u]) {
					dist[u] = newDist;

					if (u == 1)
						return;
				}
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		int K, M;
		if (scanf("%d %d", &K, &M) != 2)
			break;

		vector<int> xs;
		vector<int> ys;
		vector<int> radius;

		LP(i, 0, 2)
		{
			int fx, fy, fr;
			scanf("%d %d %d", &fx, &fy, &fr);
			xs.push_back(fx);
			ys.push_back(fy);
			radius.push_back(fr);
		}

		int nA;
		scanf("%d", &nA);

		LP(i, 0, nA)
		{
			int fx, fy, fr;
			scanf("%d %d %d", &fx, &fy, &fr);
			xs.push_back(fx);
			ys.push_back(fy);
			radius.push_back(fr);
		}

		n = xs.size();

		adj = WAL(n);

		int maxIJ = K * M;

		LP(i, 0 , n)
		{
			LP(j, i+1, n)
			{
				int xDiff = xs[i] - xs[j];
				xDiff = xDiff * xDiff;

				int yDiff = ys[i] - ys[j];
				yDiff = yDiff * yDiff;

				double ijLength = sqrt(xDiff + yDiff) - radius[i] - radius[j];

				if (ijLength > maxIJ)
					continue;

				adj[i].push_back(DW(j, ijLength));
				adj[j].push_back(DW(i, ijLength));

			}
		}

		Process(0);

		if (dist[1] == INF)
			printf("Larry and Ryan will be eaten to death.\n");
		else
			printf("Larry and Ryan will escape!\n");

	}

	return 0;
}
