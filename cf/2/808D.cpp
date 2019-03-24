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
typedef long double LD;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

int const MaxSize = 100000 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*
 */
int n;
LL a[MaxSize];
map<LL, int> psCnt, numCnt;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n;

	LL sum = 0;
	psCnt[0]++;
	numCnt[0]++;

	LPE(i, 1, n)
	{
		cin >> a[i];
		sum += a[i];
		psCnt[sum]++;
		numCnt[a[i]]++;
		//cout << i << " " << sum << endl;
	}

	LL half = sum / (LL) 2;

	if (sum % (LL) 2) {
		cout << "NO";
		return 0;
	}

	LL ps = 0;
	LPE(i, 1, n)
	{
		//try taking out current
		LL d = half - ps;
		ps += a[i];
		//cout << i << " " << ps << endl;
		psCnt[ps]--;
		numCnt[a[i]]--;

		if (psCnt[half + a[i]] > 0 || numCnt[d] > 0) {
			cout << "YES"; // << " " << half << " " << i << " " << a[i] << " " << psCnt.count(half + a[i]);
			return 0;
		}

	}
	cout << "NO";

	return 0;
}
