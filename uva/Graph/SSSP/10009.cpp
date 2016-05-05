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

//UVa 10009 All Roads Lead Where?
//BFS
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

const int MaxSize = 30;

int parent[MaxSize];

void Root_r(int node, int* path, int& size) {
	int pNode = parent[node];

	if (pNode != node) {
		Root_r(pNode, path, size);
		size++;
	}

	path[size] = node;
}

void Print(int* first, int firstSize, int* second, int secondSize) {

	int minSize = Min(firstSize, secondSize);

	int firstDiff = 0;

	while (firstDiff < minSize) {
		if (first[firstDiff] != second[firstDiff])
			break;

		firstDiff++;
	}

	for (int i = firstSize - 1; i >= firstDiff; i--)
		printf("%c", first[i] + 'A');

	LP(i, firstDiff - 1, secondSize)
		printf("%c", second[i] + 'A');
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		int M, N;
		scanf("%d %d", &M, &N);

		memset(parent, 0, sizeof(parent));

		LP(i, 0, M)
		{
			char first[1000];
			char second[1000];
			scanf("%s %s", first, second);
			int firstID = first[0] - 'A';
			int secondID = second[0] - 'A';

			parent[secondID] = firstID;
		}

		parent[('R' - 'A')] = ('R' - 'A');

		if (caseNum > 1)
			printf("\n");

		LP(i, 0, N)
		{
			char first[1000];
			char second[1000];
			scanf("%s %s", first, second);
			int firstID = first[0] - 'A';

			int pathF[MaxSize];
			int sPF = 0;

			Root_r(firstID, pathF, sPF);

			int secondID = second[0] - 'A';
			int pathS[MaxSize];
			int sPS = 0;
			Root_r(secondID, pathS, sPS);

			Print(pathF, sPF + 1, pathS, sPS + 1);
			printf("\n");
		}
	}

	return 0;
}
