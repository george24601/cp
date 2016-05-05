#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12457 D: Tennis contest
//Probability + DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 25;
int n;
double p;

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		int B, S;
		scanf("%d %d", &B, &S);

		if (B == 0 && S == 0)
			break;

		caseNum++;

		if (B == 1)
			printf("Case %d: :-\\\n", caseNum);
		else if (B <= S)
			printf("Case %d: :-|\n", caseNum);
		else
			printf("Case %d: :-(\n", caseNum);
	}

	return 0;
}
