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

const int INF = 2147483647;

const int MaxSize = 60;

map<char, int> nameToID;

void Process(int n, bool dist[][MaxSize]) {
	LP(k, 0 , n)
	{
		LP(i, 0, n)
		{
			LP(j, 0, n)
			{
				bool old = dist[i][j];
				bool firstNew = dist[i][k];
				bool secondNew = dist[k][j];

				dist[i][j] = old || (firstNew && secondNew);
			}
		}
	}
}

int GetID(char c) {
	if (nameToID.count(c) == 0) {
		int id = nameToID.size();
		nameToID[c] = id;
	}

	return nameToID[c];
}

void Read(bool firstDist[][MaxSize]) {
	int firstM = 0;
	scanf("%d", &firstM);

	LP(i, 0, MaxSize)
	{
		memset(firstDist[i], false, sizeof(firstDist[i]));

		firstDist[i][i] = true;
	}

	LP(i, 0, firstM)
	{
		char fb[10];
		char sb[10];
		scanf("%s %s", fb, sb);

		firstDist[GetID(fb[0])][GetID(sb[0])] = true;
	}
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum;
	scanf("%d", &caseNum);

	LPE(cn,1, caseNum)
	{
		if (cn > 1)
			printf("\n");

		nameToID.clear();

		bool firstDist[MaxSize][MaxSize];
		Read(firstDist);

		bool secondDist[MaxSize][MaxSize];
		Read(secondDist);
		int n = nameToID.size();
		Process(n, firstDist);
		Process(n, secondDist);

		LP(i, 0, n)
		{
			LP(j, 0, n)
			{
				if (firstDist[i][j] != secondDist[i][j]) {
					printf("NO\n");
					goto Next;
				}

			}
		}

		printf("YES\n");

		Next: continue;
	}

	return 0;
}
