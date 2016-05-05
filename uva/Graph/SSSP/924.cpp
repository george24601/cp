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

void BFS(int from) {
	queue<int> q;
	map<int, int> prev;
	prev[from] = from;
	q.push(from);

	int level = 0;
	int M = 0;
	int D = 0;
	while (!q.empty()) {

		queue<int> nextLevel;

		//iterate through level
		while (!q.empty()) {
			int current = q.front();
			q.pop();

			LP(i, 0, adj[current].size())
			{
				int next = adj[current][i];

				if (prev.count(next) != 0)
					continue;

				prev[next] = current;
				nextLevel.push(next);
			}
		}

		level++;

		if(nextLevel.size() > M)
		{
			M = nextLevel.size();
			D = level;
		}

		while(!nextLevel.empty())
		{
			int current = nextLevel.front();
			nextLevel.pop();

			q.push(current);
		}

	}

	if(M == 0)
		printf("%d\n", M);
	else
		printf("%d %d\n", M, D);

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int E;
	scanf("%d", &E);
	adj = SAL(E + 1);

	LP(node, 0, E)
	{
		int numEs = 0;
		scanf("%d", &numEs);

		LP(edge, 0, numEs)
		{
			int nei = 0;
			scanf("%d", &nei);

			adj[node].push_back(nei);
		}
	}

	int T;
	scanf("%d", &T);

	LP(i, 0, T)
	{
		int source;
		scanf("%d", &source);
		BFS(source);
	}

	return 0;
}
