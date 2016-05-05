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
using namespace std;

//UVa 10591 Happy number
//cycle finding
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

int n, k;
int maxV;
map<int, bool> visited;

int Calc(int curNum) {
	L sq = ((L) curNum);
	sq = sq * sq;

	L maxVal = pow(10, n);

	while (sq >= maxVal)
		sq = sq / 10;

	return sq;
}

void P_r() {

	int curNum = k;

	while (!visited[curNum]) {

		visited[curNum] = true;

		int next = Calc(curNum);

		if (next == curNum || next == maxV)
			return;
		else if (next > maxV)
			maxV = next;

		curNum = next;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d %d", &n, &k);
		visited.clear();
		maxV = k;

		P_r();

		printf("%d\n", maxV);
	}

	return 0;
}
