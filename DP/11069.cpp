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

int const MaxSize = 100;
int ans[MaxSize];

int DP_r(int n)
{
	if(ans[n] >= 0)
		return ans[n];

	ans[n] = DP_r(n - 2);
	ans[n] += DP_r(n - 3);

	return ans[n];
}


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int n;
	memset(ans, -1, sizeof(ans));

	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 1;

	while(scanf("%d", &n) == 1)
	{
		int first = DP_r(n);
		int second = DP_r(n-1);

		printf("%d\n", first + second);
	}

	return 0;
}
