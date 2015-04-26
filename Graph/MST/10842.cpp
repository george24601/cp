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

//UVa 10842 Traffic flow
//MST
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

//need to put negative, because PQ pops biggest first
priority_queue<pair<int, FT> > edges;

const int MaxSize = 800;

int parent[MaxSize];

int xs[MaxSize];
int ys[MaxSize];

int Find(int a) {
	if (parent[a] != a)
		parent[a] = Find(parent[a]);

	return parent[a];
}

void Union(int a, int b) {

	int aP = Find(a);
	int bP = Find(b);

	if (aP == bP)
		return;

	parent[Max(aP, bP)] = Min(aP, bP);
}

void MST() {

	int cost = 0;
	while (!edges.empty()) {
		pair<int, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;

		if (Find(from) == Find(to)) {
			continue;
		} else {
			Union(from, to);
			cost = current.first;
		}
	}

	printf("%d\n", cost);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum,1, numCase)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		while (!edges.empty())
			edges.pop();

		LP(node, 0, n)
			parent[node] = node;

		LP(i, 0, m)
		{
			int first, second, cost;
			scanf("%d %d %d", &first, &second, &cost);

			edges.push(make_pair(cost, make_pair(first, second)));
		}

		printf("Case #%d: ", caseNum);
		MST();
	}

	return 0;
}
