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
#include <map>
using namespace std;

//UVa 11053 Flavius Josephus Reloaded
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
#define Ep 1e-9

L N, a, b;


L f(L current)
{
	L next = ((((current * current) % N) * a) % N + b) % N;
	return next;
}

L P_r() {
	L t = f(0);
	L h = f(f(0));
	L v = 1;

	while(t != h)
	{
		t = f(t);
		h = f(f(h));
	}

	L startV = 0;

	while(startV != h)
	{
		startV = f(startV);
		h = f(h);
	}


	h = f(h);
	L cl = 1;

	while(h != startV)
	{
		h = f(h);
		cl++;
	}

	return cl;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%llu %llu %llu", &N, &a, &b) == 3) {

		L killed = P_r();

		printf("%llu\n", N - killed);
	}

	return 0;
}
