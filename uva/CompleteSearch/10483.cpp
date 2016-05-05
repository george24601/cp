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

//UVa 10483 The Sum Equals the Product
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

double ss[500];
double as[500];
double bs[500];
double cs[500];
int size;

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

double Last2D(int num) {
	return ((double) num) / 100;
	//return num % 100 < 10 ? (num % 100) * 10 : num % 100;
}

void PreProcess() {
	size = 0;
	LPE(num, 1, 25900)
	{
		L target = num * 10000;

		LPE(a, 1, num/3)
		{
			if (target % a != 0)
				continue;

			L S = num - a;
			L P = target / a;

			L delta = S * S - 4 * P;

			int root = SqRoot_r(delta, 0, 2560000);

			if (root < 0)
				continue;

			L top = S - root;

			if (top % 2 != 0)
				continue;

			L b = top / 2;

			if (b < a)
				continue;

			if (P % b != 0)
				continue;

			L c = S - b;
			if (P / b != c)
				continue;

			ss[size] = num;
			as[size] = a;
			bs[size] = b;
			cs[size] = c;

			size++;
		}
	}

}

void Process()
{
			printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n",
					Last2D(num), Last2D(a), Last2D(b), Last2D(c), Last2D(a),
					Last2D(b), Last2D(c));

}
int main(int argc, const char * argv[]) {

	freopen("C:\\Test\\Test.txt", "r", stdin);

	int aF, aS, bF, bS;
		PreProcess();
	while (scanf("%d.%d %d.%d", &aF, &aS, &bF, &bS) == 4) {
		int f = 100 * aF + aS;
		int s = 100 * bF + bS;

		small = Min(f, s);
		big = Max(f, s);

		Process();

	}

	return 0;
}

