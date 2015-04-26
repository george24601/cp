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
using namespace std;

//UVa 124 following orders
//graph - DFS
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

char vars[30];
map<int, int> cToI;
int varLength;

SAL rhConstraints;
int used;

char sol[30];

void P_r(int index) {

	if (index == varLength) {
		LP(i, 0, varLength)
			printf("%c", sol[i]);

		printf("\n");
		return;
	}

	LP(i, 0, varLength)
	{
		char curChar = vars[i];
		int curCIndex = cToI[curChar];

		if (((used >> curCIndex) & 1) == 1)
			continue;

		bool canAttach = true;
		LP(j, 0, rhConstraints[curCIndex].size())
		{
			int lhIndex = rhConstraints[curCIndex][j];

			if (((used >> lhIndex) & 1) == 0) {
				canAttach = false;
				break;
			}
		}

		if (!canAttach)
			continue;

		sol[index] = curChar;
		int prevUsed = used;
		used = used | (1 << curCIndex);
		P_r(index + 1);
		used = prevUsed;

	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	char varBuff[1000];

	int caseNum = 0;
	while (gets(varBuff)) {

		caseNum++;
		if (caseNum > 1)
			printf("\n");

		varLength = 0;
		used = 0;
		memset(vars, 0, sizeof(vars));
		memset(sol, 0, sizeof(sol));
		cToI.empty();

		int varLineLength = strlen(varBuff);

		LP(i, 0, varLineLength)
		{
			if (!isalpha(varBuff[i]))
				continue;

			vars[varLength] = varBuff[i];
			varLength++;
		}

		sort(vars, vars + varLength);

		LP(i, 0, varLength)
			cToI[vars[i]] = i;

		rhConstraints = SAL(varLength);

		char constraintBuff[1000];
		gets(constraintBuff);

		int consLineLen = strlen(constraintBuff);

		for (int i = 0; i < consLineLen; i++) {
			char curChar = constraintBuff[i];

			if (!isalpha(curChar))
				continue;

			int leftIndex = cToI[curChar];
			i++;
			while (!isalpha(constraintBuff[i]))
				i++;

			int rightIndex = cToI[constraintBuff[i]];

			rhConstraints[rightIndex].push_back(leftIndex);
		}

		P_r(0);
	}

	return 0;
}
