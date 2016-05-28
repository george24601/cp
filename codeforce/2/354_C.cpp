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
 at one block
 (i, j, o)
 either update to (i, j, o+1)
 or update to its neighbor
 */

int const MaxSize = 1000;
int const Ori = 4;
char maze[MaxSize][MaxSize];
int n, m;
int xt, yt, xm, ym;
int dist[MaxSize][MaxSize][Ori];
bool visited[MaxSize][MaxSize][Ori];
bool hasDoor[MaxSize][MaxSize][Ori][Ori];
queue<pair<PII, int> > toVisit;

int deltaX[4] = { -1, 0, 1, 0 };
int deltay[4] = { 0, 1, 0, -1 };
int counterDir = { 2, 3, 0, 1 };

void calcDoors() {
	LP(i, 0, n)
	{
		LP(j, 0, m)
		{
			char c = maze[i][j];

			if('+' == c){

			}else if('-' == c){

			}else if('|' == c){

			}else if('^' == c){

			}else if('>' == c){

			}else if('<' == c){

			}else if('v' == c){

			}else if('L' == c){

			}else if('R' == c){

			}else if('U' == c){

			}
		}
	}

}

void goNeighbor(int x, int y, int o) {

	LP(dir, 0, Ori)
	{
		int newX = x + deltaX[dir];
		int newY = y + deltay[dir];

		if (newX < 0 || newX >= n || newY < 0 || newY >= m)
			continue;

		if (!hasDoor[x][y][o][dir] || !hasDoor[x][y][o][counterDir[dir]])
			continue;

		dist[newX][newY][o] = min(dist[newX][newY][o], dist[x][y][o] + 1);
		toVisit.push(pair<PII, int>(PII(newX, newY), o));
	}
}

void goOO(int x, int y, int o) {
	LP(i, 0, Ori)
	{
		if (i == o)
			continue;

		dist[x][y][i] = min(dist[x][y][i], dist[x][y][o] + 1);
		toVisit.push(pair<PII, int>(PII(x, y), i));
	}
}

int main() {
	freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &m);

	LP(i, 0, n)
		scanf("%s", maze[i]);

	scanf("%d %d", &xt, &yt);
	scanf("%d %d", &xm, &ym);
	xt--;
	yt--;
	xm--;
	ym--;

	LP(i, 0, n)
	{
		LP(j, 0, m)
		{
			LP(k, 0, Ori)
			{
				dist[i][j][k] = INF;
				visited[i][j][k] = false;
				memset(hasDoor[i][j][k], false, sizeof(hasDoor[i][j][k]));
			}
		}
	}

	calcDoors();

	dist[xt][yt][0] = 0;

	toVisit.push(pair<PII, int>(PII(xt, yt), 0));

	while (!toVisit.empty()) {

		int x = toVisit.front().first.first;
		int y = toVisit.front().first.second;
		int o = toVisit.front().second;

		if (visited[x][y][o])
			continue;
		else
			visited[x][y][o] = true;

		goOO(x, y, o);
		goNeighbor(x, y, o);
	}

	int res = INF;

	LP(i, 0, Ori)
		res = min(res, dist[xm][ym][i]);

	printf("%d\n", res == INF? -1: res);

	return 0;
}
