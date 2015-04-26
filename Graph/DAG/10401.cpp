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

const int MaxSize = 20;

L dist[MaxSize][MaxSize];
char layout[MaxSize];
int n;

int GetRow(int i) {
	char pos = layout[i];
	if (pos >= '1' && pos <= '9')
		return pos - '1';

	if (pos >= 'A' && pos <= 'F')
		return pos - 'A' + 9;

	return -1;
}

bool Valid(int from, int to) {
	return to > from + 1 || to < from - 1;
}

void Relax(int col) {

	if (GetRow(col) == -1) {
		LP(from, 0, n)
		{
			LP(to, 0, n)
			{
				if (Valid(from, to))
					dist[to][col] += dist[from][col + 1];
			}
		}
	} else {
		int to = GetRow(col);
		LP(from, 0, n)
		{
			if (Valid(from, to))
				dist[to][col] += dist[from][col + 1];
		}
	}

}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (gets(layout)) {
		n = strlen(layout);
		if (n == 0)
			continue;

		LP(i, 0, n)
			memset(dist[i], 0, sizeof(dist[i]));

		if (layout[n - 1] == '?') {
			LP(i, 0, n)
				dist[i][n - 1] = 1;
		} else {
			dist[GetRow(n - 1)][n - 1] = 1;
		}

		for (int i = n - 2; i >= 0; i--)
			Relax(i);

		L total = 0;
		LP(i, 0, n)
			total += dist[i][0];

		printf("%llu\n", total);
	}

	return 0;
}
