#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

//UVa 11614 Etruscan Warriors Never Play Chess
//ad hoc

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;

L n;

L Calc(L num) {
	return ((1 + num) * num) / 2;
}

L Search_r(L start, L end) {
	if (start == end)
		return start;

	L mid = (start + end) / 2;

	if (Calc(mid + 1) <= n)
		return Search_r(mid + 1, end);
	else if (Calc(mid) > n)
		return Search_r(start, mid - 1);
	else
		return mid;
}

int main(int argc, const char * argv[]) {

///	freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;
	scanf("%d", &numCase);

	LP(i, 0, numCase)
	{
		scanf("%llu", &n);
		L start = Search_r(1, 1000000000);
		printf("%llu\n", start);
	}

	return 0;
}
