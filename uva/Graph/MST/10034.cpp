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

//UVa 10034 Freckles
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

const int MaxSize = 110;

int n;
double xs[MaxSize];
double ys[MaxSize];

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

double MST() {

	double total = 0;
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
			total += cost;
		}
	}

	return total;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d", &n);

		LP(i, 0, n)
			parent[i] = i;

		while (!edges.empty())
			edges.pop();

		LP(i, 0, n)
			scanf("%lf %lf", &xs[i], &ys[i]);

		LP(from, 0 , n)
		{
			LP(to, from + 1, n)
			{
				double x2 = xs[from] - xs[to];
				x2 = x2 * x2;

				double y2 = ys[from] - ys[to];
				y2 = y2 * y2;

				double length = sqrt(x2 + y2);
				edges.push(make_pair(-length, make_pair(from, to)));
			}
		}

		double total = MST();

		if(caseNum > 1)
			printf("\n");

		printf("%.2lf\n", total);

	}

	return 0;
}
