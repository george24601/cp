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

int Dist(int x, int y)
{
	int thisRound = x + y;

	if (x + y == 0)
		return 0;

	int lastRound = thisRound - 1;

	int totalLast = ((2 + lastRound) * (1 + lastRound))/2;

	return totalLast + x;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);
	int fx,fy,sx,sy;
	LPE(caseNum, 1, numCase)
	{
		scanf("%d %d %d %d", &fx,&fy, &sx, &sy);
		int firstDist = Dist(fx, fy);
		int secondDist = Dist(sx, sy);

		printf("Case %d: %d\n", caseNum, secondDist - firstDist);
	}


	return 0;
}

