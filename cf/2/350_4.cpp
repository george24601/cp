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

/*
 consider only 1:
 all to that ingredient

 consider 2:
 use all existing first
 add to the missing one to use them all
 add to the other missing one to , and one with purely magic power
 use the remaining
 we know # of cookies < 10^9

 suppose we have n cookies, we can calc precisely how many magic powers we can use => so just bsearch!

 */

int n, k;
int const MaxSize = 100000;

LL a [MaxSize];
LL b [MaxSize];

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-small-attempt1.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.out", "w", stdout);

	scanf("%d %d", &n, &k);

	LP(i, 0, n)
		scanf("%d", &a[i]);

	LP(i, 0, n)
		scanf("%d", &b[i]);

	LL low = 0;
	LL high = INF;

	while(low < high){
		LL mid = (low + high) / 2;

		if(mid == low)
			mid++;

		LL totalUse = 0;

		LP(i, 0, n){

			LL use = a[i] * mid - b[i];
			totalUse += use > 0? use : 0;

			if(totalUse > k)
				break;
		}

		if(totalUse > k)
			high = mid - 1;
		else
			low = mid;
	}

	cout << low << endl;

	return 0;
}
