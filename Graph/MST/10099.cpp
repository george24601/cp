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

//UVa 10099 Audiophobia
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

void MST(int s, int d, int number) {

	while (!edges.empty()) {
		pair<int, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;
		int cost = current.first;

		if (Find(from) == Find(to)) {
			continue;
		} else {
			Union(from, to);

			if (Find(s) == Find(d)) {

				int maxLoad = cost - 1;
				int times = number / maxLoad;

				if (number % maxLoad != 0)
					times++;

				printf("Minimum Number of Trips = %d\n\n", times);
				return;
			}
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while (true) {
		int N, R;
		scanf("%d %d", &N, &R);

		if (N == 0 && R == 0)
			break;

		caseNum++;

		LPE(node, 1, N)
			parent[node] = node;

		while (!edges.empty())
			edges.pop();

		LP(i, 0, R)
		{
			int f, s, cost;
			scanf("%d %d %d", &f, &s, &cost);
			edges.push(make_pair(cost, make_pair(f, s)));
		}

		int from, to, number;
		scanf("%d %d %d", &from, &to, &number);

		printf("Scenario #%d\n", caseNum);
		MST(from, to, number);
	}

	return 0;
}
