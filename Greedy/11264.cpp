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

int const MaxSize = 1001;
int coins[MaxSize];

int n;

int const cacheSize = 3000000;
int cache[cacheSize];

int Biggest(int amount)
{
	int low = 0;
	int high = n -1;

	while(low != high)
	{
		int mid = (low + high)/2;

		if(coins[mid] == amount)
			return mid;
		else if(coins[mid] > amount)
			high = mid - 1;
		else if(low + 1 == high)
			return coins[high] <= amount? high: low;
		else
			low = mid;
	}

	return low;
}

int M(int amount)
{
	if(amount < cacheSize && cache[amount] >= 0)
		return cache[amount];

	if(amount  == 0)
		return 0;
	else if(amount == 1)
		return 1;

	int maxCI = Biggest(amount);

	int maxCV = coins[maxCI];
	int noUse = M(maxCV - 1);

	int use;

	if(amount - maxCV >= (maxCV - 1))
	  use = noUse + 1;
	else
	  use = M(amount % maxCV) + 1;

	int toReturn = max(noUse, use);

	if(amount < cacheSize)
		cache[amount] = toReturn;


	return toReturn;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);

		LP(i, 0, n)
		    scanf("%d", &coins[i]);

		int ans = M(coins[n - 1] * 2 - 1);

		printf("%d\n", ans);
	}

	return 0;
}
