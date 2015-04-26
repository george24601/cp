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

const int MaxN = 110;
const int MaxM = 510;

#define maxWin 20

int C, S, E, D;

int good[MaxN][MaxM];
SAL adj;

int DFS(int city, int given) {
	if (good[city][given] >= 0) {

	} else if (given == D) {
		good[city][given] = city == E ? 1 : 0;
	} else {

		good[city][given] = 0;

		LP(i, 0, adj[city].size())
		{
			int to = adj[city][i];

			if (DFS(to, given + 1) == 1) {
				good[city][given] = 1;
			}
		}
	}

	return good[city][given];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int l;
	while (scanf("%d %d", &C, &l)) {
		if (C == 0 && l == 0)
			break;

		adj = SAL(C + 1);
		LP(i, 0, l)
		{
			int A, B;
			scanf("%d %d", &A, &B);

			adj[A].push_back(B);
			adj[B].push_back(A);
		}

		scanf("%d %d %d", &S, &E, &D);

		LPE(i, 0 , C)
			LPE(j, 0, D)
				good[i][j] = -1;

		if (DFS(S, 0))
			printf("Yes, Teobaldo can travel.\n");
		else
			printf("No, Teobaldo can not travel.\n");
	}

	return 0;
}
