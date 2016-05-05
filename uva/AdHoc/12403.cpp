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

//UVa 12403 Save setu
//ad hoc

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	char word[500];
	int N;
	scanf("%d", &N);

	L sum = 0;
	LP(i, 0, N)
	{
		scanf("%s", &word);

		if (strcmp(word, "donate") == 0) {
			L amount;
			scanf("%llu", &amount);

			sum += amount;
		} else {
			printf("%llu\n", sum);
		}

	}

	return 0;
}
