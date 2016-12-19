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
#define Ep 1e-7

#define INF 2000000000

/*
 find the first digit >= 5
 try rounding
 keep track of . index

 while(canIndex > .Index && t > 0){

 if(digit[canIndex] >0 5) {
 round
 if(canIndex == dI + 1)
 {
 lastI = dI - 1;

 }
 t--;
 }

 canIndex--;
 }

 */

int n, t;
string g;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> t >> g;

	int di = 0;

	while (g[di] != '.')
		di++;

	int ci = di + 1;

	for (; ci < n && g[ci] < '5'; ci++)
		;

	bool carry = false;
	int li = n - 1;

	while (ci >= 0 && ci < n) {

		if (ci == di) {

		} else {
			if (carry) {
				if (g[ci] == '9') {
					g[ci] = '0';
					carry = true;
				} else {
					g[ci] = g[ci] + 1;
					carry = false;
				}
			}

			if (ci > di && g[ci] >= '5' && t > 0) {
				li = ci - 1;
				g[ci] = '0';
				carry = true;
				t--;
			//	cout << ci << " " << g[ci] << " " << t << endl;
			}
		}

		ci--;
	}

	int fi = 0;

	for (; fi < di && fi == '0'; fi++)
		;

	if (carry)
		cout << 1;

	if (fi == di)
		cout << 0;

	LP(i, fi, di)
		cout << g[i];

	for (; li > di && g[li] == '0'; li--)
		;

	for (int i = di; i <= li && li > di; i++)
		cout << g[i];

	cout << endl;

	return 0;
}
