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
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e18
/*
 create a graph, with each word letter word[i] <= word[i + 1],

 then try finding cycle with the graph, if there is , then yes, otherwise, false
 */

int const MaxSize = 300;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, t[30];
bool visited[MaxSize + 1][MaxSize + 1][30][8];
bool hit[400][400];

void dfs(int x, int y, int curStep, int dir) {
	if (curStep >= n)
		return;
	if (visited[x][y][curStep][dir])
		return;
	visited[x][y][curStep][dir] = true;

	int nSteps = t[curStep];
	LP(i, 0, nSteps)
	{
		x += dx[dir];
		y += dy[dir];
		hit[x][y] = true; //Notice this order of actions!
	}

	dfs(x, y, curStep + 1, (dir + 1) % 8);
	dfs(x, y, curStep + 1, (dir + 7) % 8);
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> t[i];

	dfs(150, 150, 0, 0);
	int ans = 0;

	LPE(i, 0, MaxSize)
	{
		LPE(j, 0, MaxSize)
		{
			if (hit[i][j])
				ans++;
		}
	}
	cout << ans << endl;
}
