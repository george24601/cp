#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11723 Numbering Roads
//simple math

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;
int R, N;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (scanf("%d %d", &R, &N)) {

		if(R == 0 && N == 0)
			break;

		caseNum++;

		int D =  R/N;

		if (R%N == 0)
			D--;

		if (D >26)
			printf("Case %d: impossible\n", caseNum);
		else
			printf("Case %d: %d\n", caseNum, D);
	}

	return 0;
}
