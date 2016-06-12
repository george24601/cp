#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-8

/*
 15 primes < 50

 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47.

 if it is a composite, there must a divsior <= 10

 2, 3, 5, 7

 if no divisor for these 4 numbers => we know it must be prime

 if there is a divisor,
 how to tell between 2, 4, and 22

 94
 so try collecting all answers:
 if # >= 2 : we know it is compiste
 if == 1; we try its square

 */

int const MaxSize = 15;
int prime[MaxSize] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

int curDiv;
int numDiv;

void test(int tn) {

	printf("%d\n", tn);
	fflush(stdout);

	char response[5];
	scanf("%s", response);

	if (strcmp(response, "yes") == 0) {
		curDiv = tn;

//		cout <<"found!!" <<  tn << endl;

		numDiv++;

	}
}

int main() {
	//freopen("/Users/georgeli/A_3.in", "r", stdin);

	int const FirstSize = 4;
	curDiv= 0;
	numDiv = 0;

	LP(i, 0, FirstSize)
		test(prime[i]);

	if (numDiv == 0) {
		printf("prime");
		fflush(stdout);
		return 0;
	}

	LP(i, FirstSize, MaxSize)
		test(prime[i]);

	if (numDiv > 1) {
		printf("composite");
		fflush(stdout);
		return 0;
	}

	assert(curDiv >= 2);

	int unitDiv = curDiv;
	int nextTry = unitDiv * unitDiv;

	LP(i, 0, 5)
	{
		if (nextTry > 100)
			break;

		test(nextTry);
		nextTry *= unitDiv;
	}

	if (numDiv > 1)
		printf("composite");
	else
		printf("prime");

	fflush(stdout);

	return 0;
}
