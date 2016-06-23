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

only merge small into large, more importantly, the parent will reuse the bigger brother, to avoid duplicate saves and satifies n^2 requirement

generate map<int, int> colorCount
LL currentAnswer
LL currentColorCount
at each merge
	if =
		currentAnswer += color
	else if >
		currentAnswer = newCount
		currentColorCount = newVal

phsical id


 */

int const MaxSize = 100010;
int nums[MaxSize];

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;
	scanf("%d", &n);

	LL sum = 0;
	LP(i, 0, n){
		scanf("%d" , &nums[i]);
		sum += (LL)nums[i];
	}

	sort(nums, nums+n);

	LL target = sum / (LL) n;

	int numTarget = n - (sum % n);

	LL ans = 0;

	LP(i, 0, numTarget)
			ans += abs(target - (LL)nums[i]);

	LP(i, numTarget, n)
			ans += abs(target + (LL)1 - (LL)nums[i]);

	cout << ans/(LL)2 << endl;


	return 0;
}

