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

//UVa 12577
//ad hoc

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	char word[500];
	int caseNum = 0;
	while (true) {
		scanf("%s", &word);

		caseNum++;
		if (strcmp(word, "*") == 0)
			break;
		else if (strcmp(word, "Hajj") == 0)
			printf("Case %d: Hajj-e-Akbar\n", caseNum);
		else if (strcmp(word, "Umrah") == 0)
			printf("Case %d: Hajj-e-Asghar\n", caseNum);
	}

	return 0;
}
