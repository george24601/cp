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
highest tree
can do union-find



 */
int const MaxSize = 2010;


SAL graph;
int DFS(int i){
	int maxDepth = 0;

	LP(j, 0, graph[i].size())
		maxDepth = max(maxDepth, DFS(graph[i][j]));

	return maxDepth + 1;
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;

	scanf("%d", &n);

	graph = SAL(n);

	LP(i, 0, n){
		int p = 0;
		scanf("%d", &p);

		if(p >  0)
			graph[p -1].push_back(i);
		//cout << i << " " << p << endl;
	}

	int best = 0;
	LP(i, 0, n)
		best = max(best, DFS(i));

	cout << best << endl;



	return 0;
}
