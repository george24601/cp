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

#define INF 1e9
/*

 */

int n;
string s, m;
int ds[10], dm[10];

void minGet() {
	int ans = 0;
	int balance = 0;

	for (int d = 9; d >= 0; d--) {

		int fromM = dm[d] + balance;

		if (fromM < ds[d]) {
			ans += ds[d] - fromM;
			balance = 0;
		} else {
			balance = fromM - ds[d];
		}
	}

	cout << ans << endl;
}

void maxGive() {
	int ans = 0;
	int balance = 0;

	for (int d = 9; d > 0; d--) {

		int fromM = dm[d] + balance;

		if (fromM < ds[d - 1]) {
			ans += fromM;
			balance = 0;
		} else {
			ans += ds[d - 1];
			balance = fromM - ds[d - 1];
		}
	}

	cout << ans << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> s >> m;

	LP(i, 0, n)
	{
		ds[s[i] - '0']++;
		dm[m[i] - '0']++;
	}

	minGet();
	maxGive();

	return 0;
}
