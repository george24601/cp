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

const int INF = 2147483640;

const int MaxSize = 110;

int s, n;

int dist[MaxSize];
int order[MaxSize];
bool visited[MaxSize];

SAL adj;

int orderNum;

void TopoRelax() {

	LPE(orderN, 0, orderNum -1)
	{
		int node = order[orderN];

		int nN = adj[node].size();

		if (nN == 0) {
			dist[node] = 1;
			continue;
		}

		dist[node] = 0;

		LP(i, 0, adj[node].size())
		{
			int nbr = adj[node][i];
			dist[node] += dist[nbr];
		}
	}
}

void DFS_r(int node) {
	visited[node] = true;

	LP(i, 0, adj[node].size())
	{
		int nbr = adj[node][i];

		if (!visited[nbr]) //not visited yet
			DFS_r(nbr);
	}

	order[orderNum] = node;
	orderNum++;
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (scanf("%d", &n) == 1) {
		caseNum++;

		if (caseNum > 1)
			printf("\n");

		LP(i, 0, n)
		{
			dist[i] = 0;
			visited[i] = false;
		}

		adj = SAL(n);

		LP(i, 0, n)
		{
			int nN;
			scanf("%d", &nN);

			LP(j, 0, nN)
			{
				int neighbor;
				scanf("%d", &neighbor);

				adj[i].push_back(neighbor);
			}
		}

		orderNum = 0;
		DFS_r(s);
		TopoRelax();

		printf("%d\n", dist[0]);
	}

	return 0;
}
