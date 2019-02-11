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
 if n is even, then there are in total even # of steps, M will win for sure -> just replicate what T does
 if n is odd, T should make sure, the first bite can finish the log, otherwise, M will finish it, and T will end up in the lose case

 this means T needs to find minimal d >= k, s.t. d % m = 0, note that checking all divisors can be done in sqrt(m) => we have pairs here!
 note that minimal means that we can not further divide by by divisors > k, otherwise, it is not minimal

 corner case:
 1 2 1
 1 1 1
 */

int const MaxSize = 1e5 + 5;

//NOTE WORKS ONLY WHEN MOD IS PRIME
LL MOD = 1e9 + 7;
int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> m >> k;
	if (n % 2 == 0 || m == 1) {
		cout << "Marsel" << endl;
		return 0;
	}

	bool isPrime = true;
	LPE(d, 2, sqrt(m))
	{
		if (m % d == 0) {
			isPrime = false;
			if (d >= k || m / d >= k) {
				cout << "Timur" << endl;
				return 0;

			}
		}
	}

	if (isPrime && k == 1) {
		cout << "Timur";
		return 0;
	}

	cout << "Marsel" << endl;
	return 0;

	return 0;
}
