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
 f(g(f(g(x)))) = f(x) => f(f(x)) = f(x) => for all f(x) are stable points

 if they are all stable points

 m = number distinct f(x) values;

 g(nx)= index of f(x)

 h(mx) = value of f(nx) at that index mx


 */

int const MaxSize = 1e5 + 1;

int n, f[MaxSize], m, h[MaxSize], g1[MaxSize];

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n;

	LPE(i, 1, n)
		cin >> f[i];

	LPE(i, 1, n)
	{
		if (f[i] != f[f[i]]) {
			cout << -1;
			return 0;
		}
	}

	LPE(fnx, 1, n)
	{
		if (f[fnx] == fnx) {
			m++;
			h[m] = fnx;
			g1[fnx] = m;
		}
	}

	cout << m << endl;

	LPE(nx, 1, n)
		cout << g1[f[nx]] << " ";

	cout << endl;

	LPE(mx, 1, m)
		cout << h[mx] << " ";

	return 0;
}
