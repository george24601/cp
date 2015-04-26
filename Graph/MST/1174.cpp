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

//UVa 1174  IP-TV
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

const int MaxSize = 3000;
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

int MST() {

	int cost = 0;
	while (!edges.empty()) {
		pair<int, FT> current = edges.top();
		edges.pop();

		int from = current.second.first;
		int to = current.second.second;


		if (Find(from) == Find(to))
			continue;

		Union(from, to);
		cost += current.first;
	}

	return cost;
}

int NToI(string name) {
	if (nameToIndex[name] == 0)
		nameToIndex[name] = nameToIndex.size();

	return nameToIndex[name];
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	cin >> numCase;

	LPE(caseNum, 1 , numCase)
	{
		int M, N;
		cin >> M >> N;

		LPE(i, 1, M)
			parent[i] = i;

		while (!edges.empty())
			edges.pop();

		nameToIndex.clear();

		LP(i, 0 , N)
		{
			string B, E;
			int C;
			cin >> B >> E >> C;
			edges.push(make_pair(-C, make_pair(NToI(B), NToI(E))));
		}

		if (caseNum > 1)
			cout << endl;

		cout << -MST() << endl;
	}

	return 0;
}
