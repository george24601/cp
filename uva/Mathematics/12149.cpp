#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12149 Feyman 
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

	L T;
	while(true)
	{
		scanf("%llu", &T);

		if(T == 0)
			break;

		L result = T * (T + 1) * (2*T + 1);
		result = result / 6;

		printf("%llu\n", result);

	}


	return 0;
}
