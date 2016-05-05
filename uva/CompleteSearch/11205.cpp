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

//UVa 11205 The Broken pedometer
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

const int MaxSize = 100;

int P, N;

int digits[MaxSize];

void Process() {
	int minNum = P;
	int choices = pow(2, P) - 1;

	LPE(choice, 1, choices)
	{
		set<int> values;
		int numDigitsUsed = 0;

		LP(digit, 0, P)
		{
			if ((choice & (1 << digit)) == (1 << digit))
				numDigitsUsed++;
		}

		if (numDigitsUsed >= minNum)
			continue;

		LP(i, 0, N)
		{
			int newVal = digits[i] & choice;
			if (values.count(newVal) > 0)
				goto Bad;
			else
				values.insert(newVal);
		}

		minNum = numDigitsUsed;

		Bad: continue;
	}

	printf("%d\n", minNum);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;

	scanf("%d", &numCase);

	LP(i, 0, numCase)
	{
		scanf("%d", &P);
		scanf("%d", &N);

		LP(row, 0, N)
		{
			int num = 0;

			LP(col, 0, P)
			{
				int digit = 0;
				scanf("%d", &digit);

				num = num | digit << col;
			}

			digits[row] = num;
		}

		Process();
	}

	return 0;
}
