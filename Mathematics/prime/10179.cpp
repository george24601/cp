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

vector<int> primes;

void factor(int n)
{
	int div = 2;
	int num = n;

	while(num > 1 && div <= sqrt(n))
	{
		if(num % div > 0)
			div++;
		else
		{
			while(num %div == 0)
				num /= div;

			primes.push_back(div);
		}
	}

	if(num > 1)
		primes.push_back(num);
}


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);

	int num;
	while (scanf("%d", &num) == 1)
	{
		if(num == 0)
			break;

		primes.clear();

		factor(num);

		int ans = num;
		LP(i, 0, primes.size())
		{
			ans /= primes[i];
			ans *= primes[i] -1;
		}



		printf("%d\n", ans);
	}

	return 0;
}
