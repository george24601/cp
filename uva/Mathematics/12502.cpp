#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12502 Three Families 
//simple math

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int T = 0;
	scanf("%d", &T);

	LPE(caseNum, 1, T)
	{
		L x, y, z;

		scanf("%llu %llu %llu", &x, &y, &z);

		L result = ((2* x - y) * z)/ (x + y);


		printf("%llu\n",result);
	}

	return 0;
}
