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
//typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e9
/*

 */

int const MaxSize = 1024;
int n, k, x, c[MaxSize];
int nextC[MaxSize];

/*
 consider min case:
 if after applying for the first time, it goes to odd spot => we are good, it will be that
 if after applying, it goes to the even spot

 */

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> k >> x;

	LP(i, 0, n)
	{
		int num;
		cin >> num;

		c[num]++;
	}

	LP(i, 0, k)
	{
		bool odd = true;

		LP(v, 0, MaxSize)
		{
			int numChanged = (c[v] + (odd ? 1 : 0)) / 2;

			nextC[v] += (c[v] - numChanged);
			nextC[v ^ x] += numChanged;

			if (c[v] % 2)
				odd = !odd;
		}

		LP(v, 0, MaxSize)
			c[v] = nextC[v];

		memset(nextC, 0, sizeof(nextC));
	}

	for (int v = MaxSize - 1; v >= 0; v--) {

		if (c[v] > 0) {
			cout << v << " ";
			break;
		}
	}

	LP(v, 0, MaxSize)
	{
		if (c[v] > 0) {
			cout << v << endl;
			break;
		}

	}

	return 0;
}
