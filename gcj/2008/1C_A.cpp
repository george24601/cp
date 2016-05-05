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
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
#define INF 2000000000
#define Ep 1e-9

/*
 unknown:
 an arrangement

 condition:
 the arrangement will win the game, in increasing order, i.e., order of removal is 1,2,3,4....

 */

int N, P, K, L;
int const MaxL = 1000;
int nums[MaxL];

LL p(){
	sort(nums, nums + L);

	int index = 0;
	int depth = 1;
	LL total = 0;

	while(index < L){

		if (index + K < L){

			LP(i, 0, K)
					total += depth * -nums[index + i];
		}else{
			LP(i, index, L)
					total += depth * -nums[i];
		}

		depth++;
		index += K;
	}

	return total;
}

int main() {
	freopen("/Users/georgeli/Downloads/A-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	cin >> N;

	//printf("%d\n", N);

	LPE(cn, 1, N)
	{
		cin >> P >> K >> L;

		memset(nums, 0, sizeof(nums));

		LP(i, 0, L)
		{
			cin >> nums[i];
			nums[i] *= -1;

		}

//		printf("%d %d %d\n", P, K, L);

		printf("Case #%d: %lld\n", cn, p());

	}

	return 0;
}
