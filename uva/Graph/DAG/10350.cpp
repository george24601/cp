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
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 130;
const int MaxM = 20;

int m, n;

int edge[MaxN][MaxM][MaxM];
int dist[MaxN][MaxM];

void Relax(int floor) {

	LP(from, 0, m)
	{
		LP(to, 0, m)
		{
			int newDist = dist[floor][from] + edge[floor][from][to] + 2;
			dist[floor+1][to] = min(dist[floor+1][to], newDist);
		}
	}

}

int main() {
	freopen("C:\\Test\\Test.txt", "r", stdin);

	char name[100];
	while (scanf("%s", name) == 1) {

		scanf("%d %d", &n, &m);

		LP(k, 0, n-1)
		{
			LP(i,0, m)
			{
				LP(j, 0, m)
					scanf("%d", &edge[k][i][j]);
			}
		}
	}

	LP(i, 0, m)
	{
		dist[0][i] = 0;

		LP(k, 1, n)
			dist[k][i] = INF;
	}

	LP(i, 0, n-1)
		Relax(i);

	int minDist = INF;
	LP(i, 0, m)
		minDist = min(minDist, dist[n-1][i]);

	printf("%s\n", name);
	printf("%d\n", minDist);
	return 0;
}
