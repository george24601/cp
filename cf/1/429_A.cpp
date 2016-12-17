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
the min # is deterministic

ans(node, curFlip, pFilp)
{
	if(node is value)
		do nothing
	else
		!curFilp

		cost++

	for each children
		  pFilp

}



 */

int const MaxSize = 100010;

int const MOD = 1000000007;

SAL tree;
int n;

int init[MaxSize];
int goal[MaxSize];

bool visited[MaxSize];
vector<int> choices;

void dfs(int node, bool curSame, bool parentSame){
	assert(!visited[node]);
	visited[node] = true;

	bool match = init[node] == goal[node];

	if(!curSame)
		match = !match;

	if(!match){
		choices.push_back(node);
		curSame = !curSame;
	}

	LP(i, 0, tree[node].size()){

		int child = tree[node][i];

		if(visited[child])
			continue;

		dfs(child, parentSame, curSame);
	}
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	tree = SAL(n+ 1);

	LP(i, 0 , n-1){
		int a, b;
		scanf("%d %d", &a , &b);

	//	cout << a << " " << b << endl;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	//cout << " init done" << endl;

	LPE(i, 1, n)
		scanf("%d", &init[i]);

	LPE(i, 1, n)
		scanf("%d", &goal[i]);

	memset(visited, false, sizeof(visited));


	dfs(1, true, true);

	printf("%d\n", choices.size());

	LP(i, 0, choices.size())
		printf("%d\n", choices[i]);

	//print remaining
	return 0;
}
