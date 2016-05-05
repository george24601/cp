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

//UVa 1185 Big Number
//mathematics
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

const int Size = 1000001;
double ans[Size];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	ans[1] = 0;

	LP(i, 2, Size)
		ans[i] = ans[i - 1] + log2(i);

	while (true) {
		int year;
		scanf("%d", &year);

		if (year == 0)
			break;

		int since = (year - 1960) / 10;
		int tarDigits = 4 * pow(2, since);

		LP(n, 1, Size)
		{
			int digits = ((int) ans[n]) + 1;

			int nextDigits = ((int) ans[n + 1]) + 1;

			if (digits <= tarDigits && nextDigits > tarDigits) {
				printf("%d\n", n);
				break;
			}
		}

	}

	return 0;
}

