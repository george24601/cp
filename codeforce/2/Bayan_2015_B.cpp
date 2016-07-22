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
 */

int n, m;
string row, col;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n>> m;
	cin >> row >> col;

	bool cw = '>' == row[0] && 'v' == col[m - 1] && '<' == row[n-1] && '^' == col[0];
	bool ccw = '<' == row[0] && 'v' == col[0] && '>' == row[n-1] && '^' == col[m-1];

	if(cw || ccw)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

