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

//UVa 11733  Airport
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

int N, M, A;

map<string, int> nameToID;
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

	int totalRoad = 0;
	int numRoads = 0;

	while (!edges.empty()) {
		pair<int, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;
		int cost = -current.first;

		if (cost >= A)
			break;

		if (Find(from) == Find(to)) {
			continue;
		} else {
			Union(from, to);

			totalRoad += cost;
			numRoads++;
		}
	}

	int numA = N - numRoads;
	int totalC = totalRoad + A * numA;

	printf(" %d %d\n", totalC, numA);
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		scanf("%d %d %d", &N, &M, &A);

		LPE(i, 1, N)
			parent[i] = i;

		while (!edges.empty())
			edges.pop();

		nameToID.clear();

		LP(i, 0, M)
		{
			int X, Y, C;
			scanf("%d %d %d", &X, &Y, &C);

			edges.push(make_pair(-C, make_pair(X, Y)));
		}

		printf("Case #%d:", caseNum);
		MST();
	}

	return 0;
}
