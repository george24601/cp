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
 # of snowdrift = # of components - 1

 */

int const MaxSize = 110;

int const MOD = 1000000007;

int n;
int x[MaxSize];
int y[MaxSize];
SAL graph;
int visited[MaxSize];

void dfs(int node){
	if(visited[node])
		return;
	else
		visited[node] = true;

	LP(i, 0, graph[node].size())
		dfs(graph[node][i]);
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d" , &n);

	LP(i, 0, n)
		scanf("%d %d", &x[i], &y[i]);

	graph = SAL(n);

	LP(i, 0, n){
		LP(j, i + 1, n){
			if(x[i] == x[j] || y[i] == y[j]){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	int comp = 0;

	memset(visited, false, sizeof(visited));

	LP(i, 0, n){
		if(visited[i])
			continue;

		comp++;
		dfs(i);
	}


	cout << comp - 1 << endl;

	return 0;
}
