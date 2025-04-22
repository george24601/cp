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
 */

int A, B, K;
int const MaxSize = 32;

LL _ways[MaxSize][2][2][2];

int getBit(int num, int bitPos) {
	return (num >> bitPos) & 1;
}

LL ways(int bitPos, bool APre, bool BPre, bool KPre) {

	if (bitPos == -1) {
		//base case
		return !APre && !BPre && !KPre; //we need to generate # less than K, plus, numbers from A, B are LESS than A, B. Other cases are always valid, since only valid case can proceed
	}

	int aI = APre? 1 : 0;
	int bI = BPre? 1 : 0;
	int kI = KPre? 1 : 0;

	if (_ways[bitPos][aI][bI][kI] >= 0)
		return _ways[bitPos][aI][bI][kI];

	//printf("%d\n", bitPos);

	int curABit = getBit(A, bitPos);
	bool A0Prefix = APre && !curABit;
	int curBBit = getBit(B, bitPos);
	bool B0Prefix = BPre && !curBBit;
	int curKBit = getBit(K, bitPos);
	bool K0Prefix = KPre && !curKBit;

	//Insight: how to simplify it?instead of turning it into a giant nested statement? with each end reducing to true/false instead of a variable

	//case: both a, b gives 0
	LL result = ways(bitPos - 1, A0Prefix, B0Prefix, K0Prefix); //K's bit must be 0

	//case: a 1, b 0
	if (!A0Prefix) //either ABit is 1, or already less than that
		result += ways(bitPos - 1, APre, B0Prefix, K0Prefix);

	//case: a 0, b 1
	if (!B0Prefix)
		result += ways(bitPos - 1, A0Prefix, BPre, K0Prefix);

	//case: a 1, b 1
	if (!A0Prefix && !B0Prefix && !K0Prefix)
		result += ways(bitPos - 1, APre, BPre, KPre);

	return _ways[bitPos][aI][bI][kI] = result;
}

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/B_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d %d %d", &A, &B, &K);
		//printf("%d %d %d", A, B, K);

		LP(i, 0, MaxSize)
		{
			LP(j, 0, 2)
			{
				LP(k, 0, 2)
				{
					LP(m, 0, 2)
					{
						_ways[i][j][k][m] = -1;
					}
				}
			}
		}


		printf("Case #%d: %lld\n", cn, ways(31, true, true, true));
	}

	return 0;
}
