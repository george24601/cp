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

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define INF 2000000000
#define Ep 1e-9

int const MaxSize = 200000;
char W[MaxSize];
char rW[MaxSize];
int wLen;
int T[MaxSize];
int rT[MaxSize];

void BuildRT() {
	rT[0] = -1; //special case
	rT[1] = 0; //0 because we have no suffix right now

	int i = 2;
	int rI = 0;

	while (i < wLen) {

		if (rW[i - 1] == rW[rI]) {
			//i - 1 can extend an existing suffix which is also a prefix
			rT[i] = rI + 1;
			i += 1;
			rI = rI + 1;
		} else if (rI > 0) {
			//so the suffix ending at i-1 will not work for current starting point, can we try a shorter suffix?
			//notice the suffix ending at i-2 has T[tI] matches already, so we will try that match's starting point
			rI = rT[rI];
		} else {
			//i -2 is not part of prefix, and i-1 is not same as the first char, so no valid suffix => reset to a fresh start
			rT[i] = 0;
			i += 1;
		}
	}
}

void BuildT() {
	T[0] = 0; //special case

	int i = 1;
	int rI = 0;

	while (i < wLen) {

//		printf("%d %d\n", i - 1, rI);

		if (W[i - 1] == rW[rI]) {
			//i - 1 can extend an existing suffix which is also a prefix
			T[i] = rI + 1;
			i += 1;
			rI = rI + 1;
		} else if (rI > 0) {
			//so the suffix ending at i-1 will not work for current starting point, can we try a shorter suffix?
			//notice the suffix ending at i-2 has T[tI] matches already, so we will try that match's starting point
			rI = rT[rI];
		} else {
			//i -2 is not part of prefix, and i-1 is not same as the first char, so no valid suffix => reset to a fresh start
			T[i] = 0;
			i += 1;
		}
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (scanf("%s", W) > 0) {
		//buildrW
		wLen = strlen(W);

		LP(i, 0, wLen)
			rW[i] = W[wLen - 1 - i];

		BuildRT();
		BuildT();

		printf("%s", W);

		int pLen = 1;
		LP(i, wLen/2, wLen)
		{
			int rLen = wLen - i;

			//		if (i == 5)
			//			printf("%d %d\n", rLen, T[i]);

			if (rLen == T[i])
				pLen = 2 * rLen;
			else if (rLen == T[i] + 1)
				pLen = 2 * rLen - 1;
		}

		LP(i, pLen, wLen)
			printf("%c", rW[i]);

		printf("\n");
	}

	return 0;
}
