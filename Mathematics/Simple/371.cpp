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

//UVa 371 Ackermann Functions
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

L cache[MaxSize];

void Ac(L num, L& total) {
	if (num == 1)
		return;

	total += 1;

	if ((num % 2) == 1)
		Ac(3 * num + 1, total);
	else
		Ac(num / 2, total);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	memset(cache, 0, sizeof(cache));

	cache[1] = 3;
	while (true) {
		L first, second;
		scanf("%llu %llu", &first, &second);

		L low = Min(first, second);
		L high = Max(first, second);

		if(low == 0 && high == 0)
			break;

		L maxCount = 0;
		L numMax = 0;

		for (L i = low; i <= high; i++) {
			L curCount = 0;

			if (i < MaxSize) {
				if (cache[i] != 0)
					curCount = cache[i];
				else {
					Ac(i, curCount);
					cache[i] = curCount;
				}
			} else {
				Ac(i, curCount);
			}

			if (curCount > maxCount) {
				maxCount = curCount;
				numMax = i;
			}
		}

		printf(
				"Between %llu and %llu, %llu generates the longest sequence of %llu values.\n",
				low, high, numMax, maxCount);
	}

	return 0;
}

