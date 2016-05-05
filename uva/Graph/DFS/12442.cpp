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
using namespace std;

//UVa 12442 Forwarding emails
//graph traversal

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n, m;
int neighbor[50001];
int reachable[50001];
bool visited[50001];

void DFS_r(int node) {

	visited[node] = true;
	int next = neighbor[node];

	if (next == 0 || visited[next]) {
		reachable[node] = 0;
	} else {
		DFS_r(next);
		reachable[node] = 1 + reachable[next];
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		scanf("%d", &n);

		memset(neighbor, 0, sizeof(neighbor));
		memset(reachable, -1, sizeof(reachable));
		memset(visited, false, sizeof(visited));

		LP(i, 0, n)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			neighbor[u] = v;
		}

		int maxVal = 0;
		int maxNode;

		LPE(i, 1, n)
		{
			if (reachable[i] >= 0)
				continue;

			DFS_r(i);
			if (reachable[i] > maxVal) {
				maxVal = reachable[i];
				maxNode = i;
			}

			memset(visited, false, sizeof(visited));
		}

		printf("Case %d: %d\n", caseNum, maxNode);
	}

	return 0;
}

