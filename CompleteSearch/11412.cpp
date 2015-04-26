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

//UVa 11553  grid game
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 1000;

char q1[5];
char q2[5];

int pos[4];

int f1, s1, f2, s2;

int CToN(char color) {
	if (color == 'R')
		return 0;
	if (color == 'B')
		return 1;
	if (color == 'G')
		return 2;
	if (color == 'Y')
		return 3;
	if (color == 'O')
		return 4;
	if (color == 'V')
		return 5;
}

bool Verify(char * gS, int f, int s) {

	int samePos = 0;
	int existsButDiff = 0;
	LP(guess, 0, 4)
	{
		LP(actual, 0, 4)
		{
			if (CToN(gS[guess]) == pos[actual]) {
				if (guess == actual)
					samePos++;
				else
					existsButDiff++;

			}
		}
	}

	return f == samePos && s == existsButDiff;
}

bool Process_r(int colIndex, int used) {

	if (colIndex >= 4)
		return Verify(q1, f1, s1) && Verify(q2, f2, s2);

	LP(i, 0, 6)
	{
		if (((used >> i) & 1) == 1)
			continue;

		pos[colIndex] = i;

		bool possible = Process_r(colIndex + 1, (used | (1 << i)));

		if (possible)
			return true;
	}

	return false;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	LP(caseN, 0, t)
	{
		scanf("%s", &q1);
		scanf("%d %d", &f1, &s1);

		scanf("%s", &q2);
		scanf("%d %d", &f2, &s2);

		bool possible = Process_r(0, 0);

		if (possible)
			printf("Possible\n");
		else
			printf("Cheat\n");
	}

	return 0;
}
