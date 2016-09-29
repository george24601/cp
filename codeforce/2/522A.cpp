#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

#define INF 2000000000

LL const LINF = LL(1e18);
/*
 1. try each 26 length substring
 2. if set size + ??? size  >= 26, we are done
 3. fill in ? with missing ones, remaing ?s with A
 4. print s

 */

int const MaxSize = 4010;
int const AS = 26;
/*
 1. either m += k, (so keep always multiple same)
 2. or m = sqrt(m), and go to next level

 */

SAL graph;

map<string, int> nameToID;

int toID(string name) {
	if (nameToID.count(name) == 0) {
		nameToID[name] = nameToID.size();
	}

	return nameToID[name];
}

int DFS(int id) {

	int maxD = 0;

	LP(i, 0, graph[id].size())
		maxD = max(maxD, DFS(graph[id][i]));

	return maxD + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;
	cin >> n;

	graph = SAL(n + 10);

	LP(i, 0, n)
	{
		string  to, temp, from;
		cin >> to >> temp >> from;
		LP(i, 0, to.length())
			to[i] = tolower(to[i]);

		LP(i, 0, from.length())
			from[i] = tolower(from[i]);

		graph[toID(from)].push_back(toID(to));
	}

	cout << DFS(toID("polycarp")) << endl;

	return 0;
}
