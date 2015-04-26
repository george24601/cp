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

//UVa 900 Brick wall Patterns
//DP- fib
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

L nums[52];

void Preprocess() {
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;

	LPE(i, 3, 50)
		nums[i] = nums[i - 1] + nums[i - 2];

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	Preprocess();

	while (true) {
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%llu\n", nums[n]);
	}

	return 0;
}
