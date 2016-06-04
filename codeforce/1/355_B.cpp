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
 consider the base 2 case: just y and n, represent 1 and 0

 suppose we know a target

if that digit is 0

can be 1-0 or 0 - 1 or 0 - 0

if that digit is 1
can be 1-1

= 3^(# of 0 digits) - identical pairs, in binary case, only 1: itself

#ways(n) = #ways(n-1)* pair count
---
consider base 64
problem: need big int, can't brute force multiple

for target, assume they are all distinct, i.e., max 64 length




 */
int const MaxSize = 100010;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	LL n, h, k;
	scanf("%d %d %d", &n, &h, &k);
	//cin >> n >>h >> k;

	int a[MaxSize];

	//n = 100000;
	LP(i, 0, n){
	//	a[i] = 1000000000;
		scanf("%d", &a[i]);
		//cin >> a[i];
	}

	LL time = 0;
	LL capacity = h;

	LP(i, 0, n)
	{
		if (capacity >= a[i]) {
		} else {
			LL delta = a[i] -  capacity;
			LL pt = delta / k;

			if (delta % k)
				pt += 1;

			time += pt;

			//cout << i << " " << capacity << " "<< pt << endl;

			capacity = min(h, capacity + pt * k);
		}

		capacity -= a[i];
	}

	LL lastV = h - capacity;

	time += lastV/k;

	if(lastV % k)
		time++;

	cout << time << endl;

	return 0;
}
