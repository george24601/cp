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

//UVa 11689 Soda Surpler
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

int e, f, c;
int numShows;

void Process_r(int total) {
	int num = total / c;
	numShows += num;

	if (total < c) {
		//get final result
		printf("%d\n", numShows);
	} else {
		int nextRound = total % c;

		Process_r(num + nextRound);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);
	LP(i, 0, numCase)
	{
		scanf("%d %d %d", &e, &f, &c);

		numShows = 0;
		Process_r(e + f);
	}

	return 0;
}

