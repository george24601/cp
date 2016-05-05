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

//UVa 1234 RACING
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

const int MaxSize = 10010;

int parent[MaxSize];

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

	int totalCost = 0;
	while (!edges.empty()) {
		pair<int, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;
		int cost = current.first;

		if (Find(from) == Find(to)) {
			totalCost += cost;
			continue;
		} else {
			Union(from, to);
		}
	}

	printf("%d\n", totalCost);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	scanf("%d", &caseNum);

	LP(cn, 0, caseNum)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		LPE(i, 1, n)
			parent[i] = i;

		while (!edges.empty())
			edges.pop();

		LP(i, 0, m)
		{
			int from, to, cost;
			scanf("%d %d %d", &from, &to, &cost);
			edges.push(make_pair(cost, make_pair(from, to)));
		}

		MST();
	}

	return 0;
}
