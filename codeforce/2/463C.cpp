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

int const MaxSize = 2010;
int n;
int a[MaxSize][MaxSize];

LL leftS[5000];
LL rightS[5000];

void calcDia() {

	LP(i, 0, n)
	{
		LP(j, 0, n)
		{
			leftS[i - j + n - 1] += (LL) a[i][j];
			rightS[i + j] += (LL) a[i][j];
		}
	}
}

LL getLeft(int i, int j) {
	return leftS[i - j + n - 1];
}

LL getRight(int i, int j) {
	return rightS[i + j];
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	LP(i, 0, n)
	{
		LP(j, 0, n)
			scanf("%d", &a[i][j]);
	}

	calcDia();

	LL curBest0 = 0;
	int i0, j0;

	LL curBest1 = 0;
	int i1, j1;

	LP(i, 0, n)
	{
		LP(j, 0,n)
		{
			LL curSum = getLeft(i, j) + getRight(i, j) - (LL) a[i][j];

			int classN = abs(i - j) % 2;

			if (!classN && curBest0 <= curSum) {
				curBest0 = max(curBest0, curSum);
				i0 = i;
				j0 = j;
			}

			if (classN && curBest1 <= curSum) {
				curBest1 = max(curBest1, curSum);
				i1 = i;
				j1 = j;
			}

		}
	}

	cout << curBest1 + curBest0 << endl;
	cout << i0 + 1 << " " << j0 + 1 << " " << i1 + 1 << " " << j1 + 1 << endl;

	return 0;
}

