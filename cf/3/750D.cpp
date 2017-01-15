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

 */

int const MaxSize = 30;
int n, ts[MaxSize];

int const MaxVisit = 160;
bool hit[2 * MaxVisit][2 * MaxVisit];
bool visited[2 * MaxVisit][2 * MaxVisit][8][5];

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void go(int curStep, int x, int y, int dir) {

	if (curStep >= n)
		return;

	int nSteps = ts[curStep];

	//if (visited[x][y][dir][nSteps - 1])
	//	return;

	int finalX = x + (nSteps - 1) * dx[dir];
	int finalY = y + (nSteps - 1) * dy[dir];

	LPE(i, 1, nSteps)
	{
		if (visited[x][y][dir][nSteps - i])
			break;
		else {
			visited[x][y][dir][nSteps - i] = true;
			hit[x][y] = true;
			x += dx[dir];
			y += dy[dir];
		}
	}

	int leftDir = (dir - 1 + 8) % 8;
	go(curStep + 1, finalX + dx[leftDir], finalY + dy[leftDir], leftDir);

	int rightDir = (dir + 1 + 8) % 8;
	go(curStep + 1, finalX + dx[rightDir], finalY + dy[rightDir], rightDir);
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> ts[i];

	go(0, 155, 155, 0);

	int total = 0;

	LP(x, 0, 2 * MaxVisit)
	{
		LP(y, 0, 2 * MaxVisit)
		{
			if (hit[x][y])
				total++;
		}
	}

	cout << total << endl;

	return 0;
}

