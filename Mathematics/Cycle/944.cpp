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

const int MaxNum = 99999;
int happy[MaxNum + 1];
int happySteps[MaxNum + 1];

int sortNum(int num) {

	int buff[6];

	int length = 0;

	int curNum = num;

	while(curNum > 0)
	{
		buff[length] = curNum % 10;
		length++;
		curNum = curNum/ 10;
	}

	sort(buff, buff + length);

	int toReturn = 0;

	LP(i, 0, length - 1)
	{
		toReturn += (buff[i]);
		toReturn *= 10;
	}

	toReturn += (buff[length - 1]) ;

	return toReturn;
}

int GetNext(int num) {
	int remaining = num;
	int toReturn = 0;
	while (remaining > 0) {
		toReturn += (remaining % 10) * (remaining % 10);
		remaining /= 10;
	}

	return toReturn;
}

void Happy(int num) {
	int curNum = num;

	int happyStep = 1;

	bool visited[MaxNum + 1];
	memset(visited, false, sizeof(visited));

	while (true) {
		if (visited[curNum]) {
			happy[num] = 2;
			return;
		} else if (curNum == 1) {
			happy[num] = 1;
			happySteps[num] = happyStep;
			return;
		} else {
			visited[curNum] = true;
			happyStep++;
			curNum = GetNext(curNum);
		}
	}
}

void PreC() {
	happy[1] = 1;
	happySteps[1] = 1;

	LPE(num, 2, MaxNum)
	{
		if (happy[num] > 0)
			continue;

		int sortedNum = sortNum(num);

		if (happy[sortedNum] > 0) {
			happy[num] = happy[sortedNum];
			happySteps[num] = sortedNum == 1 ? 2 : happySteps[sortedNum];
		} else
			Happy(num);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	memset(happy, 0, sizeof(happy));
	memset(happySteps, 0, sizeof(happySteps));
	PreC();

	int l, h;
	int caseNum = 0;
	while (scanf("%d %d", &l, &h) == 2) {
		caseNum++;

		if (caseNum > 1)
			printf("\n");

		LPE(num, l, h)
		{
			if (happy[num] == 1)
				printf("%d %d\n", num, happySteps[num]);
		}
	}

	return 0;
}
