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
leaves:
degree 1, xor sum => know the node
know all degree 1 nodes, and their parent

form parent, know all its children, only parent left, plus the XOR diff => so can infer its parent
so we can keep relaxing

inverse of xor

1 ^ 0 = 1
1 ^ 1 = 0
0 ^ 1 = 1

i.e., just need to keep xoring


relax(i){
assert(degree[i] = 1)

int xor = s[i];

LP(j, 0, tree[i].size()){
	xor ^= tree[i][j];
}

degree[xor] --;
degree[xor].push_back(i);

if(degree[xor] == 1)
	relax(i);
}

 */

int const MaxSize = 100010;

int const MOD = 1000000007;

SAL tree;
int n;

int deg[MaxSize];
int s[MaxSize];
int m;

void relax(int node){
	assert(deg[node] == 1);
	deg[node]--;

	int parent = s[node];

	LP(i, 0, tree[node].size()){
		parent = parent^tree[node][i];
	}

	//printf("%d %d\n", node, parent);

	m++;
	deg[parent]--;
	tree[parent].push_back(node);

	if(1 == deg[parent]){
		relax(parent);
	}
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	tree = SAL(n);

	LP(i, 0, n)
		scanf("%d %d", &deg[i], &s[i]);

	LP(i, 0, n){
		if(1 == deg[i])
			relax(i);
	}

	printf("%d\n", m);

	LP(i, 0, n){
		LP(j, 0, tree[i].size())
				printf("%d %d\n",i, tree[i][j]);
	}



	//print remaining
	return 0;
}
