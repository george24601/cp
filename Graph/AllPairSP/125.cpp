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

const int INF = 2147483647;

const int MaxSize = 60;

int n;
int dist[MaxSize][MaxSize];

void Process() {
	LP(k, 0 , n)
	{
		LP(i, 0, n)
		{
			LP(j, 0, n)
			{
				int old = dist[i][j];
				int firstNew = dist[i][k];
				int secondNew = dist[k][j];

				if (old < 0 || (firstNew < 0 && secondNew != 0)
						|| (firstNew != 0 && secondNew < 0)) {
					dist[i][j] = -1;

					if(dist[j][i] != 0)
						dist[j][i] = -1;

				} else if (i == j) {
					if(dist[i][j] < 0)
					{

					}else if (firstNew * secondNew > 0)
						dist[i][j] = -1;
				} else {
					dist[i][j] += firstNew * secondNew;

					if(dist[i][j] != 0 && dist[j][i] != 0)
					{
						dist[i][j] = -1;
						dist[j][i] = -1;
					}
				}

			}
		}
	}
}

void Print() {
	LP(i, 0, n)
	{
		printf("%d", dist[i][0]);
		LP(j, 1, n)
			printf(" %d", dist[i][j]);

		printf("\n");
	}
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	int m;
	while (scanf("%d", &m) == 1) {

		n = 0;

		printf("matrix for city %d\n", caseNum);
		caseNum++;

		LP(i, 0, MaxSize)
			memset(dist[i], 0, sizeof(dist[i]));

		LP(i, 0, m)
		{
			int from, to;
			scanf("%d %d", &from, &to);

			n = max(from + 1, n);
			n = max(to + 1, n);

			dist[from][to] = 1;
			//dist[toID][fromID] = 1;
		}

		Process();

		Print();
	}

	return 0;
}
