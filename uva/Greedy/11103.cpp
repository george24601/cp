#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <string>
using namespace std;

typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 110;

int numU;
int numB;
int numL;
char leaves[MaxN];
char binaries[MaxN];

PII leftChild[MaxN][MaxN];

PII DFS_r(int b, int l) {
	if (leftChild[b][l].first >= -1)
		return leftChild[b][l];

	leftChild[b][l] = PII(-1, -1);

	if (b == 0 && l == 1)
		leftChild[b][l] = PII(0, 0);
	else if (b == 0 && l != 1) {

	} else if (l == 0) {

	} else if (b == 1 && l == 2) {
		leftChild[b][l] = PII(0, 1);
	} else if (b == 1 && l != 2) {
	} else {
		LP(lb, 0, b)
		{
			LP(ll, lb+1, l)
			{
				PII leftResult = DFS_r(lb, ll);

				if (leftResult.first < 0)
					continue;

				PII rightResult = DFS_r(b - lb - 1, l - ll);

				if (rightResult.first < 0)
					continue;

				leftChild[b][l] = PII(lb, ll);
				return leftChild[b][l];
			}
		}
	}

	return leftChild[b][l];
}

int bIndex;
int lIndex;
void P_r(int b, int l) {
	if (b == 0 && l == 1) {
		printf("%c", leaves[lIndex]);
		lIndex++;
		return;
	}

	printf("%c", binaries[bIndex]);
	bIndex++;

	P_r(leftChild[b][l].first, leftChild[b][l].second);

	P_r(b - leftChild[b][l].first - 1, l - leftChild[b][l].second);
}

int main() {
//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\D.1.dat", "r", stdin);
//freopen("C:\\Test\\out.txt", "w", stdout);

	LPE(i, 0, 100)
	{
		LPE(j, 0, 100)
			leftChild[i][j] = PII(-2, -2);
	}

	while (true) {
		char buff[MaxN];
		scanf("%s", buff);

		int len = strlen(buff);

		if (len == 1 && buff[0] == '0')
			break;

		numU = 0;
		numB = 0;
		numL = 0;

		LP(i, 0, len)
		{
			if (buff[i] >= 'p' && buff[i] <= 't') {
				leaves[numL] = buff[i];
				numL++;
			} else if (buff[i] == 'N') {
				numU++;
			} else {
				binaries[numB] = buff[i];
				numB++;
			}
		}

		int total = 0;
		int solB = 0;
		int solL = 0;

		LPE(i, 0, numB)
		{
			LPE(j, 0, numL)
			{
				if (DFS_r(i, j).first < 0)
					continue;

				if (i + j > total) {
					solB = i;
					solL = j;
				}

			}
		}

		if (solB == 0 && solL == 0) {
			printf("no WFF possible\n");
		} else {
			LP(i, 0, numU)
				printf("N");

			bIndex = 0;
			lIndex = 0;
			P_r(solB, solL);
			printf("\n");
		}
	}

	return 0;
}
