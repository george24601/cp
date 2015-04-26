#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12024 Hats
//Probability + DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 12;
L top[MaxSize + 1];
L bottom[MaxSize + 1];

void Process() {
	top[1] = 0;
	bottom[1] = 1;

	top[2] = 1;
	bottom[2] = 2;

	LPE (i, 3, MaxSize)
	{
		top[i] = top[i - 1] * (i - 1) + (i - 1) * top[i - 2];
		bottom[i] = bottom[i - 1] * (i);
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	Process();

	int num;
	scanf("%d", &num);

	LP(i, 0, num)
	{
		int index;
		scanf("%d", &index);

		printf("%llu/%llu\n", top[index], bottom[index]);
	}

	return 0;
}
