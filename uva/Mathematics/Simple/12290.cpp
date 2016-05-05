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

//UVa 12290 Counting Game
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

const int MaxSize = 2000000;

int n, m, k;

bool GoodNum(L num) {
	if (num % 7 == 0)
		return true;

	while (num >= 7) {
		if (num % 10 == 7)
			return true;
		else
			num = num / 10;
	}

	return false;
}
void Process_r() {

	int count = 0;
	L curNum = 0;

	while (true) {
		LPE(i, 1, n)
		{
			curNum++;
			if (i != m)
				continue;

			if (GoodNum(curNum)) {
				count++;
				if (count == k) {
					printf("%llu\n", curNum);
					return;
				}
			}
		}

		for (int i = n - 1; i > 1; i--) {

			curNum++;
			if (i != m)
				continue;

			if (GoodNum(curNum)) {
				count++;

				if (count == k) {
					printf("%llu\n", curNum);
					return;
				}
			}
		}
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d %d", &n, &m, &k);

		if (n == 0 && m == 0 && k == 0)
			break;

		Process_r();
	}

	return 0;
}

