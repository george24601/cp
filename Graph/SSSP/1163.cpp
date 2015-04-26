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

//UVa 1112 Teams
//Counting
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 101;

int N, E, T;

WAL adj;

void Process() {
	PII start = PII(0, E);

	priority_queue<PII> pq;
	pq.push(start);

	map<int, int> dist;

	LPE(n, 1, N)
		dist[n] = 2000000000;

	dist[E] = 0;

	bool canExit[MaxSize];

	memset(canExit, false, sizeof(canExit));

	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();

		int curDist = -cur.first;
		int u = cur.second;

		if (curDist > T)
			break;
		else
			canExit[u] = true;

		if (curDist != dist[u])
			continue; //we processed a better solution already

		LP(i, 0, adj[u].size())
		{
			int v = adj[u][i].first;
			int nextCost = dist[u] + adj[u][i].second;

			if (nextCost >= dist[v])
				continue;
			else {
				dist[v] = nextCost;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}

	int counter = 0;
	LPE(i, 1, N)
	{
		if (canExit[i])
			counter++;
	}

	printf("%d\n", counter);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	scanf("%d", &caseNum);

	LPE(c, 1, caseNum)
	{
		scanf("%d", &N);
		scanf("%d", &E);
		scanf("%d", &T);
		int M;
		scanf("%d", &M);

		adj = WAL(N + 1);

		LP(e, 0, M)
		{
			int from, to, time;
			scanf("%d %d %d", &from, &to, &time);

			adj[to].push_back(make_pair(from, time));
		}

		if (c > 1)
			printf("\n");

		Process();
	}

	return 0;
}
