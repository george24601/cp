#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

//UVa 11242 Tour de France
//Complete Search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b

const int MaxSize = 10000;

int f;
int r;
const int MaxF = 10;

int fs[MaxF];
int rs[MaxF];

double ratios[100];

void Process() {

	int index = 0;
	LP(i, 0, f)
	{
		LP(j, 0, r)
		{
			ratios[index] = (double) rs[j] / (double) fs[i];

			index++;
		}
	}

	sort(ratios, ratios + f * r);

	double max = 0;
	LP(i, 1, f*r)
		max = Max(max, ratios[i] / ratios[i - 1]);

	printf("%.2lf\n", max);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d", &f)) {

		if (f == 0)
			break;

		scanf("%d", &r);

		LP(i, 0, f)
			scanf("%d", &fs[i]);

		LP(i, 0, r)
			scanf("%d", &rs[i]);

		Process();
	}

	return 0;
}
