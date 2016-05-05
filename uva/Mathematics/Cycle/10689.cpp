#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 10689 Yet another Number Sequence
//cycle finding
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
#define Ep 1e-9

const int MaxSize = 1000;

int a, b, mod;

int cycleStart;
int cycleLength;

PII f(PII p) {

	int next = (p.first + p.second) % mod;

	return make_pair(p.second, next);
}

void ComputeToIndex(int toIndex) {

	PII init = make_pair(a % mod, b % mod);
	int curIndex =0;

	while(curIndex < toIndex)
	{
		init = f(init);
		curIndex++;
	}

	printf("%d\n", init.first);
}

void ComputeCycle() {

	PII init = make_pair(a % mod, b % mod);

	PII t = f(init);
	PII h = f(f(init));

	while (true) {
		if (t == h)
			break;

		t = f(t);
		h = f(f(h));
	}

	int startIndex = 0;
	t = init;

	while (true) {
		if (t == h)
			break;

		t = f(t);
		h = f(h);
		startIndex++;
	}

	t = f(t);
	int numItems = 1;

	while (true) {
		if (t == h)
			break;

		t = f(t);
		numItems++;
	}

	cycleStart = startIndex;
	cycleLength = numItems;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;

	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		int n, m;
		scanf("%d %d %d %d", &a, &b, &n, &m);

		mod = pow(10, m);
		ComputeCycle();

		int seqIndex = n;

		int toIndex =0;

		if(seqIndex >= cycleStart)
		{
			toIndex = seqIndex % cycleLength;
		}else
		{
			toIndex = seqIndex;
		}

		ComputeToIndex(toIndex);



		//catch: 1. out of cycle case 2. the cycle info starts at the 2nd one!
		//3. truncate the OOC part
	}

	return 0;
}
