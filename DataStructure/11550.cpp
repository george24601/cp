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
using namespace std;

//UVa 11550 DEMANDING DILEMMA
//graph structure

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 1000;

int input[8][28];
int n, m;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	LPE(caseN, 1, t)
	{
		scanf("%d %d", &n, &m);

		LP(v, 0, n)
		{
			LP(e, 0, m)
				scanf("%d", &input[v][e]);
		}

		bool aM[8][8];

		memset(aM, false, sizeof(aM));
		LP(e, 0, m)
		{
			int sum = 0;
			LP(v, 0, n)
			{
				if (input[v][e] == 1)
					sum++;
			}

			if (sum != 2)
				goto Bad;

			int firstV = 0;

			while (input[firstV][e] == 0)
				firstV++;

			int secondV = firstV + 1;
			while (input[secondV][e] == 0)
				secondV++;

			if (aM[firstV][secondV])
				goto Bad;

			aM[firstV][secondV] = true;
			aM[secondV][firstV] = true;
		}

		printf("Yes\n");
		continue;

		Bad: printf("No\n");

	}

	return 0;
}
