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
#define INF 1000000000
#define Ep 1e-8

/*
 consider only 2 persons
 after k days, same if orginal diff <= 2k, or Max - Min - 2K

 Consider the final min value fMin

 so consider largest m that gets money
 (curSum of 1...m + k) /m = new minValue
 and make sure fMin < V(m+1)

 similarly, consider largest n that gives money
 if m crosses n, then we can reach balance(?)

 otherwise, we can do similar thing to calc new max value

 so do accumulative sum
 Bsearch for final minValue
 can calculate # of add to that
 if total > k, too high

 Bsearch for final maxValue
 can calculate # to remote to that
 if total > k, too high
 */

int const MaxSize = 500000;

LL nums[MaxSize];
int n, k;

LL bsMin() {
	LL low = nums[0];
	LL high = nums[n - 1];

	while (low < high) {
		LL mid = (low + high) / 2;

		LL totalDiff = 0;

		LP(i, 0, n)
		{
			if (nums[i] >= mid)
				break;

			if (totalDiff > k)
				break;

			totalDiff += (mid - nums[i]);
		}

		if (totalDiff > k) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}

	return low;
}

LL bsMax() {
	LL low = nums[0];
	LL high = nums[n - 1];

	while (low < high) {
		LL mid = (low + high) / 2;

		LL totalDiff = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] <= mid)
				break;

			if (totalDiff > k)
				break;

			totalDiff += (nums[i] - mid);
		}

		if (totalDiff > k)
			low = mid +1;
		else
			high = mid;
	}

	return low;
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-large.in", "r", stdin);
	//freopen("/Users/georgeli/B_large.out", "w", stdout);

	scanf("%d %d", &n, &k);

	LP(i, 0, n)
		scanf("%d", &nums[i]);

	sort(nums, nums + n);

	LL highMin = bsMin();
	LL lowMax = bsMax();

//	printf("%d %d", highMin, lowMax);

	printf("%d\n", highMin >= lowMax ? 0 : -highMin + lowMax);

	return 0;
}
