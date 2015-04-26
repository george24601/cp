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

int const MaxSize = 250001;

vector<int> primes;
int ans[MaxSize];
	bool isHSP[MaxSize];
	bool isPrime[MaxSize];

void CalcHPrime() {
	//calculate all H-primes
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;

	primes.clear();

	LP(i, 1, MaxSize)
	{
		if (!isPrime[i])
			continue;

		LP(j, 1, MaxSize)
		{
			int iTj = (4 * i + 1) * (4 * j + 1);

			int index = (iTj - 1) / 4;

			if (index >= MaxSize)
				break;

			isPrime[index] = false;
		}
	}

	LP(i, 1, MaxSize)
	{
		if (isPrime[i])
			primes.push_back(i);
	}
}

void CalcHSP() {
	memset(isHSP, false, sizeof(isHSP));

	LP(i, 0, primes.size())
	{
		L firstN = primes[i] * 4 + 1;
		LP(j, i, primes.size())
		{
			L secondN = primes[j] * 4 + 1;
			L result = firstN * secondN;

			L index = (result - 1) / 4;

			if (index >= MaxSize)
				break;

			isHSP[index] = true;
		}
	}


	int total = 0;
	LP(i, 0, MaxSize)
	{
		if (isHSP[i])
			total++;

		ans[i] = total;
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\A.1.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	CalcHPrime();
//	cout << primes.size() << endl;
	CalcHSP();

	while (true) {
		int num;
		scanf("%d", &num);

		if(0 == num)
			break;

		int index = (num - 1) / 4;

		printf("%d %d\n", num, ans[index]);
	}

	return 0;
}
