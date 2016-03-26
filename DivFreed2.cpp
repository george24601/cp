#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
#define Ep 1e-9
#define MOD 1000000007

//DP, complete search

/*
 given n, k
 n to n+1,
 k1 from 1 to n, only if k1 >= k or k % k1 < 0
 ways(index + 1, num) = ways(index, n1) n1 < num  or n1 % num != 0
 check all on ways(N, n), add them all
 */
class DivFreed2{

	int N, K;
	int cache [11][100000];

	int DP(int n, int tail){
		if (cache[n][tail] >= 0)
			return cache[n][tail];

		if(1 == n)
			return 1;

		int result = 0;

		LPE(prev, 1, K){
			if (prev <= tail || prev % tail != 0){
				result += DP(n-1, prev);
				result %= MOD;
			}
		}

		return cache[n][tail] = result;
	}


	public:
		int count(int n, int k){
			N = n;
			K = k;

			LP(i, 0, n)
				memset(cache[i], -1, sizeof(cache[i]));

			int total = 0;

			LPE(i, 1, k){
				total += DP(n, i);
				total %= MOD;
			}

			return total;
		}
};

int main() {
	return 0;
}
