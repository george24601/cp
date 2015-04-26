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

//UVa 1235  Anti Brute
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

const int MaxSize = 510;

int N;

int parent[MaxSize];

char locks[MaxSize][5];

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

int MST() {

	int totalRoad = 0;

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

			totalRoad += cost;
		}
	}

	return totalRoad;
}

int Dist(char * first, char* second) {
	int total = 0;

	LP(i, 0, 4)
	{
		int diff = abs(first[i] - second[i]);

		if (diff > 5)
			diff = 10 - diff;

		total += diff;
	}

	return total;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		scanf("%d", &N);

		LP(i, 0, N)
		{
			parent[i] = i;
			scanf("%s", locks[i]);
		}

		while (!edges.empty())
			edges.pop();

		int minStart = 500;
		LP(first, 0, N)
		{
			int startDist = Dist(locks[first], "0000");
			minStart = Min(startDist, minStart);

			LP(second, first + 1, N)
			{
				edges.push(
						make_pair(-Dist(locks[first], locks[second]),
								make_pair(first, second)));
			}
		}

		int total = MST();
		printf("%d\n", total + minStart);
	}

	return 0;
}
