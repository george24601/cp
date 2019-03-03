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

int const MaxSize = 2000 + 5;
int const MOD = 1e9 + 7;

/*
 corner case: consider when current count is 0 or n!
 */
double pr[MaxSize][MaxSize];
int n, t;
double p;


int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> p >> t;
	//cout << n << " " << p << " " << t << endl;

	pr[0][0] = 1.0;
	LPE(curT, 1, t){
		pr[0][curT] = pr[0][curT - 1] * (1 - p);
		LP(curN, 1, n){
			pr[curN][curT] = pr[curN][curT - 1] * (1.0 - p) + pr[curN - 1][curT - 1] * p;
		//	cout << curN << " " << curT << setprecision(12) << " " <<  pr[curN][curT] << endl;
		}

		pr[n][curT] = pr[n][curT - 1] + pr[n - 1][curT - 1] * p;
	}

	double ans = 0;

	LPE(curN, 1, n)
		ans += pr[curN][t] * curN;

	cout << setprecision(12) << ans << endl;

	return 0;
}
