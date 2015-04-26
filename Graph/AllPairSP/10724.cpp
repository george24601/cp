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
#define Ep 1e-8

const int INF = 2147483647;

const int MaxSize = 50;

int n;
WAL adj;

double edge[MaxSize][MaxSize];
double dist[MaxSize][MaxSize];
int xs[MaxSize];
int ys[MaxSize];

void Process() {

	LP(k, 0, n)
	{
		LP(i, 0 , n)
		{
			if (dist[i][k] == INF)
				continue;

			LP(j, 0, n)
			{
				if (dist[i][k] == INF || dist[k][j] == INF)
					continue;

				double newCost = dist[i][k] + dist[k][j];

				if (newCost < dist[i][j])
					dist[i][j] = newCost;
			}

		}
	}
}

void NewNode() {
	int bestU = -1;
	int bestV = -1;
	double maxCUV = 0;
	double bestUVDist = 0;

	LP(u, 0, n)
	{
		LP(v, u+1, n)
		{
			if (edge[u][v] != INF)
				continue; //edge already exists

			int xDiff = xs[u] - xs[v];
			xDiff *= xDiff;

			int yDiff = ys[u] - ys[v];
			yDiff *= yDiff;

			double uvDist = sqrt(xDiff + yDiff);

			double cUV = 0;

			LP(start, 0, n)
			{
				LP(end, start + 1, n)
				{
					double newIJDist = INF;

					if (dist[start][u] != INF && dist[v][end] != INF) {
						double iuvj = dist[start][u] + uvDist + dist[v][end];
						newIJDist = min(newIJDist, iuvj);
					}

					if (dist[start][v] != INF && dist[u][end] != INF) {
						double ivuj = dist[start][v] + uvDist + dist[u][end];
						newIJDist = min(newIJDist, ivuj);
					}

					if (newIJDist < dist[start][end])
						cUV += (dist[start][end] - newIJDist);
				}
			}

			if (cUV <= 1.0 + Ep)
				continue;

			if (cUV > maxCUV + Ep
					|| (fabs(cUV - maxCUV) < Ep && uvDist < bestUVDist - Ep)) {
				bestU = u;
				bestV = v;
				maxCUV = cUV;

				bestUVDist = uvDist;
			}
		}
	}

	if (bestU < 0)
		printf("No road required\n");
	else
		printf("%d %d\n", bestU + 1, bestV + 1);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		int M;
		scanf("%d %d", &n, &M);

		if (n == 0 && M == 0)
			break;

		LP(v, 0 , n)
		{
			LP(u, 0, n)
			{
				dist[v][u] = INF;
				edge[v][u] = INF;
			}
		}

		LP(v, 0 , n)
		{
			dist[v][v] = 0;
			edge[v][v] = 0;
			scanf("%d %d", &xs[v], &ys[v]);
		}

		LP(i, 0, M)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			from -= 1;
			to -= 1;

			int xDiff = xs[from] - xs[to];
			xDiff *= xDiff;

			int yDiff = ys[from] - ys[to];
			yDiff *= yDiff;

			double cost = sqrt(xDiff + yDiff);

			if (cost < dist[from][to]) {
				dist[from][to] = cost;
				edge[from][to] = cost;
				dist[to][from] = cost;
				edge[to][from] = cost;
			}
		}

		Process();
		NewNode();
	}

	return 0;
}
