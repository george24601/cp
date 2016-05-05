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

int const MaxSize = 100000;

int p;

bool bits[MaxSize];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\E.0.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		scanf("%d", &p);

		if (p == 0)
			break;

		memset(bits, true, sizeof(bits));

		LPE(i, 1, p)
		{
			L row = i;
			L index = (row * row) % p;

			bits[index - 1] = false;
		}

		bool hasOne = false;
		LP(i, 0, p - 1)
		{
			if (bits[i]) {
				hasOne = true;
				break;
			}
		}

		if (!hasOne) {
			printf("Impossible\n");
			continue;
		}
		LP(i, 0, p - 1)
		{
			if (bits[i])
				printf("1");
			else
				printf("0");
		}

		printf("\n");
	}

	return 0;
}
