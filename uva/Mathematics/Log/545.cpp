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

//UVa 545 square numbers
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

const int Size = 9001;
double first[Size];
int digit[Size];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	first[1] = 5;
	digit[1] = 1;

	LP(i, 1, Size - 1)
	{
		double next = first[i] / 2;

		if (next < 1) {
			first[i + 1] = next * 10;
			digit[i + 1] = digit[i] + 1;
		} else {
			first[i + 1] = next;
			digit[i + 1] = digit[i];
		}
	}

	int r;
	scanf("%d", &r);

	LP(i, 0, r)
	{
		int n;
		scanf("%d", &n);

		printf("2^-%d = %.3lfE-%d\n", n, first[n] + Ep, digit[n]);
	}

	return 0;
}

