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

/*
 if total # is odd, by coloring we know we need a teleportor for sure
 in other cases, we can experiement and construct a solution
 catch case: (1, 2), (1, >2), (>2, 1)

 */

int const MaxSize = 1000 + 5;
int n, m;

void tele() {
	cout << 1  << endl << n << " " << m <<" 1 1"<< endl;

	LPE(i, 1, n)
	{
		if (i % 2) {
			LPE(j, 1, m)
			{
				cout << i << " " << j << endl;
			}
		} else {
			for (int j = m; j >= 1; j--) {
				cout << i << " " << j << endl;
			}
		}
	}
	cout << "1 1";

}
void left() {
	cout << 0 << endl;
	cout << "1 1" << endl;
	LP(i, 1, n)
	{
		if (i % 2) {
			LPE(j, 2, m)
			{
				cout << i << " " << j << endl;
			}
		} else {
			for (int j = m; j >= 2; j--) {
				cout << i << " " << j << endl;
			}
		}
	}

	for (int j = m; j >= 1; j--) {
		cout << n << " " << j << endl;
	}

	for (int i = n - 1; i >= 1; i--)
		cout << i << " " << 1 << endl;
}
void down() {
	cout << 0 << endl;
	cout << "1 1" << endl;
	LP(j, 1, m)
	{
		if (j % 2) {
			LPE(i, 2, n)
			{
				cout << i << " " << j << endl;
			}
		} else {
			for (int i = n; i >= 2; i--) {
				cout << i << " " << j << endl;
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		cout << i << " " << m << endl;
	}

	for (int i = m - 1; i >= 1; i--)
		cout << 1 << " " << i << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> m;

	if(n == 1 && m == 2){
		left();
	}else if(n == 2 && m == 1){
		down();
	}else if (n % 2 && m % 2)
		tele();
	else if (n == 1 || m == 1)
		tele();
	else if (n % 2) {
		down();
	} else {
		left();
	}

	return 0;
}
