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

int N = 16, J = 50;
LL bitToDec(LL num, int base){
	LL res = 0;
	for(int shift = (N-1); shift >= 0; shift --){
		res *= base;
		int digit = (num >> shift) & 1;
		res += digit;
	}

	return res;
}


int main() {
	freopen("/Users/georgeli/C_small.out", "w", stdout);

	LL start = (1 << (N-1)) + 1;

	int found = 0;
	printf("Case #1:\n");

	while(found < J){
		LL divs[11];

		LPE(base, 2, 10){
			LL num = bitToDec(start, base);
			LL maxDiv = sqrt(num) + 1;

			bool isPrime = true;
			LPE(div, 2, maxDiv){
				if (num % div == 0){
					divs[base] = div;
					isPrime = false;
					break;
				}
			}

			if(isPrime)
				goto NextNum;
		}

		for(int i = (N-1);i >= 0; i--){
			printf("%d", (start >> i) & 1);
		}

		LPE(base, 2, 10){
			printf(" %d", divs[base]);
		}

		printf("\n");

		found++;

		NextNum:
			start += 2;
	}
}
