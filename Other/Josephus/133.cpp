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

//UVa 10354 avoiding your boss
//SSSP
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxSize = 21;

int prev[MaxSize], next[MaxSize];

int n, k, m;

void Print(int num) {
	if (num < 10)
		printf(" ");

	printf(" %d", num);
}

void Unhook(int pos) {
	int newP = prev[pos];
	int newN = next[pos];

	next[newP] = newN;
	prev[newN] = newP;

}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d %d", &n, &k, &m);

		if (n == 0 && k == 0 && m == 0)
			break;

		LP(i, 1, n)
			next[i] = i + 1;

		LPE(i, 2, n)
			prev[i] = i - 1;

		next[n] = 1;
		prev[1] = n;

		int nextPos = 1;
		int prevPos = n;

		int total = n;

		while (total > 0) {

			LP(i, 1,k)
				nextPos = next[nextPos];

			LP(i, 1, m)
				prevPos = prev[prevPos];

			Print(nextPos);
			if (nextPos == prevPos) {

				if (total == 1)
					break;

				int newPrev = prev[nextPos];
				int newNext = next[nextPos];

				Unhook(nextPos);

				nextPos = newNext;
				prevPos = newPrev;

				total -= 1;
			} else {
				Print(prevPos);

				if (total == 2)
					break;

				int newNext, newPrev;

				if (next[nextPos] == prevPos) {

					newNext = next[next[nextPos]];
					newPrev = prev[prev[prevPos]];
				} else {
					newPrev = prev[prevPos];
					newNext = next[nextPos];

				}

				Unhook(nextPos);
				Unhook(prevPos);
				nextPos = newNext;
				prevPos = newPrev;

				total -= 2;
			}

			printf(",");
		}

		printf("\n");
	}

	return 0;
}
