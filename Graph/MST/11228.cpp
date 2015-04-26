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

//UVa 11228 Transportation system
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

const int MaxSize = 1010;

int n, r;
int xs[MaxSize];
int ys[MaxSize];

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

	double inS = 0;
	double outS = 0;
	int numS = 1;

	while (!edges.empty()) {
		pair<double, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;

		if (Find(from) == Find(to)) {
			continue;
		} else {
			Union(from, to);

			double cost = -current.first;

			if (cost <= r) {
				inS += cost;
			} else {
				outS += cost;
				numS++;
			}
		}
	}

	printf(" %d %d %d\n", numS, (int) round(inS), (int) round(outS));
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		scanf("%d %d", &n, &r);

		LP(i, 0, n)
			parent[i] = i;

		while (!edges.empty())
			edges.pop();

		LP(i, 0, n)
			scanf("%d %d", &xs[i], &ys[i]);

		LP(from, 0 , n)
		{
			LP(to, from + 1, n)
			{
				int x2 = xs[from] - xs[to];
				x2 = x2 * x2;

				int y2 = ys[from] - ys[to];
				y2 = y2 * y2;

				double length = sqrt(x2 + y2);
				edges.push(make_pair(-length, make_pair(from, to)));
			}
		}

		printf("Case #%d:", caseNum);
		MST();
	}

	return 0;
}
