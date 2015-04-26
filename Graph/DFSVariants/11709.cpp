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

//UVa 11709 trust groups
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

int P;
int postN;

SAL adj;
SAL rAdj;

const int MaxSize = 2000;

int nIDToPN[MaxSize];
int postNToNID[MaxSize];
bool visited[MaxSize];
bool rVisited[MaxSize];

map<string, int> nameToNID;
string nIDToName[MaxSize];

int curSize;
int comp;

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
}

void SCC() {

	LPE(i, 1, P)
	{
		if (nIDToPN[i] == 0)
			DFS_r(i);
	}

	for (int pn = P; pn >= 1; pn--) {
		if (rVisited[postNToNID[pn]])
			continue;

		comp++;
		rDFS_r(postNToNID[pn]);

	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);
	int T;
	while (true) {
		cin >> P >> T;

		if (P == 0 && T == 0)
			break;

		string nl;
		getline(cin, nl);

		curSize = 0;
		postN = 0;
		adj = SAL(P + 1);
		rAdj = SAL(P + 1);
		memset(nIDToPN, 0, sizeof(nIDToPN));
		memset(postNToNID, 0, sizeof(postNToNID));
		memset(visited, false, sizeof(visited));
		memset(rVisited, false, sizeof(rVisited));
		nameToNID.clear();
		comp = 0;

		LPE(nID, 1, P)
		{
			string name;
			getline(cin, name);

			nameToNID[name] = nID;
		}

		LP(edge, 0, T)
		{
			string first, second;
			getline(cin, first);

			int fI = nameToNID[first];

			getline(cin, second);
			int sI = nameToNID[second];

			adj[fI].push_back(sI);
			rAdj[sI].push_back(fI);
		}

		SCC();

		printf("%d\n", comp);

	}

	return 0;
}
