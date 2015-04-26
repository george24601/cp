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

//UVa 924 Spreading the news
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

const int MaxSize = 800;

SAL adj;

void BFS(int from, int to) {
	queue<int> q;
	map<int, int> dist;
	dist[from] = 0;
	q.push(from);

	//iterate through level
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == to)
			break;

		LP(i, 0, adj[current].size())
		{
			int next = adj[current][i];

			if (dist.count(next) != 0)
				continue;

			dist[next] = dist[current] + 1;
			q.push(next);
		}
	}

	printf("%d %d %d\n", from, to, dist[to] - 1);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		int N;
		scanf("%d", &N);
		adj = SAL(N + 1);

		LP(node, 0, N)
		{
			int id;
			scanf("%d", &id);
			int numEs = 0;
			scanf("%d", &numEs);

			LP(edge, 0, numEs)
			{
				int nei = 0;
				scanf("%d", &nei);

				adj[id].push_back(nei);
			}
		}

		int from, to;
		scanf("%d %d", &from, &to);

		if (caseNum > 1)
			printf("\n");

		BFS(from, to);
	}

	return 0;
}
