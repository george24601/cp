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

//UVa 138 Street Numbers
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

const int MaxSize = 2000000;

int n, m, k;

L first[10];
L second[10];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int counter = 2;
    first[0] = 6; second[0] =  8;
    first[1]=35; second[1]=  49;
	while (counter < 10) {
		first[counter] = 6 * first[counter - 1] - first[counter - 2];

		second[counter] = first[counter] + first[counter - 1] + second[counter - 1];
		counter++;
	}


	LP(i, 0, 10)
	{
		printf("%10llu%10llu\n", first[i], second[i]);

	}

	return 0;
}

