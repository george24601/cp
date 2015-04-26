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

const int MaxSize = 1100;

int n;
WAL adj;
int dist[MaxSize][MaxSize];
int totalPath[MaxSize][MaxSize];

void Process() {

	LP(k, 0, n)
	{
		LP(i, 0 , n)
		{
			LP(j, 0, n)
			{
				if (dist[i][k] == INF || dist[k][j] == INF)
					continue;

				int newCost = dist[i][k] + dist[k][j];
				int newPathLen = totalPath[i][k] + totalPath[k][j];

				if (newCost < dist[i][j]) {
					dist[i][j] = newCost;
					totalPath[i][j] = newPathLen;
				} else if (newCost == dist[i][j]) {
					totalPath[i][j] = min(totalPath[i][j], newPathLen);
				}
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
		if (caseNum > 1)
			printf("\n");

		int D;
		scanf("%d %d", &n, &D);

		LP(v, 0 , n)
		{
			LP(u, 0, n)
			{
				dist[v][u] = INF;
				totalPath[v][u] = INF;
			}
		}

		LP(v, 0 , n)
		{
			dist[v][v] = 0;
			totalPath[v][v] = 0;
		}

		LP(i, 0, D)
		{
			int from, to, cost, length;
			scanf("%d %d %d %d", &from, &to, &cost, &length);
			from -= 1;
			to -= 1;

			if (cost < dist[from][to]) {
				dist[from][to] = cost;
				dist[to][from] = cost;
				totalPath[from][to] = length;
				totalPath[to][from] = length;
			} else if (cost == dist[from][to]) {
				totalPath[from][to] = min(totalPath[from][to], length);
				totalPath[to][from] = min(totalPath[to][from], length);
			}
		}

		Process();

		int numQ;
		scanf("%d", &numQ);

		LP(i, 0, numQ)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			from -= 1;
			to -= 1;

			if (dist[from][to] == INF)
				printf("No Path.\n");
			else
				printf("Distance and time to reach destination is %d & %d.\n",
						totalPath[from][to], dist[from][to]);
		}

	}

	return 0;
}
