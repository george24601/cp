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

int const MaxSize = 1000;

int n, m;

bool possible(int prime, int count)
{
	if(m < prime)
		return false;

	int remaining = count;
	int curUnit = 1;

	while(remaining > 0)
	{
		if(curUnit > m)
			break;
		else
		    curUnit *= prime;

		remaining -= m/curUnit;
	}

	return remaining <= 0;
}

bool factor()
{
	int div = 2;
	int num = n;

	while(num > 1 && div <= sqrt(n))
	{
		if(num % div > 0)
			div++;
		else
		{
			int count = 0;

			while(num %div == 0)
			{
				num /= div;
				count++;
			}

			if(!possible(div, count))
				return false;
		}
	}

	if(num > 1)
		return possible(num, 1);
    else
	    return true;
}


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);

	while (scanf("%d %d", &m, &n) == 2)
	{
		if(factor())
			printf("%d divides %d!\n", n, m);
		else
			printf("%d does not divide %d!\n", n, m);
	}

	return 0;
}
