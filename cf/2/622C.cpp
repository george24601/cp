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

#define INF 2000000100

/*
 for each i, find the first index to the left that is not equal to it

 for a query, anser is either, a[r] if a[r] != x
 a[p[r]] if a[p[r]] != x && p[r] >= l
 or -1


 */

int const MaxSize = 200010;

int n, m;
int a[MaxSize], pdi[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n , &m);

	LPE(i, 1, n)
		scanf("%d", &a[i]);

	pdi[1] = -1;

	LPE(i, 2, n)
	{
		if (a[i] == a[i - 1])
			pdi[i] = pdi[i - 1];
		else
			pdi[i] = i - 1;
	}

	LP(i, 0, m)
	{
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);

		if (a[r] != x) {
			cout << r << endl;
		} else {
			int prevDI = pdi[r];

			if (prevDI >= l)
				cout << prevDI << endl;
			else
				cout << -1 << endl;
		}
	}

	return 0;
}
