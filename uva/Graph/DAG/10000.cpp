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

	for (int orderN = orderNum - 1; orderN >= 0; orderN--) {
		int node = order[orderN];

		int newDist = dist[node] + 1;
		LP(i, 0, adj[node].size())
		{
			int neighbor = adj[node][i];

			if (dist[neighbor] < newDist) {
				dist[neighbor] = newDist;
			}
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

void TopoSort() {
	orderNum = 0;
	DFS_r(s);
}

int main() {
//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;

		caseNum++;

		scanf("%d", &s);

		s -= 1;

		LP(i, 0, n)
		{
			dist[i] = 0;
			visited[i] = false;
		}

		adj = SAL(n);

		while (true) {
			int p, q;
			scanf("%d %d", &p, &q);

			if (p == 0 && q == 0)
				break;

			adj[p - 1].push_back(q - 1);
		}

		TopoSort();
		TopoRelax();

		int longDist = -1;
		int endNode = -1;

		LP(i, 0, n)
		{
			if (dist[i] > longDist) {
				longDist = dist[i];
				endNode = i;
			}
		}

		if (longDist == 0)
			endNode = s;

		printf(
				"Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
				caseNum, s + 1, longDist, endNode + 1);
	}

	return 0;
}
