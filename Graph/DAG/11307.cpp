#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 10354 avoiding your boss
//SSSP
typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 10010;
const int MaxK = 6;

#define maxWin 20

int n;

int total[MaxN][6];

SAL adj;
bool parent[MaxN];

int DFS(int node, int used) {

	if (total[node][used] >= 0) {
	} else {
		int minSum = used + 1;

		LP(i, 0, adj[node].size())
		{
			int child = adj[node][i];

			int childMin = INF;
			LP(color,0, 6)
			{
				if (color == used)
					continue;
				childMin = min(childMin, DFS(child, color));
			}

			minSum += childMin;
		}

		total[node][used] = minSum;
	}

	return total[node][used];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (cin >> n) {
		if (n == 0)
			break;
		adj = SAL(n);

		getchar(); //newline

		memset(parent, false, sizeof(parent));

		LP(i, 0, n)
		{
			memset(total[i], -1, sizeof(total[i]));
			string line;
			stringstream ss;
			getline(cin, line);

			ss << line;

			int p;
			ss >> p;
			char c;
			ss >> c;

			int child;
			while (ss >> child) {
				adj[p].push_back(child);
				parent[child] = true;
			}

		}

		LP(i, 0 , n)
		{
			if (!parent[i]) {

				int result = INF;
				LP(color, 0, 6)
					result = min(result, DFS(i, color));

				printf("%d\n", result);
			}
		}
	}

	return 0;
}
