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

//UVa 11747  Heavy Cycle Edges
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
map<string, int> nameToIndex;

const int MaxSize = 1010;
int parent[MaxSize];

int cycleEs[2510];
int cycleESize;

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

	while (!edges.empty()) {
		pair<int, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;

		if (Find(from) == Find(to)) {
			cycleEs[cycleESize] = -current.first;
			cycleESize++;
		} else
			Union(from, to);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		int n, m;
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0)
			break;

		LP(i, 0, n)
			parent[i] = i;

		while (!edges.empty())
			edges.pop();

		cycleESize = 0;

		memset(cycleEs, 0, sizeof(cycleEs));

		LP(i, 0 , m)
		{
			int from, to, length;
			scanf("%d %d %d", &from, &to, &length);
			edges.push(make_pair(-length, make_pair(from, to)));
		}

		MST();

		if (cycleESize > 0) {
			printf("%d", cycleEs[0]);
			LP(i, 1, cycleESize)
				printf(" %d", cycleEs[i]);

			printf("\n");

		} else {
			printf("forest\n");
		}

	}

	return 0;
}
