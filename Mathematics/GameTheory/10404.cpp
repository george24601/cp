#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10404:To Carry or not to Carry
//game theory + DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 1000000;
bool win[MaxSize + 1];
int moves[10];

int n, m;

void Process() {

	LPE(nS, 0, n)
	{
		win[nS] = false;

		LP(i, 0, m)
		{
			int move = moves[i];

			if (nS < move)
				continue;

			if (!win[nS - move]) {
				win[nS] = true;
				break;
			}
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &n, &m) == 2) {

		LP(i,0, m)
			scanf("%d", &moves[i]);

		Process();

		if (win[n])
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}

	return 0;
}
