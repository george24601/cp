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
#define Ep 1e-7

#define INF 2000000000
//#define INF 1e18

/*

 */

int const MaxSize = 1000010;

int fenw[MaxSize];
int n;

void addDelta(int x, int v) {
	while (x <= n) {
		fenw[x] += v;
		x = (x | (x - 1)) + 1;
	}
}

int preSum(int x) {
	int v = 0;
	while (x > 0) {
		v += fenw[x];
		x &= x - 1;
	}
	return v;
}

int k;

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> k;

	if (k * 2 > n)
		k = n - k;

	//new polygons  = num of diagonals crossed + 1

	int cur = 1;
	LL ans = 1;

	LP(i, 0, n)
	{
		int from = cur - k + 1;
		int to = cur + k - 1;

		if(from < 1){
			ans += preSum(n) - preSum(from + n  - 1) + preSum(to);

		}else if(to > n){
			ans += preSum(to - n) + preSum(n) - preSum(from - 1);

		}else{
			ans += preSum(to) - preSum(from - 1);
		}


		addDelta(cur, 1);
		cur += k;
		if (cur > n)
			cur -= n;

		ans++;
		cout << ans <<" ";
	}

	return 0;
}
