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
int const MaxSize = 1e5 + 1;

LL k, prefixSum[MaxSize];

map<LL, int> nPSV;

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> k;

	LL ans = 0;

	nPSV[0] = 1;

	vector<LL> powers;

	powers.push_back(1);

	if (1 == k) {

	} else if (-1 == k) {
		powers.push_back(-1);
	} else {
		LL power = k;

		while (abs(power) <= 1e14) {

			powers.push_back(power);

			power *= k;
		}
	}

	LPE(i, 1, n)
	{
		LL ai;
		cin >> ai;

		prefixSum[i] = prefixSum[i - 1] + ai;

		LP(pi, 0, powers.size()){
			LL power = powers[pi];

			//cout << power << endl;

			LL target = prefixSum[i] - power;

			if (nPSV.count(target)) {
				//cout <<  i << " " <<  target << " " << nPSV[target] << endl;
				ans += nPSV[target];
			}

		}

		nPSV[prefixSum[i]]++;
	}

	cout << ans << endl;

	return 0;
}
