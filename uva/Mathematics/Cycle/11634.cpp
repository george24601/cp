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

//UVa 944 Happy numbers
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

const int MaxNum = 9999;
bool visited[MaxNum + 1];

int Calc(int num) {
	int sq = num * num;
	sq /= 100;

	return sq % 10000;
}

void Gen_r(int num) {
	if (visited[num])
		return;

	visited[num] = true;

	Gen_r(Calc(num));
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int num;
	while (true) {
		scanf("%d", &num);

		if (num == 0)
			break;

		memset(visited, false, sizeof(visited));
		Gen_r(num);

		int total = 0;
		LPE(i, 0, MaxNum)
		{
			if (visited[i])
				total++;
		}

		printf("%d\n", total);

	}

	return 0;
}
