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
//typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e9
/*

 */
int const MaxSize = 1e6 + 1;
int n, k, f[MaxSize];
PII s[MaxSize];
int m;

bool good(int sizeS) {

	int si = m - sizeS, fi = 0;

	for (int day = 0; si < m || fi < n; day++) {

		for (int todayTry = 0; todayTry < k && (si < m || fi < n); todayTry++) {
			bool moveF = fi < n && (si >= m || s[si].first > f[fi]);
			//		cout << fi << " " << n << " " << si << " " << m - sizeS << endl;

			if (moveF) {

				if (f[fi] >= day)
					fi++;
				else {
					//				cout << "fi:" << fi << " day:" << day << endl;
					return false;
				}
			} else {
				if (s[si].first >= day) {
					si++;
				} else {
					//				cout << "size: " << sizeS << " si:" << si << " day:" << day
					//						<< endl;
					return false;
				}
			}
		}
	}

	//cout << "good!" << sizeS << endl;
	return true;
}

int bsearchMax() {
	/*
	 if (l > h)
	 return -1;
	 else if (l == h)
	 return good(l) ? l : -1;

	 int mid = (l + h) / 2;

	 if (good(mid)) {
	 if (good(mid + 1))
	 return bsearchMax(mid + 1, h);
	 else
	 return mid;
	 } else
	 return bsearchMax(l, mid - 1);
	 */

	int l = 0, r = m + 1;
	while (r - l > 1) {
		int bm = (l + r) / 2;
		if (good(bm)) {
			l = bm;
		} else {
			r = bm;
		}
	}

	return l;
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);

	LP(i, 0, n)
		scanf("%d", &f[i]);

	LP(i, 0, m)
	{
		scanf("%d", &s[i].first);
		s[i].second = i + 1;
	}

	sort(f, f + n);
	sort(s, s + m);

//	int ans = bsearchMax(0, m);
	if (good(0)) {
		int ans = bsearchMax();

		cout << ans << endl;

		LP(i, 0, ans)
		{
			if (i > 0)
				cout << " ";

			cout << s[m - ans + i].second;
		}
	} else {
		cout << -1;
	}

	//cout << " 11 good?" <<  good(11) << endl;
}
