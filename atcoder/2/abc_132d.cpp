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

LL const MOD = 1e9 + 7;
LL const MaxSize = 2000 + 5;
//LL const MOD = 998244353;

/*

https://atcoder.jp/contests/abc132/tasks/abc132_d
D - Blue and Red Balls

 */

//NOTE WORKS ONLY WHEN MOD IS PRIME
LL N, K;
//test case, either = 1 or all = 1

//NOTE WORKS ONLY WHEN MOD IS PRIME
LL f[MaxSize], invF[MaxSize], r[MaxSize];

void preCalc() {
        r[1] = 1;
        f[1] = 1;
        invF[1] = 1;
        LL m = MOD;

        for (LL i = 2; i < MaxSize; ++i) {
                r[i] = (m - (m / i) * r[m % i] % m) % m;

                f[i] = (i * f[i - 1]) % MOD;
                invF[i] = (r[i] * invF[i - 1]) % MOD;
        }
}

LL choose(LL top, LL bottom) {
        if (top < bottom || top < 0 || bottom < 0)
                return 0;
        else if (top == bottom || bottom == 0)
                return 1;


        LL bfs = (invF[bottom] * invF[top - bottom]) % MOD;

        //      cout << "ftop:" << top << " " << f[top] << endl;

        return (f[top] * bfs) % MOD;
}

int main() {
        ios_base::sync_with_stdio(false);
        //freopen("/Users/georgeli/A_1.in", "r", stdin);

        cin >> N >> K;

        preCalc();

        LPE(i, 1, K){
            LL pos = choose(N-K+1, i);
            LL ways = choose(K - 1, K - i);
        //    cout << i << " " << pos << " " << ways << endl;
            cout << (pos * ways) % MOD << endl;
        }

        return 0;
}

