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
using namespace std;

//UVa 10305 Ordering tasks
//cycle finding
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

int n, m;

SAL adj;

bool visited[101];
stack<int> order;

void TS_r(int node) {
	if (visited[node])
		return;
	else
		visited[node] = true;

	LP(i, 0, adj[node].size())
		TS_r(adj[node][i]);

	order.push(node);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &n, &m)) {

		if (n == 0 && m == 0)
			break;

		memset(visited, false, sizeof(visited));

		adj = SAL(n + 1);

		LP(i, 0 , m)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			adj[from].push_back(to);
		}

		LPE(i, 1, n)
			TS_r(i);

		printf("%d", order.top());
		order.pop();

		while (order.size() > 0) {
			printf(" %d", order.top());
			order.pop();
		}

		printf("\n");
	}

	return 0;
}
