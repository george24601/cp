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
 maxUp(i)
 if(isLight(i))
 get next to left

 if(next to left)  > 0
 return 1 + maxUp(nextoLeft)
 else return 1

 else
 return maxUp(i - 1)

 */

int const MaxSize = 1000001;

bool isLight[MaxSize];
int ans[MaxSize];
int n;
map<int, int> lToP;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	memset(isLight, false, sizeof(isLight));
	cin >> n;

	LP(i, 0, n)
	{
		int a, b;
		cin >> a >> b;
		lToP[a] = b;
		isLight[a] = true;
	}

	int maxUp = 0;

	LP(i, 0, MaxSize)
	{
		if (isLight[i]) {
			int nextToLeft = i - lToP[i] - 1;

			ans[i] = 1;
			if (nextToLeft >= 0)
				ans[i] += ans[nextToLeft];

		} else {
			ans[i] = i == 0 ? 0 : ans[i - 1];
		}

		//cout << ans[i] << endl;
		maxUp = max(maxUp, ans[i]);
	}

	cout << n - maxUp << endl;

	return 0;
}
