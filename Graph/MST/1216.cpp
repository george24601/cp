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

//UVa 1216 The bug sensor system
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

const int MaxSize = 2000;

int xs[MaxSize];
int ys[MaxSize];

int N;

int parent[MaxSize];

map<string, int> nToID;

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

void MST(int maxNumC) {
	double miniMax = 0;
	int totalC = N;

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

			totalC--;
			if (totalC == maxNumC)
				break;
		}
	}

	printf("%d\n", (int) ceil(miniMax));
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	scanf("%d", &caseNum);

	LP(cn, 0, caseNum)
	{
		int nc;
		scanf("%d", &nc);

		N = 0;

		while (true) {
			int x, y;

			scanf("%d", &x);
			if (x == -1)
				break;
			scanf("%d", &y);

			parent[N] = N;
			xs[N] = x;
			ys[N] = y;

			N++;
		}

		while (!edges.empty())
			edges.pop();

		LP(first, 0, N)
		{
			LP(second, first + 1, N)
			{
				int xD = xs[first] - xs[second];
				double xDiff = pow(xD, 2);
				int yD = ys[first] - ys[second];
				double yDiff = pow(yD, 2);
				edges.push(
						make_pair(-sqrt(xDiff + yDiff),
								make_pair(first, second)));
			}
		}

		MST(nc);
	}

	return 0;
}
