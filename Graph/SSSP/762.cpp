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

//UVa 762  We Ship Cheap
//BFS
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

const int MaxSize = 800;

SAL adj;
map<string, int> sToI;
map<int, string> iToS;

int SToI(string s) {

	if (sToI[s] == 0) {
		sToI[s] = sToI.size();
		iToS[sToI[s]] = s;
	}

	return sToI[s];
}

void Print_r(int node, map<int, int> prevs) {
	if (prevs[node] == node)
		return;

	int prevNode = prevs[node];

	Print_r(prevNode, prevs);

	cout << iToS[prevNode] << " " << iToS[node] << endl;
}

void BFS(int from, int to) {
	queue<int> q;
	map<int, int> prev;
	prev[from] = from;
	q.push(from);

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		LP(i, 0, adj[current].size())
		{
			int next = adj[current][i];

			if (prev.count(next) != 0)
				continue;

			prev[next] = current;
			q.push(next);

			if (next == to) {
				Print_r(to, prev);
				return;
			}
		}
	}

	cout << "No route" << endl;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while (true) {
		int nE;

		if (scanf("%d", &nE) != 1)
			break;
		caseNum++;

		adj = SAL(MaxSize);
		sToI.clear();
		iToS.clear();

		LP(i, 0, nE)
		{
			char first[10];
			char second[10];
			scanf("%s %s", first, second);
			int firstID = SToI(string(first));
			int secondID = SToI(string(second));

			adj[firstID].push_back(secondID);
			adj[secondID].push_back(firstID);
		}

		char first[10];
		char second[10];
		scanf("%s %s", first, second);
		int firstID = SToI(string(first));
		int secondID = SToI(string(second));

		if (caseNum > 1)
			cout << endl;

		if (firstID == secondID)
			cout << iToS[firstID] << " " << iToS[firstID] << endl;
		else
			BFS(firstID, secondID);

	}

	return 0;
}
