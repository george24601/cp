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

#define INF 2000000100

/*

 just DFS the grid, to construct a path the traverse the whole graph,

 then print it that in 2 length seg, except the last one
 */

int n, m, k;

int const MaxSize = 310;

bool visited[MaxSize][MaxSize];

int dR[4] = { 0, -1, 0, 1 };
int dC[4] = { -1, 0, 1, 0 };

vector<PII> path;

void fill(int r, int c) {
	if (visited[r][c])
		return;
	else
		visited[r][c] = true;

	path.push_back(PII(r, c));

	LP(i, 0, 4)
	{
		int newR = r + dR[i];
		int newC = c + dC[i];

		if (newR > 0 && newR <= n && newC > 0 && newC <= m)
			fill(newR, newC);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> m >> k;

	LP(i, 0, n)
		memset(visited[i], false, sizeof(visited[i]));

	fill(1, 1);

	LP(i, 0, k - 1)
	{
		PII firstV = path[2 * i];
		PII secondV = path[2 * i + 1];
		cout << "2 " << firstV.first << " " << firstV.second << " "
				<< secondV.first << " " << secondV.second << endl;
	}

	int remLen = n * m - (k - 1) * 2;

	cout << remLen;

	LP(i, 0, remLen)
	{
		PII v = path[(k - 1) * 2 + i];
		cout << " " << v.first << " " << v.second;
	}

	return 0;
}
