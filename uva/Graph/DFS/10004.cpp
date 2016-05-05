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

//UVa 10004 Bicoloring
//graph - DFS
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

SAL adj;
const int MaxSize = 200;

int visited[MaxSize];

bool P_r(int curNode) {

	LP(i, 0, adj[curNode].size())
	{
		int toNode = adj[curNode][i];

		if (visited[toNode] == 0) {
			visited[toNode] = visited[curNode] == 1 ? 2 : 1;
			bool bicolorable = P_r(adj[curNode][i]);
			if (!bicolorable)
				return false;
		} else if (visited[toNode] == visited[curNode])
			return false;

	}

	return true;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		memset(visited, 0, sizeof(visited));

		adj = SAL(n);

		int l;
		scanf("%d", &l);

		LP(i, 0 , l)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		visited[0] = 1;

		bool bicolorable = P_r(0);

		if (bicolorable)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");

	}

	return 0;
}
