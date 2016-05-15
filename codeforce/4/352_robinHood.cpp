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
 apply all gives

 apply all takes

 */

int const MaxSize = 500000;

LL nums[MaxSize];
int n, k;

void applyGives() {
	LL low = 0;
	LL high = INF;

	while (low < high) {
		LL mid = (low + high) / 2;

		if (mid == low)
			mid++;

		LL totalDiff = 0;

		LP(i, 0, n)
		{
			if (mid > nums[i])
				totalDiff += mid - nums[i];
		}

		if (totalDiff > k) {
			high = mid - 1;
		} else {
			low = mid;
		}
	}

	int remaining = k;

	LP(i, 0, n)
	{
		if (nums[i] < low) {
			LL diff = low - nums[i];
			nums[i] += diff;
			remaining -= diff;
		}
	}

	LP(i, 0, n)
	{
		if (remaining && nums[i] == low) {
			nums[i]++;
			remaining--;
		}
	}

	//cout << low << endl;
}

void applyTakes() {
	LL low = 0;
	LL high = INF;

	while (low < high) {
		LL mid = (low + high) / 2;

		LL totalDiff = 0;

		LP(i, 0, n)
		{
			if (mid < nums[i])
				totalDiff += nums[i] - mid;
		}

		if (totalDiff > k) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}

//	cout << high << endl;
	int remaining = k;

	LP(i, 0, n)
	{
		if (nums[i] > high) {
			LL diff = nums[i] - high;
			nums[i] -= diff;
			remaining -= diff;
		}
	}

	//Note that unlike sample answer, we don't need to redistribute remaning here, since the max will remain same
	LP(i, 0, n)
	{
		if (remaining && nums[i] == high) {
			nums[i]--;
			remaining--;
		}
	}
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-large.in", "r", stdin);
	//freopen("/Users/georgeli/B_large.out", "w", stdout);

	scanf("%d %d", &n, &k);

	LP(i, 0, n)
		scanf("%d", &nums[i]);

	applyGives();
	applyTakes();

	cout << *max_element(nums, nums + n) - *min_element(nums, nums + n) << endl;

	return 0;
}
