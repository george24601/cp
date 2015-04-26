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
#include <stack>
#include <queue>
using namespace std;

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

int const MaxSize = 365;

bool IsPrime(int p)
{
	int rt = sqrt(p);

	LPE(i, 2, rt)
	{
		if (p % i == 0)
			return false;
	}

	return true;
}

L pm(L a, L p, L m)
{
	if(p == 0)
		return 1;

	L half = pm(a, p/2, m);

	L full = (half * half) % m;

	if(p %2 == 1)
		full = (full * a) % m;

	return full;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\C.1.dat", "r", stdin);
///	freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		int p, a;
		scanf("%d %d", &p, &a);

		if(0 == p && 0 == a)
			break;

		  if(!IsPrime(p) && pm(a, p, p) == a)
			  printf("yes\n");
		  else
			  printf("no\n");
	}

	return 0;
}
