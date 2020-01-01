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

LL const MOD = 1e9+7;
LL const MaxSize = 3e5 + 5;
//LL const MOD = 998244353;

/*

#https://atcoder.jp/contests/abc147/tasks/abc147_d
#Xor Sum 4
"""
iterate over bits
1. calculate how many bits we have on that position
2. for each 1, we need to add num 0s * num 1s * 2s
3. sum them up

1. python version gets TLE due to the IO
2. in c++ version, all needs to be LL
 */


LL N, a[MaxSize];

int main() {
        ios_base::sync_with_stdio(false);
        //freopen("/Users/georgeli/A_1.in", "r", stdin);

        cin >> N;

        LP(i, 0, N){
        	cin >> a[i];
        }

        LL ans = 0;
        int maxS = 61;
        LL base = 1;
        LP(shift, 0, maxS){ //instead of spending time calculating tight boudary, relax it a bit
        	//LL base = 1 << shift;
            base %= MOD;//!!!! this overflow is what got me, also, shift does not work well in 32 bit+ cases
            LL n1 = 0;
            LP(i, 0, N){
                if ((a[i] >> shift) & 1) //this is what got me: I didn't use & 1, shift itself is an assignment which returns no value
                    n1 += 1;
            }


            //cout << "n1: " << n1 << endl;
            LL part = n1 * (N - n1);
            //cout << shift << " " << part << " " << ans << endl;
            part %= MOD;
            part *= base;
            part %= MOD;
            ans += part;
            ans %= MOD;
            base *= 2L;
        }

        cout << ans;
        return 0;
}

