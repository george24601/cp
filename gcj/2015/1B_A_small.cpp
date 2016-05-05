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

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define INF 2000000000
#define Ep 1e-9

/*
Either reserver or add 1 => we need a function to reverse digits regardless

during process, new insight discovered:
1.digits end with 0 is a speical case => you can introduce only via +1
2.you reverse only to increase, never decrease
 */
int const MaxSize = 1000001;
int T;
int N; //Test small input first

int ans[MaxSize];

long reverse(long num){
	long toReturn = 0;

	while(num > 0)
	{
		toReturn *= 10;
		toReturn += num % 10;
		num /= 10;
	}

	return toReturn;
}

void process()
{
	ans[1] = 1;

	LP(i, 2, MaxSize){
		long reversed = reverse(i);

		ans[i] = ans[i - 1] + 1;
		if (reversed < i && i % 10 != 0)
			ans[i] = min(ans[i], ans[reversed] + 1);
	}
}

int main() {
	freopen("/Users/georgeli/Downloads/A-small-practice.in", "r", stdin);
	//freopen("/Users/georgeli/1B_A_1.in", "r", stdin);
	freopen("/Users/georgeli/1B_A_small.out", "w", stdout);

	scanf("%d", &T);

	process();
	LPE(i, 1, T)
	{
		scanf("%d", &N);
		printf("Case #%d: %d\n", i, ans[N]);
	}

	return 0;
}
