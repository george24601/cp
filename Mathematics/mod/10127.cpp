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
#define Ep 1e-9

int const MaxSize = 10000;

L ans[MaxSize + 1];

void PreCompute() {
	ans[1] = 1;

	LPE(i, 3, MaxSize)
	{
		if(i %2 == 0 || i % 5 == 0)
			continue;

		int curMod = 1;
		LP(digits, 1, 100000)
		{
			if(curMod == 0)
			{
				ans[i] = digits;
				break;
			}else
			{
				curMod = (curMod * 10 + 1) % i;
			}
		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);

	int n;

	PreCompute();

	while (scanf("%d", &n) == 1)
		printf("%d\n", ans[n]);

	return 0;
}
