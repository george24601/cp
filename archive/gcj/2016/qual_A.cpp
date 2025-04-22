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
1. consider only digits from 0 -9, if they are all possible, any bigger number is possible
notice 0 - 9 * (0 -9) mod 10 form a group

we can definitely form a chain from 1 -> 9 -> 9, i.e., max 20 times
if last digits are 0, that is fine, reduce to smaller case anyway

while(true)
	update digits



	if(all good)
		break;
	cur += N

 */
int N;
bitset<10> seen;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/A-large.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d", &N);
		seen.reset();

		if (0 == N){
			printf("Case #%d: INSOMNIA\n", cn);
			continue;
		}

		LL cur = N;

		while(true){
			LL temp = cur;

			while(temp > 0){
				int digit = temp % 10;
				seen.set(digit);
				temp /= 10;
			}

			if(seen.all()){
				printf("Case #%d: %lld\n", cn, cur);
				break;
			}else{
				cur += N;
			}
		}
	}

	return 0;
}
