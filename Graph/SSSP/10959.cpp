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
#include <queue>
using namespace std;

//UVa 10959 The party
//BFS
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

const int MaxSize = 1010;

SAL adj;

int P, D;

void BFS() {
	queue<int> q;
	map<int, int> dist;
	dist[0] = 0;
	q.push(0);

	//iterate through level
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		LP(i, 0, adj[current].size())
		{
			int next = adj[current][i];

			if (dist.count(next) != 0)
				continue;

			dist[next] = dist[current] + 1;
			q.push(next);
		}
	}

	LP(i, 1, P)
		printf("%d\n", dist[i]);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d %d", &P, &D);

		adj = SAL(P);

		LP(i, 0, D)
		{
			int from, to;
			scanf("%d %d", &from, &to);

			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		if (caseNum > 1)
			printf("\n");

		BFS();

	}

	return 0;
}
