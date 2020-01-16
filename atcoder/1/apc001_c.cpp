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
#define LP(i, a, b) for (LL i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (LL i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

LL const MOD = 1e9 + 7;
LL const MaxSize = 1e5 + 5;
//LL const MOD = 998244353;

/*

 https://atcoder.jp/contests/abc110/tasks/abc110_c
 #C - String Transformation
 */

//NOTE WORKS ONLY WHEN MOD IS PRIME
//test case, either = 1 or all = 1
int N;
int ss[MaxSize];
int found = -1;

int pg(int i) {
	if (ss[i] >= 0)
		return ss[i];

	cout << i << endl;
	cout.flush();
	string s;
	cin >> s;
	int state = 2;

	if (s == "Male")
		state = 0;
	else if(s == "Female")
		state = 1;

	ss[i] = state;
	if (state == 2)
		found = i;

	return state;
}

void find(int si, int ei) {
	if (si > ei)
		return;

	int mid = (si + ei) / 2;

	pg(mid);
	if (found >= 0) {
		cout << found << endl;
		cout.flush();
		return;
	}

	if (mid == si) {
		find(mid + 1, ei);
		return;
	}

	int d = mid - si;

	if (d % 2) {
		if (ss[mid] ^ ss[si])
			find(mid, ei);
		else
			find(si, mid - 1);
	} else {
		if (ss[mid] ^ ss[si])
			find(si, mid - 1);
		else
			find(mid, ei);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> N;
	memset(ss, -1, sizeof(ss));

	pg(0);
	if (found >= 0){
		cout << found << endl;
		cout.flush();
	}
	else
		find(0, N - 1);

	return 0;
}
