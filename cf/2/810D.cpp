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
#define Ep 1e-13

#define INF 1e16
int n, k;

int bs(int l, int r) {
	if (l == r)
		return l;

	if (l + 1 == r) {
		cout << 1 << " " << l << " " << r << endl;
		fflush(stdout);
		string ans;
		cin >> ans;

		if (ans == "TAK")
			return l;
		else
			return r;
	}

	int mid = (l + r) / 2;

	cout << 1 << " " << mid << " " << mid + 1 << endl;
	fflush(stdout);

	string ans;
	cin >> ans;

	if (ans == "TAK")
		return bs(l, mid);
	else {
		return bs(mid + 1, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> k;

	int first = bs(1, n);

	//cout << "first:" << first << endl;

	int second;
	if (first == 1) {
		second = bs(2, n);
	} else if (first == n) {
		second = bs(1, n - 1);
	} else {
		second = bs(1, first - 1);

		cout << 1 << " " << second << " " << second + 1 << endl;
		fflush(stdout);
		string s;
		cin >> s;
		if (s == "TAK") {

		} else {
			second = bs(first + 1, n);
		}

	}
	cout << 2 << " " << first << " " << second << endl;
	fflush(stdout);

	return 0;
}
