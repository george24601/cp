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

int n, k;
int const MaxSize = 100000;

int nums[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d %d", &n, &k);

	memset(nums, 0, sizeof(nums));

	LP(i, 0, n)
		scanf("%d", &nums[i]);

	sort(nums, nums+ n);

	set<int> toReturn;

	LP(i, 0, n){
		int curN = nums[i];


		if(curN % k == 0 && toReturn.count(curN/k))
			continue;

		toReturn.insert(curN);
	}

	cout << toReturn.size() << endl;

	return 0;
}

