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

const int MaxN = 26;
const int MaxM = 31;

int n, m;

int total[MaxN][MaxM];

int zero[MaxN], one[MaxN];

bool target[MaxN];

int DFS(int node, int moves) {
	if (total[node][moves] >= 0)
		return total[node][moves];

	if (moves == m)
		return target[node] ? 1 : 0;

	total[node][moves] = DFS(zero[node], moves + 1) + DFS(one[node], moves + 1);

	return total[node][moves];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d", &n) == 1) {
		char c;
		scanf("%c", &c);//nl

		LP(i, 0, n)
		{
			char node, z, o, symbol;
			scanf("%c %c %c %c", &node, &z, &o, &symbol);

			scanf("%c", &c);//nl

			int nodeID = node - 'A';
			target[nodeID] = (symbol == 'x');

			zero[nodeID] = z - 'A';
			one[nodeID] = o - 'A';
		}

		scanf("%d", &m);

		LP(i, 0, n)
		{
			LPE(j, 0, m)
				total[i][j] = -1;
		}

		printf("%d\n", DFS(0, 0));
	}

	return 0;
}
