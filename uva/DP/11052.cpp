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

//UVa 10354 avoiding your boss
//SSSP
typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 1010;

int mm[MaxN], dd[MaxN], HH[MaxN], MM[MaxN];
bool required[MaxN];
int n;
int high[MaxN][MaxN];

bool tless(int fI, int sI) {
	if (mm[fI] != mm[sI])
		return mm[fI] < mm[sI];

	if (dd[fI] != dd[sI])
		return dd[fI] < dd[sI];
	if (HH[fI] != HH[sI])
		return HH[fI] < HH[sI];

	return MM[fI] < MM[sI];
}

int GetFirstToRecord(int start) {
	int next = start + 1;

	while (tless(next - 1, next)) //same year
	{
		if (required[next])
			return next;
		else if (next == n - 1)
			return next;
		else
			next++;
	}

	//next now points to the start of next year
	while (true) {

		if(tless(start, next))
			return next -1;

		if (required[next])
			return next;

		if (next == n - 1)
			return next;

		if (tless(next, next + 1)) //can silde further?
				{
			if (tless(start, next + 1))
				return next; //can't be smaller than start
			else
				next++;
		} else
			return next; //will go to new year,
	}

	return -1;
}

int FindStart() {

	int toReturn = 0;

	while (true) {
		if (required[toReturn])
			break;

		if (toReturn == n - 1)
			break;

		toReturn++;
	}

	return toReturn;
}

int FindEnd() {

	int toReturn = n - 1;

	while (true) {
		if (required[toReturn])
			break;

		if (toReturn == 0)
			break;

		if (tless(toReturn - 1, toReturn)) //same year?
			toReturn--;
		else
			break;

	}

	return toReturn;
}

int main() {
//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\economic.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		memset(required, false, sizeof(required));

		LP(i, 0, n)
		{
			char buff1[20], buff2[20];
			scanf("%d:%d:%d:%d %s %s", &mm[i], &dd[i], &HH[i], &MM[i], buff1,
					buff2);

			if (buff2[0] == '+')
				required[i] = true;
		}

		LP(i, 0, n)
			high[i][0] = i;

		LP(i, 0, n - 1)
			high[i][1] = GetFirstToRecord(i);

		LP(length, 2, n)
		{
			LP(i, 0, n - length)
			{
				int firstLow = high[i][length - 1];

				high[i][length] = high[firstLow][1];
			}
		}

		//find first required or last in first year, which has lower index
		int startSearch = FindStart();

		if (startSearch == n - 1) {
			if (required[startSearch])
				printf("1\n");
			else
				printf("0\n");

			continue;
		}

		//find last required or first in last year, whichever has higher index
		int endSearch = FindEnd();

		if (endSearch < startSearch)
			endSearch = startSearch;

		LP(length, 0, n)
		{
			if (high[startSearch][length] >= endSearch) {
				printf("%d\n", length + 1);
				break;
			}
		}
	}

	return 0;
}
