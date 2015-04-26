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

//UVa 247 calling cirles
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

SAL adj;
SAL rAdj;

const int MaxSize = 27;

int nIDToPN[MaxSize];
int postNToNID[MaxSize];
bool visited[MaxSize];
bool rVisited[MaxSize];

int sccSize;
int sccMs[MaxSize];

map<string, int> nameToNID;
string nIDToName[MaxSize];

int curSize;

int ToI(char * name) {
	string arr(name);

	if (nameToNID[arr] == 0) {
		curSize++;
		nameToNID[arr] = curSize;
		nIDToName[curSize] = arr;
	}

	return nameToNID[arr];
}

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
	else
		rVisited[node] = true;

	LP(i, 0, rAdj[node].size())
		rDFS_r(rAdj[node][i]);

	sccMs[sccSize] = node;
	sccSize++;
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

		sccSize = 0;
		memset(sccMs, 0, sizeof(sccMs));
		rDFS_r(postNToNID[pn]);

		printf("%s", nIDToName[sccMs[0]].c_str());

		LP(i, 1, sccSize)
			printf(", %s", nIDToName[sccMs[i]].c_str());

		printf("\n");
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);
	int caseNum = 0;
	while (true) {
		int m;
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0)
			break;

		caseNum++;

		curSize = 0;
		postN = 0;
		adj = SAL(n + 1);
		rAdj = SAL(n + 1);
		memset(nIDToPN, 0, sizeof(nIDToPN));
		memset(postNToNID, 0, sizeof(postNToNID));
		memset(visited, false, sizeof(visited));
		memset(rVisited, false, sizeof(rVisited));
		nameToNID.clear();

		char fB[MaxSize];
		char sB[MaxSize];

		LP(i, 0, m)
		{
			scanf("%s %s", fB, sB);
			int fI = ToI(fB);
			int sI = ToI(sB);

			adj[fI].push_back(sI);
			rAdj[sI].push_back(fI);
		}

		if (caseNum > 1)
			printf("\n");

		printf("Calling circles for data set %d:\n", caseNum);
		SCC();

	}

	return 0;
}
