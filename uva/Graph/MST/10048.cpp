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

//UVa 10048 Audiophobia
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

const int MaxSize = 110;

int parent[MaxSize];

const int MaxNE = 1010;

int fs[MaxNE];
int ts[MaxNE];
int cs[MaxNE];

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

void MST(int s, int d) {

	while (!edges.empty()) {
		pair<int, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;
		int cost = -current.first;

		if (Find(from) == Find(to)) {
			continue;
		} else {
			Union(from, to);

			if (Find(s) == Find(d)) {
				printf("%d\n", cost);
				return;
			}
		}
	}

	printf("no path\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while (true) {
		int C, S, Q;
		scanf("%d %d %d", &C, &S, &Q);

		if (C == 0 && S == 0 && Q == 0)
			break;

		caseNum++;

		LP(i, 0, S)
			scanf("%d %d %d", &fs[i], &ts[i], &cs[i]);

		if (caseNum > 1)
			printf("\n");

		printf("Case #%d\n", caseNum);

		LP(query, 0, Q)
		{
			LPE(node, 1, C)
				parent[node] = node;

			while (!edges.empty())
				edges.pop();

			LP(i, 0, S)
				edges.push(make_pair(-cs[i], make_pair(fs[i], ts[i])));

			int from, to;
			scanf("%d %d", &from, &to);

			MST(from, to);
		}
	}

	return 0;
}
