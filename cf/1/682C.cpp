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
maxSave(node, prevCost)
if(prevCost > a[node])
	return 0;

int res += 1




 */
int const MaxSize = 100010;
int a[MaxSize];
bool visited[MaxSize];
WAL adj;
int n;

int maxSave(int node, LL pathMaxCost){
	assert(!visited[node]);
	visited[node] = true;

	if(pathMaxCost > a[node])
		return 0;

	int res = 1;

	LP(ni, 0, adj[node].size()){
		int child = adj[node][ni].first;

		if(visited[child])
			continue;

		LL cost = (LL) adj[node][ni].second;

		if(pathMaxCost > 0)
			cost += pathMaxCost;

		res += maxSave(child, cost);
	}

	return res;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	memset(visited, false, sizeof(visited));

	adj = WAL(n+1);

	LPE(i, 1, n)
		scanf("%d", &a[i]);

	//tree has n-1 edges
	LP(i, 0, n - 1){
		int node = i + 2;
		int other, cost;
		scanf("%d %d", &other, &cost);

		cout << node << " " << other << " " << cost << endl;

		adj[node].push_back(PII(other, cost));
		adj[other].push_back(PII(node, cost));
	}

	int saved = maxSave(1, 0);

	cout << n - saved << endl;

	return 0;
}
