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
#define INF 2000000000
#define Ep 1e-8

/*
 read through string, populate graph
 topological sort
 add free varaibles to the result

 */

int const MaxSize = 30;

int n;
SAL graph;
int visited[MaxSize];

int clockV[MaxSize];

int postV;

bool hasCycle;

vector<string> inputs;
vector<char> ans;

void popgraph() {
	LP(index, 1, n)
	{
		string a = inputs[index - 1];
		string b = inputs[index];

		int minSize = min(a.size(), b.size());

		bool same = true;
		int i = 0;
		while (same && i < minSize) {
			if (a[i] == b[i]) {

			} else {
				//cout << a[i] << " " << b[i] << endl;
				graph[b[i] - 'a'].push_back(a[i] - 'a');
				same = false;
			}

			i++;
		}

		if (same && a.size() > b.size())
			hasCycle = true;
	}

}

void dfs(int node) {
	if (visited[node])
		return;
	else
		visited[node] = true;

	LP(i, 0, graph[node].size())
	{
		int next = graph[node][i];

		if (visited[next] && clockV[next] == 0) {
			hasCycle = true;

			//cout << node << " " << next << endl;
		}

		dfs(next);
	}

	postV++;
	clockV[node] = postV;
	ans.push_back('a' + node);
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;

	graph = SAL(MaxSize);

	LP(i, 0, n)
	{
		string a;
		cin >> a;
		inputs.push_back(a);
	}

	hasCycle = false;
	popgraph();

	memset(visited, false, sizeof(visited));
	memset(clockV, 0, sizeof(clockV));
	postV = 0;

	LP(i, 0, MaxSize)
	{
		if (visited[i])
			continue;

		dfs(i);

		if (hasCycle) {
			cout << "Impossible" << endl;
			return 0;
		}
	}

	LP(i, 0, 26)
		cout << ans[i];

	return 0;
}
