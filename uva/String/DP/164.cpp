#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 164 String Computer
//string DP
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 25;
const int INF = 2000000000;

char f[MaxSize];
char s[MaxSize];

int dist[MaxSize][MaxSize];

char op[MaxSize][MaxSize];
int length[MaxSize][MaxSize]; //length of string AFTER ops

void PL(int length) {
	if (length < 10)
		printf("0%d", length);
	else
		printf("%d", length);
}

void Print_r(int fI, int sI) {
	if (fI < 0 || sI < 0)
		return;

	if (op[fI][sI] == 'I') {
		Print_r(fI, sI - 1);

		printf("%c%c", op[fI][sI], s[sI - 1]);

		PL(length[fI][sI]);
		//length here
	} else if (op[fI][sI] == 'C') {
		Print_r(fI - 1, sI - 1);

		printf("%c%c", op[fI][sI], s[sI - 1]);

		PL(length[fI][sI]);
		//length here

	} else if (op[fI][sI] == 'D') {
		Print_r(fI - 1, sI);

		printf("%c%c", op[fI][sI], f[fI - 1]);

		PL(length[fI][sI] + 1);
		//length here

	} else {
		Print_r(fI - 1, sI - 1);
	}
}

void Process() {
	int fLen = strlen(f);
	int sLen = strlen(s);

	//init 00

	dist[0][0] = 0;
	op[0][0] = 'N';
	length[0][0] = 0;

	//init r0
	LPE(si, 1, sLen)
	{
		dist[0][si] = dist[0][si - 1] + 1; //just delete all previous one
		op[0][si] = 'I';
		length[0][si] = si;
	}

	LPE(fi, 1, fLen)
	{
		dist[fi][0] = dist[fi - 1][0] + 1; //just keep inserting
		op[fi][0] = 'D';
		length[fi][0] = 0;
	}

	//init col 0

	LPE(fl, 1, fLen)
	{
		char fc = f[fl - 1];
		LPE(sl, 1, sLen)
		{
			char sc = s[sl - 1];

			int cC = fc == sc ?
							dist[fl - 1][sl - 1] : dist[fl - 1][sl - 1] + 1; //change last

			int iC = dist[fl][sl - 1] + 1; //add last
			int dC = dist[fl - 1][sl] + 1; //remove last

			if (cC <= iC && cC <= dC) {
				dist[fl][sl] = cC;
				op[fl][sl] = fc == sc ? 'N' : 'C';
				length[fl][sl] = length[fl - 1][sl - 1] + 1;

			} else if (iC <= cC && iC <= dC) {
				dist[fl][sl] = iC;
				op[fl][sl] = 'I';

				length[fl][sl] = length[fl][sl - 1] + 1;

			} else {
				dist[fl][sl] = dC;
				op[fl][sl] = 'D';
				length[fl][sl] = length[fl - 1][sl];
			}
		}
	}

	Print_r(fLen, sLen);
	printf("E\n");

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%s %s", f, s) == 2) {

		Process();

	}

	return 0;
}
