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

//UVa 11313 Gourment Games
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

int n, m;
int numShows;

void Process_r(int total) {
	if (total == m) {
		//get final result
		numShows++;

		printf("%d\n", numShows);
		return;
	} else if (total < m) {
		//bad

		printf("cannot do this\n");
		return;
	} else {
		int num = total / m;
		int nextRound = total % m;

		numShows += num;

		Process_r(num + nextRound);
	}
}
int main(int argc, const char * argv[]) {

	///freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);
	LP(i, 0, numCase)
	{
		scanf("%d %d", &n, &m);

		numShows = 0;
		Process_r(n);
	}

	return 0;
}

