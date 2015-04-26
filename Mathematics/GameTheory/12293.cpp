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

//UVa 12293 Box Gmae
//Game theory

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

L n;

bool Process_r(L l) {
	if (n == l)
		return false;
	else if (n <= 2 * l)
		return true;
	else
		return Process_r(2 * l + 1);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%llu", &n);

		if (n == 0)
			break;

		if (Process_r(1))
			printf("Alice\n");
		else
			printf("Bob\n");
	}

	return 0;
}
