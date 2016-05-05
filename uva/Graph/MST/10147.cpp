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

//UVa 10147 Highways
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
priority_queue<pair<double, FT> > edges;

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

	bool hasEdge = false;
	while (!edges.empty()) {
		pair<double, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;

		if (Find(from) == Find(to)) {
			continue;
		} else {
			Union(from, to);
			printf("%d %d\n", from, to);
			hasEdge = true;
		}
	}

	if(!hasEdge)
		printf("No new highways need\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	scanf("%d", &caseNum);
	LPE(nc, 1, caseNum)
	{
		int N;
		scanf("%d", &N);

		LPE(node, 1, N)
		{
			parent[node] = node;
			scanf("%d %d", &xs[node], &ys[node]);
		}

		while (!edges.empty())
			edges.pop();

		LPE(first, 1, N)
		{
			LPE(second, first + 1, N)
			{
				int x2 = xs[first] - xs[second];
				x2 = x2 * x2;

				int y2 = ys[first] - ys[second];
				y2 = y2 * y2;
				edges.push(make_pair(-sqrt(x2 + y2), make_pair(first, second)));
			}
		}

		int existing = 0;
		scanf("%d", &existing);

		LP(i, 0, existing)
		{
			int first, second;
			scanf("%d %d", &first, &second);
			Union(first, second);
		}

		if(nc > 1)
			printf("\n");

		MST();
	}

	return 0;
}
