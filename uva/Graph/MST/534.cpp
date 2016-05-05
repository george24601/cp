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

//UVa 534 Frogger
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

const int MaxSize = 210;

int xs[MaxSize];
int ys[MaxSize];

int N;

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
	double miniMax = 0;

	while (!edges.empty()) {
		pair<double, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;
		double cost = -current.first;

		if (Find(from) == Find(to)) {
			continue;
		} else {
			Union(from, to);
			miniMax = cost;

			if (Find(0) == Find(1))
				break;
		}
	}

	printf("Frog Distance = %.3lf\n\n", miniMax);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		scanf("%d", &N);

		if (N == 0)
			break;

		caseNum++;

		LP(i, 0, N)
		{
			parent[i] = i;
			scanf("%d %d", &xs[i], &ys[i]);
		}

		while (!edges.empty())
			edges.pop();

		LP(first, 0, N)
		{
			LP(second, first + 1, N)
			{
				double x2 = xs[first] - xs[second];
				x2 = x2 * x2;
				double y2 = ys[first] - ys[second];
				y2 = y2 * y2;

				edges.push(make_pair(-sqrt(x2 + y2), make_pair(first, second)));
			}
		}

		printf("Scenario #%d\n", caseNum);
		MST();
	}

	return 0;
}
