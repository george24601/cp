#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11875 Brick Game 
//simple math

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;

int nums[MaxSize];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int T = 0;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		int N;

		scanf("%d", &N );

		LP(i, 0, N)
			scanf("%d", &nums[i]);


		printf("Case %d: %d\n", caseNum, nums[N/2]);
	}

	return 0;
}
