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

 */

int k;
int const MaxSize = 1001;
int const MOD = 1000000007;

int nums[MaxSize];

LL chooseN[MaxSize + 1][MaxSize + 1];

void initChoose() {
	LPE(i, 0, MaxSize)
	{
		memset(chooseN[i], 0, sizeof(chooseN[i]));
		chooseN[i][0] = 1;
		chooseN[i][i] = 1;
	}
}

LL choose(int top, int bottom) {

	if (top < 0 || bottom < 0 || bottom > top)
		return 0;

	assert(top >= bottom);

	if (chooseN[top][bottom])
		return chooseN[top][bottom];

	return chooseN[top][bottom] = (choose(top - 1, bottom - 1)
			+ choose(top - 1, bottom)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d", &k);

	memset(nums, 0, sizeof(nums));

	LP(i, 0, k)
		scanf("%d", &nums[i]);

	LL ways = 1;

	LL totalN = nums[0];

	initChoose();

	LP(i, 1, k)
	{
		LL curN = nums[i];

		totalN += curN;

		if (curN == 1) {

		} else {
			ways = ways * choose(totalN - 1, curN - 1);
			ways %= MOD;
			//cout << totalN + 1 << " " << curN - 1 << " " << ways << endl;
		}

	}

	cout << ways << endl;

	return 0;
}

