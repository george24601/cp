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

//UVa 10986 Sending email
//Dijkstra
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

int n, m, S, T;

WAL adj;

void Process() {
	PII start = PII(0, S);

	priority_queue<PII> pq;
	pq.push(start);

	map<int, int> dist;

	LP(i, 0, n)
		dist[i] = 2000000000;

	dist[S] = 0;

	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();

		int curDist = -cur.first;
		int u = cur.second;

		if (u == T)
		{
			printf("%d\n", curDist);
			return;
		}

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

	printf("unreachable\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	scanf("%d", &caseNum);

	LPE(c, 1, caseNum)
	{
		scanf("%d %d %d %d", &n, &m, &S, &T);

		adj = WAL(n);

		LP(e, 0, m)
		{
			int from, to, time;
			scanf("%d %d %d", &from, &to, &time);

			adj[from].push_back(make_pair(to, time));
			adj[to].push_back(make_pair(from, time));
		}

		printf("Case #%d: ", c);

		Process();
	}

	return 0;
}
