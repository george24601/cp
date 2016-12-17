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
 h <= d <= 2h

 new root =

 */

int const MaxSize = 101;

int const MOD = 1000000007;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n, d, h;
	cin >> n >> d >> h;

	if(n > 2 && d == 1){
		printf("%d\n", -1);
		return 0;
	}

	if (!(d <= 2 * h && d >= h && d <= n - 1)) {
		printf("%d\n", -1);
		return 0;
	}

	int curID = 2;
	//print depth
	LP(i, 0, h)
	{

		printf("%d %d\n", curID - 1, curID);
		curID++;
	}

	if (d != h) {
		//print diameter
		LP(i, 0, d - h)
		{
			printf("%d %d\n", i == 0 ? 1 : curID - 1, curID);
			curID++;
		}
	}

	LP(i, 0, n - d - 1)
	{
		printf("%d %d\n", d == h? 2 : 1, curID);
		curID++;
	}

	//print remaining
	return 0;
}
