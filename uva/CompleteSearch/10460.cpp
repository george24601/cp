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

//UVa 10460 Find the Permuted String
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

char result[40];
char buff[40];
bool occupied[40];
int leng;

void Process_r(int curLeng, int i) {
	if (curLeng == 0)
		return;

	int emptyPos = i % curLeng;

	int insertionIndex = 0;

	int counter = 0;
	for (; insertionIndex < leng; insertionIndex++) {

		if (!occupied[insertionIndex])
			counter++;

		if (counter == emptyPos + 1)
			break;
	}

	result[insertionIndex] = buff[curLeng - 1];
	occupied[insertionIndex] = true;

	Process_r(curLeng - 1, i / curLeng);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LP(i, 0, numCase)
	{
		memset(result, 0, sizeof(result));
		memset(buff, 0, sizeof(buff));
		memset(occupied, false, sizeof(occupied));

		scanf("%s", buff);
		leng = strlen(buff);
		int I;
		scanf("%d", &I);

		Process_r(leng, I - 1);

		printf("%s\n", result);
	}

	return 0;
}

