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

//UVa 10642 Can you solve it
//mathematics => cantor

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

const int MaxSize = 2000000;

int CalcTotal(int rc)
{
	int total = 1;

	if (rc == 0)
		return total;

	return total + 2 *(1 + rc) * rc;
}

int LastRC(int num)
{
	int lastRC = 0;

	while(CalcTotal(lastRC) < num)
		lastRC++;

	return lastRC - 1;
}

void Coord(int num, int&x, int&y)
{
	if (num == 0)
	{
		x = 0;
		y = 0;
		return;
	}

	int lastRC = LastRC(num + 1);

	int remaining = num + 1 - CalcTotal(lastRC);

	int curRC = lastRC + 1;
	int dir = (remaining -1) /curRC;
	int precise = (remaining - 1) % curRC;

	if (dir == 1)
	{
		x = precise + 1;
		y = curRC - x;

	}else if(dir == 2)
	{
		y = -precise -1;
		x = curRC + y;
	}else if(dir == 3)
	{
		x = -precise - 1;
		y = -curRC - x;

	}else
	{
		y = precise + 1;
		x = -curRC + y;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int a,b;
	while(true)
	{
		scanf("%d %d", &a, &b);

		if (a== -1 && b == -1)
			break;
		int fx,fy, sx, sy;

		Coord(a, fx, fy);
		Coord(b, sx, sy);

		int sqDist = (fx - sx) * (fx - sx) + (fy - sy) * (fy - sy);

		printf("%.2lf\n", sqrt(sqDist));
	}


	return 0;
}

