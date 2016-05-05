#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;

//UVa 12476 as long as I learn
//graph traversal

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n, m;
int nV [101];

SAL adj;

int curNode;
int curVal;

void DFS_r(int node)
{
	curNode = node;
	curVal += nV[node];

	if(adj[node].size() == 0)
		return;

	int nextVal = 0;
	int nextToVisit;
	LP(i, 0, adj[node].size())
	{
		int neighbor = adj[node][i];

		if(nV[neighbor] >nextVal)
		{
			nextVal = nV[neighbor];
			nextToVisit = neighbor;
		}
	}

	DFS_r(nextToVisit);

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		scanf("%d %d", &n, &m);

		LP(i, 0, n)
			scanf("%d", &nV[i]);

		SAL newAdj(n + 1);
		adj = newAdj;
		curVal = 0;

		LP(i, 0, m)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			adj[u].push_back(v);
		}

		DFS_r(0);

		printf("Case %d: %d %d\n", caseNum, curVal, curNode);
	}

	return 0;
}

