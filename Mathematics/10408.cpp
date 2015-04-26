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
using namespace std;

//UVa 10408 Farey sequences
//mathematics
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n, k;

int ansT, ansB;

void P_r(int a, int b, int c, int d, int cur)
{
	int p = ((n + b)/d) * c - a;
	int q = ((n + b)/d) * d - b;

	if(cur == k)
	{
		ansT = p;
		ansB = q;
	}else
	{
		P_r(c, d, p, q, cur + 1);
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &n, &k) == 2) {

		if(k == 1)
		{
			ansT = 1;
			ansB = n;
		}else if(k == 2)
		{
			ansT = 1;
			ansB = n - 1;

		}else
		{
			P_r(1, n, 1, n - 1, 3);
		}

		printf("%d/%d\n", ansT, ansB);
	}

	return 0;
}

