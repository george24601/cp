#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-8

/*
 for each v
 if visited, ignore
 mark as visited
 while parent[curent] is not visited and parent[current] != current
 current = parent current

 if parent[current] = current
 add this to list of heads
 else if parent[current] = v
 add current to list of heads

 */

int n;
int const MaxSize = 200010;
int p[MaxSize];
int ans[MaxSize];
bool visited[MaxSize];
vector<int> roots;

int finalRoot;

int main() {
	ios_base::sync_with_stdio(false);
//	freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d", &n);

	LPE(i, 1, n)
	{
		scanf("%d", &p[i]);
		ans[i] = p[i];
	}

	memset(visited, false, sizeof(visited));

	finalRoot = 0;

	LPE(v, 1, n)
	{
		if (visited[v])
			continue;

		set<int> path;

		int current = v;
		visited[current] = true;
		path.insert(current);

		while (!visited[p[current]]) {
			current = p[current];
			visited[current] = true;
			path.insert(current);
		}

		if (path.count(p[current])) {
			//cycle detected, include node to itself
			if (p[current] == current) {
				finalRoot = current;
			}

			roots.push_back(current);
		}
	}

	if (!finalRoot)
		finalRoot = roots[0];

	int totalCost = 0;

	LP(i, 0, roots.size())
	{
		int curR = roots[i];

		ans[curR] = finalRoot;

		if (ans[curR] != p[curR])
			totalCost++;
	}

	printf("%d\n", totalCost);

	LPE(i, 1, n)
	{
		printf("%d", ans[i]);

		if (i < n)
			printf(" ");
		else
			printf("\n");
	}

	return 0;
}

