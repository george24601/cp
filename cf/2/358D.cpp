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
#define Ep 1e-13

#define INF 1e9
int const MaxSize = 3000 + 10;
int n, a[MaxSize], b[MaxSize], c[MaxSize], mC[MaxSize][2];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> a[i];

	LP(i, 0, n)
		cin >> b[i];

	LP(i, 0, n)
		cin >> c[i];

	mC[0][0] = a[0]; //right not filled
	mC[0][1] = b[0]; //right filled

	LP(i, 1, n)
	{
		mC[i][1] = max(mC[i - 1][0] + c[i], mC[i - 1][1] + b[i]);
		mC[i][0] = max(mC[i - 1][0] + b[i], mC[i - 1][1] + a[i]);
	}

	cout << mC[n - 1][0] << endl;

	return 0;
}
