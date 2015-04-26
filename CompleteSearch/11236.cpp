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

//UVa 11236 Grocery Store
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

L small;
L big;

int MaxP = 2000;
const int OM = 1000000;

int SqRoot_r(L target, L min, L max) {

	if (min > max)
		return -1;

	if (min == max) {
		if (min * min == target)
			return min;
		else
			return -1;
	}

	L mid = (min + max) / 2;

	if (mid * mid > target)
		return SqRoot_r(target, min, mid - 1);
	else if (mid * mid == target)
		return mid;
	else
		return SqRoot_r(target, mid + 1, max);

}

double L2D(int num) {
	return ((double) num) / 100;
	//return num % 100 < 10 ? (num % 100) * 10 : num % 100;
}

void PreProcess() {
	LPE(s, 1, MaxP)
	{
		L P = s;
		P = P * OM;

		LPE(a, 1, s/4)
		{
			if (P % a != 0)
				continue;

			L bcd = P / a;

			int maxB = (s - a) / 3;

			LPE(b, a, maxB)
			{
				if (bcd < b * b * b)
					break;

				if (bcd % b != 0)
					continue;

				L cPd = s - a - b;
				L cTd = bcd / b;

				L delta = cPd * cPd - 4 * cTd;

				if (delta < 0)
					continue;

				int root = SqRoot_r(delta, 0, 2000);

				if (root < 0)
					continue;

				L top = cPd - root;

				if (top % 2 != 0)
					continue;

				L c = top / 2;

				L d = s - a - b - c;

				if (!(c >= b && d >= c))
					continue;

				printf("%.2lf %.2lf %.2lf %.2lf\n", L2D(a), L2D(b), L2D(c),
						L2D(d));
			}
		}
	}

}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	PreProcess();

	return 0;
}

