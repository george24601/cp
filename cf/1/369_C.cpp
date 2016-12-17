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
 consider the tree

 if root is problem

 get combined result from all chilren

 if(result is not empty)
 	 return
 else
 	 return if root node is problem

 */

int const MaxSize = 100010;

int const MOD = 1000000007;

SAL tree;
int n;

set<PII> bads;

int visited[MaxSize];

vector<int> res;

void dfs(int node){
	assert(!visited[node]);
	visited[node] = true;

	LP(j, 0, tree[node].size()){
		int next = tree[node][j];

		if(visited[next])
			continue;

		int prevSize = res.size();
		dfs(next);
		int curSize = res.size();

		if(curSize > prevSize)
			continue;

		PII edge = PII(min(node, next), max(node, next));

		if(bads.count(edge))
			res.push_back(next);
	}
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	tree = SAL(n+1);

	LP(i, 0, n - 1){
		int fir, sec, t;

		scanf("%d %d %d", &fir, &sec, &t);

		if(t == 2)
			bads.insert(PII(min(fir, sec), max(fir, sec)));

		tree[fir].push_back(sec);
		tree[sec].push_back(fir);
	}

	dfs(1);

	printf("%d\n", res.size());

	LP(i, 0, res.size()){
		printf("%d", res[i]);

		if(i == n-1)
			printf("\n");
		else
			printf(" ");
	}

	//print remaining
	return 0;
}
