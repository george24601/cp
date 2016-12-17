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

 */

int n, m;
SAL graph;
int const MaxSize = 100010;
int visited[MaxSize];
vector<int> first;
vector<int> second;

bool valid;

void dfs(int v, int part) {
	if (visited[v]) {
		if (visited[v] != part)
			valid = false;

		return;
	}

	visited[v] = part;


	if (1 == part)
		first.push_back(v);
	else
		second.push_back(v);

	//cout << v << " " << first.size() << " " << second.size() << endl;

	int nextPart = part == 1 ? 2 : 1;

	LP(i, 0, graph[v].size())
	{
		int u = graph[v][i];

		dfs(u, nextPart);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d %d", &n, &m);

	graph = SAL(n + 1);
	memset(visited, 0, sizeof(visited));

	LP(i, 0, m)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	valid = true;
	LPE(v, 1, n)
	{
		if (visited[v] || graph[v].size() == 0) //ignore nodes with no edges
			continue;

		dfs(v, 1);
	}

	if (valid) {
		int firstC = first.size();
		printf("%d\n", firstC);

		LP(i, 0, firstC){
			printf("%d", first[i]);

			if(i < firstC - 1)
				printf(" ");
			else
				printf("\n");
		}

		int secondC = second.size();
		printf("%d\n", secondC);

		LP(i, 0, secondC){
			printf("%d", second[i]);
			if(i < secondC - 1)
				printf(" ");
			else
				printf("\n");
		}

	} else {
		printf("-1\n");
	}

	return 0;
}

