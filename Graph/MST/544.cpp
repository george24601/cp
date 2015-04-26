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

//UVa 544 Heavy Cargo
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

const int MaxSize = 210;

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

void MST(int s, int d) {
	int miniMax = 0;

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
			miniMax = cost;

			if (Find(s) == Find(d))
				break;
		}
	}

	printf("%d tons\n\n", miniMax);
}

int NToID(string name) {
	if (nToID[name] == 0)
		nToID[name] = nToID.size();

	return nToID[name];
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while (true) {
		int r;
		cin >> N >> r;

		if (N == 0 && r == 0)
			break;

		caseNum++;

		LPE(i, 1, N)
			parent[i] = i;

		while (!edges.empty())
			edges.pop();

		nToID.clear();

		LP(e, 0, r)
		{
			string first, second;
			int dist;

			cin >> first >> second >> dist;

			edges.push(make_pair(dist, make_pair(NToID(first), NToID(second))));
		}

		printf("Scenario #%d\n", caseNum);
		string s, d;
		cin >> s >> d;
		MST(NToID(s), NToID(d));
	}

	return 0;
}
