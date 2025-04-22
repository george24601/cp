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

/*
 N <= 150
 L <= 40

 if there is a con

 brute force can do,
 For the first outlet, assume i matches, it, and then we can get config

 try config on all things, if it works, we are good
 and get smallest #

 total N * (N + N logN) * L,

 can use a UL to represent strings, or bitsets

 */
int N, Len;
bitset<50> outlets [160];
bitset<50> devices [160];

char buf[50];

int cost(int outIndex){
	bitset<50> toFilp;
	int flipCount = 0;

	//calc what to flip
	LP(i, 0, Len){
		if (outlets[outIndex][i] == devices[0][i]){
			toFilp[i] = 0;
		}else{
			toFilp[i] = 1;
			flipCount++;
		}
	}

	//apply flip to outlets
	bitset<50> flipedOutlet [160];

	LP(i, 0 , N){
		LP(j, 0, Len){
			if (toFilp[j])
				flipedOutlet[i][j] = !outlets[i][j];
			else
				flipedOutlet[i][j] = outlets[i][j];
		}
	}

	UL outletBits[160];
	UL deviceBits[160];

	LP(i, 0, N){
		outletBits[i] = flipedOutlet[i].to_ullong();
		deviceBits[i] = devices[i].to_ullong();
	}

	sort(outletBits, outletBits + N);
	sort(deviceBits, deviceBits + N);

	LP(i, 0, N){
		if (outletBits[i] != deviceBits[i])
			return INF;
	}

	return flipCount;

}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/A-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d %d", &N, &Len);
		//printf("%d %d\n", N, Len);

		LP(i, 0, N){
			scanf("%s", buf);
			outlets[i].reset();
			LP(j, 0, Len)
				outlets[i].set(j, buf[j] - '0');
		}

		LP(i, 0, N){
			scanf("%s", buf);
			devices[i].reset();
			LP(j, 0, Len)
				devices[i].set(j, buf[j] - '0');
		}

		int curMin = INF;
		LP(i, 0, N){
			curMin = min(cost(i), curMin);
		}

		if (curMin == INF)
			printf("Case #%d: NOT POSSIBLE\n", cn);
		else
			printf("Case #%d: %d\n", cn, curMin);
	}

	return 0;
}
