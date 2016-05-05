#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
#define Ep 1e-9
#define MOD 1000000007

/*
One attack:
try all possible assignments
find min one


*/

class 	MutaliskEasy{
	int ans[61][61][61];

	int dp(int i, int j, int k){
		if (i < 0)
			i = 0;

		if(j < 0)
			j = 0;

		if(k < 0)
			k = 0;

		if(ans[i][j][k] >= 0)
			return ans[i][j][k];

		int best = INF;
		best = min(best, dp(i -9, j - 3, k - 1));
		best = min(best, dp(i -9, j - 1, k - 3));

		best = min(best, dp(i -3, j - 1, k - 9));
		best = min(best, dp(i -3, j - 9, k - 1));

		best = min(best, dp(i -1, j - 3, k - 9));
		best = min(best, dp(i -1, j - 9, k - 3));

		return ans[i][j][k] = (best + 1);
	}

public:
	int minimalAttacks(vector<int> x){

		LP(i,0, 61)
			LP(j,0, 61)
				memset(ans[i][j], -1, sizeof(ans[i][j]));

		int n = x.size();

		ans[0][0][0] = 0;

		if(1 == n)
			return dp(x[0], 0, 0);
		else if(2 == n)
			return dp(x[0], x[1], 0);
		else
			return dp(x[0], x[1], x[2]);
	}
};
/*
int main() {
	MutaliskEasy test;

	return 0;
}
*/
