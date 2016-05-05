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

	while (scanf("%d", &n) == 1) {

		if (n == 0)
			break;

		memset(dist, 0, sizeof(dist));

		adj = SAL(n);

		LP(i, 0, n)
		{
			int nN;
			scanf("%d", &nN);

			LP(j, 0, nN)
			{
				int neighbor;
				scanf("%d", &neighbor);

				adj[i].push_back(neighbor - 1);
			}
		}

		LP(i, 0, n)
		{
			memset(visited, false, sizeof(visited));
			orderNum = 0;
			DFS_r(i);

			dist[i] = orderNum;
		}

		int maxDep = 0;
		int maxNode;
		LP(i, 0, n)
		{
			if (dist[i] > maxDep) {
				maxDep = dist[i];
				maxNode = i;
			}
		}

		printf("%d\n", maxNode + 1);
	}

	return 0;
}
