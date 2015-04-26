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
#include <map>
#include <stack>
using namespace std;

//UVa 11770 Lighting away
//SCC
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

int n;
int postN;

const int MaxSize = 100010;

SAL adj;
SAL rAdj;

int nIDToPN[MaxSize];
int postNToNID[MaxSize];
bool visited[MaxSize];
bool rVisited[MaxSize];

int comp;
int nodeToComp[MaxSize];

void DFS_r(int node) {
	if (visited[node])
		return;
	else
		visited[node] = true;

	LP(i, 0, adj[node].size())
		DFS_r(adj[node][i]);

	postN++;
	nIDToPN[node] = postN;
	postNToNID[postN] = node;
}

void rDFS_r(int node) {
	if (rVisited[node])
		return;

	rVisited[node] = true;
	nodeToComp[node] = comp;

	LP(i, 0, rAdj[node].size())
		rDFS_r(rAdj[node][i]);

}

void SCC() {

	LPE(i, 1, n)
	{
		if (nIDToPN[i] == 0)
			DFS_r(i);
	}

	for (int pn = n; pn >= 1; pn--) {
		if (rVisited[postNToNID[pn]])
			continue;

		comp++;

		rDFS_r(postNToNID[pn]);

	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);
	int caseNum = 0;

	scanf("%d", &caseNum);

	LPE(c, 1, caseNum)
	{
		int m;

		scanf("%d %d", &n, &m);

		postN = 0;
		memset(nIDToPN, 0, sizeof(nIDToPN));
		memset(postNToNID, 0, sizeof(postNToNID));
		memset(visited, false, sizeof(visited));
		memset(rVisited, false, sizeof(rVisited));

		adj = SAL(MaxSize);
		rAdj = SAL(MaxSize);
		comp = 0;

		LP(line, 0, m)
		{
			int from, to;
			scanf("%d %d", &from, &to);

			adj[from].push_back(to);
			rAdj[to].push_back(from);
		}

		SCC();

		bool hasIn[MaxSize];

		memset(hasIn, false, sizeof(hasIn));

		LPE(node, 1, n)
		{
			int curComp = nodeToComp[node];

			LP(i, 0, adj[node].size())
			{
				int to = adj[node][i];
				int toComp = nodeToComp[to];

				if (curComp != toComp)
					hasIn[toComp] = true;
			}
		}

		int total = 0;

		LPE(i, 1,comp)
		{
			if (!hasIn[i])
				total++;
		}

		printf("Case %d: %d\n", c, total);

	}

	return 0;
}
