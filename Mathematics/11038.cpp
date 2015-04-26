#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 558 Rough Roads
//Bellman-Ford
typedef long long L;
typedef unsigned long long ULL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 31;
const int INF = 200000000;

L Calc(L num)
{
	L curR = num % 10;
	L curL = num/ 10;

	L total = (num/10) + 1;
	L base = 10;

	while(curL > 0)
	{
		int curDigit = curL % 10;

		L newR = curR + base * curDigit;

		L newBase = base * 10;

		if(0 == curDigit)
		{
			total += curR + 1;

			total += ((num - newR - 1)/newBase) * base;

		}else
		{
			total += (num/newBase) * base;
		}

		curR = newR;

		curL = curL/10;
		base = newBase;

	}

	return total;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {

		L m,n;

		scanf("%lld %lld", &m, &n);

		if(m < 0 || n < 0)
			break;

		L result = 0;

		if(n != m && m == 0)
			result = Calc(n);
		else
			result = Calc(n) - Calc(m - 1);

		printf("%lld\n", result);
//		printf("%d\n", Calc(100));
	}

	return 0;
}

