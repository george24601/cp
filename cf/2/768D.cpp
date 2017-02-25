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

int const MaxSize = 1e4 + 1;
int k, q;
double pr[MaxSize][1001];

void precompute() {
	pr[0][0] = 1;

	LP(day, 0, 10000)
	{
		LPE(got, 0, k)
		{
			double prNoNew = (double) got / (double) k;

			pr[day + 1][got] += prNoNew * pr[day][got];

			pr[day + 1][got + 1] += (1 - prNoNew) * pr[day][got];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	freopen("/Users/george/A_1.in", "r", stdin);
	cin >> k >> q;

	precompute();
	LP(i, 0, q)
	{
		int p;
		cin >> p;

		double targetP = ((double) p - Ep) / 2000.0;

		LPE(day, 0, 10000)
		{
			if (pr[day][k] >= targetP) {
				cout << day << endl;
				break;
			}
		}
	}

	return 0;
}
