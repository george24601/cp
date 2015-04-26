#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12455 Bars
//DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

int p, q;

const int MaxSize = 1000;

L Fs[20];
L Cs[20];
L V, T;

int N;
L minCost;

void Process() {
	L set = pow(2, N) - 1;

	LPE(choice, 0, set)
	{
		L totalCost = 0;
		L totalFlow = 0;

		LP(gate, 0, N)
		{
			if ((choice >> gate) & 1 == 1) {
				totalCost += Cs[gate];
				totalFlow += Fs[gate];
			}
		}

		if (totalFlow * T < V) {
			continue;
		} else {
			if (minCost == 0)
				minCost = totalCost;
			else
				minCost = Min(minCost, totalCost);
		}
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	scanf("%d", &N);

	LP(i, 0, N)
		scanf("%d %d", &Fs[i], &Cs[i]);

	int M;
	scanf("%d", &M);

	LPE(i, 1, M)
	{
		scanf("%d %d", &V, &T);
		minCost = 0;

		Process();

		if (minCost == 0)
			printf("Case %d: IMPOSSIBLE\n", i);
		else
			printf("Case %d: %llu\n", i, minCost);
	}

	return 0;
}
