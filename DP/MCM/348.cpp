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

const int MaxSize = 10;

L dist[MaxSize][MaxSize];
int prev[MaxSize][MaxSize];
bool init[MaxSize][MaxSize];

int rows[MaxSize];
int cols[MaxSize];
int n;

void Process() {
	LP(diff, 1, n)
	{
		for (int i = 0; i + diff < n; i++) {
			int j = i + diff;

			LPE(k, i+1, j)
			{
				L total = dist[i][k - 1] + dist[k][j]
						+ rows[i] * rows[k] * cols[j];

				if (!init[i][j] || dist[i][j] > total) {
					prev[i][j] = k;
					dist[i][j] = total;

					init[i][j] = true;
				}
			}
		}

	}
}

void Print_r(int i, int j) {
	if (i == j) {
		printf("A%d", i + 1);
	} else {
		printf("(");

		Print_r(i, prev[i][j] - 1);

		printf(" x ");
		Print_r(prev[i][j], j);
		printf(")");

	}
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;
		else
			caseNum++;

		LP(i, 0, n)
		{
			scanf("%d", &rows[i]);
			scanf("%d", &cols[i]);

			memset(prev[i], 0, sizeof(prev[i]));
			memset(dist[i], 0, sizeof(dist[i]));
			memset(init[i], false, sizeof(init[i]));
		}

		printf("Case %d: ", caseNum);
		Process();
		Print_r(0, n - 1);
		printf("\n");
	}

	return 0;
}
