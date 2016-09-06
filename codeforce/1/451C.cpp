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
#define Ep 1e-8

/*
 brute force on the seocnd order

 if first > second


 if second > third


 */

int const MaxSize = 1010;
int t;

LL n, k, d1, d2;

bool goodFirst(LL v) {
	return v >= 0 && v <= k;
}

bool goodSecond(LL v) {
	return v >= 0 && v <= n - k;
}

void p() {

	LPE(i, 0, 1)
	{
		LPE(j, 0, 1)
		{
			LL delta1 = i ? d1 : -d1;
			LL delta2 = j ? d2 : -d2;

			LL s3 = k - delta1 - delta2;
			//	cout << s3 << endl;

			if (s3 % 3)
				continue;

			LL second = s3 / 3;

			//	cout << second << endl;

			if (!(goodFirst(second) && goodFirst(second + delta1)
					&& goodFirst(second + delta2)))
				continue;

			LL remS3 = n - k + delta1 + delta2;

			if (remS3 % 3)
				continue;

			LL remS = remS3 / 3;
			LL remF = remS - delta1;
			LL remT = remS - delta2;

			if (goodSecond(remS) && goodSecond(remF) && goodSecond(remT)) {
				cout << "yes" << endl;
				return;
			}
		}
	}
	cout << "no" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> t;

	LP(i, 0, t)
	{
		cin >> n >> k >> d1 >> d2;
		p();
	}

	return 0;
}

