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

int n, m, k;

int const MaxSize = 510;
string maze[MaxSize];
bool visited[MaxSize][MaxSize];

int deltaR[4] = { 0, -1, 0, 1 };
int deltaC[4] = { -1, 0, 1, 0 };

int steps;

void mark(int r, int c) {
	if (steps == 0 || '#' == maze[r][c])
		return;
	else if (visited[r][c])
		return;

	visited[r][c] = true;
	steps--;


	LP(i, 0, 4)
	{
		int newR = r + deltaR[i];
		int newC = c + deltaC[i];

		if (newR >= 0 && newR < n && newC >= 0 && newC < m)
			mark(newR, newC);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> m >> k;

	LP(i, 0, n)
	{
		cin >> maze[i];
		memset(visited[i], false, sizeof(visited[i]));
	}

	LP(i, 0, n)
	{
		LP(j, 0, m)
		{
			if ('.' == maze[i][j])
				steps++;
		}
	}

	steps -= k;

	LP(i, 0, n)
	{
		LP(j, 0, m)
			mark(i, j);
	}

	LP(i, 0, n)
	{
		LP(j, 0, m)
		{
			if (!visited[i][j] && '.' == maze[i][j])
				maze[i][j] = 'X';
		}
	}

	LP(i, 0, n)
		cout << maze[i] << endl;

	return 0;
}
