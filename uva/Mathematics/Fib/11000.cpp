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

//UVa 10450 World Cup Noise
//Fib
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

const int MaxSize = 51;
L m[MaxSize];
L f[MaxSize];

void PreProcess() {

	m[0] = 0;
	f[0] = 1;

	LP(i, 1, MaxSize)
	{
		m[i] = f[i - 1] + m[i - 1];
		f[i] = m[i - 1] + 1;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	PreProcess();

	while (true) {
		int num = 0;

		scanf("%d", &num);

		if (num < 0)
			break;

		L total = m[num] + f[num];
		printf("%llu %llu\n", m[num], total);
	}

	return 0;
}
