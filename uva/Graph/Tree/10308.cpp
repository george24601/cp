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

//UVa 10354 avoiding your boss
//SSSP
typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 10001;

WAL adj;

int dist[MaxN];

void S_r(int node, int curDist) {
	if (dist[node] >= 0)
		return;
	else
		dist[node] = curDist;

	LP(i, 0, adj[node].size())
	{
		int neighbor = adj[node][i].first;
		int cost = adj[node][i].second;

		S_r(neighbor, curDist + cost);
	}
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	string line;
	while (cin.peek() != EOF) {
		int firstTry = -1;
		adj = WAL(MaxN);
		while (getline(cin, line)) {
			if (line.length() == 0)
				break;

			stringstream ss;
			ss << line;

			int from, to, length;
			ss >> from >> to >> length;

			adj[from].push_back(make_pair(to, length));
			adj[to].push_back(make_pair(from, length));

			firstTry = from;
		}

		memset(dist, -1, sizeof(dist));

		S_r(firstTry, 0);

		int furthest;
		int curMax = -INF;

		LP(i, 1, MaxN)
		{
			if (dist[i] > curMax) {
				curMax = dist[i];
				furthest = i;
			}
		}

		memset(dist, -1, sizeof(dist));

		S_r(furthest, 0);

		curMax = -1;
		LP(i, 1, MaxN)
			curMax = max(dist[i], curMax);

		printf("%d\n", curMax);
	}

	return 0;
}
