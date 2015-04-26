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

const int MaxSize = 40;

int dims[MaxSize][MaxSize];
int dim, n;

int dist[MaxSize];
int prev[MaxSize];
int order[MaxSize];
bool visited[MaxSize];

SAL adj;

int orderNum;

void TopoRelax() {

	for (int orderN = n - 1; orderN >= 0; orderN--) {
		int node = order[orderN];

		int newDist = dist[node] + 1;
		LP(i, 0, adj[node].size())
		{
			int neighbor = adj[node][i];

			if (dist[neighbor] < newDist) {
				dist[neighbor] = newDist;
				prev[neighbor] = node;
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
	LP(i, 0,n)
	{
		if (visited[i])
			continue;

		DFS_r(i);
	}
}

bool Smaller(int from, int to) {
	LP(i, 0, dim)
	{
		if (dims[from][i] >= dims[to][i])
			return false;
	}

	return true;
}

void P_r(int node) {
	int prevN = prev[node];

	if (prevN == node) {
		printf("%d", node + 1);
	} else {
		P_r(prevN);
		printf(" %d", node + 1);
	}
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &n, &dim) == 2) {

		LP(i, 0, n)
		{
			dist[i] = 0;
			prev[i] = i;
			visited[i] = false;

			LP(j, 0, dim)
				scanf("%d", &dims[i][j]);

			sort(dims[i], dims[i] + dim);
		}

		adj = SAL(n);

		LP(from, 0, n)
		{
			LP(to, 0, n)
			{
				if (from == to)
					continue;

				if (Smaller(from, to))
					adj[from].push_back(to);
			}
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

		printf("%d\n", longDist + 1);
		P_r(endNode);
		printf("\n");
	}

	return 0;
}
