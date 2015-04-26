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

const int MaxN = 25;

int n;
vector<int> blocks[MaxN];

/*
 probably needs an array to track horizontal address
 find the current block's horizotal + vertical position
 everything above the vertical, return to init
 probably need a list of vectors
 */

PII Find(int block) {
	LP(hori,0, n)
	{
		LP(verti, 0, blocks[hori].size())
		{
			if (blocks[hori][verti] == block)
				return PII(hori, verti);
		}
	}

	return PII(-1, -1);
}

void ReturnToInit(PII curPos) {
	int hori = curPos.first;
	int verti = curPos.second;

	int startIndex = blocks[hori].size() - 1;

	for (int i = startIndex; i > verti; i--) {
		int blockAbove = blocks[hori][i];
		blocks[blockAbove].push_back(blockAbove);
		blocks[hori].pop_back();
	}
}

/*
 * find current block's hori + verti position,
 * add everything to the end new block
 */
void PutOver(PII fromPos, PII toPos) {

	int fromSize = blocks[fromPos.first].size();

	LP(i, fromPos.second, fromSize)
		blocks[toPos.first].push_back(blocks[fromPos.first][i]);

	LP(i, fromPos.second, fromSize)
		blocks[fromPos.first].pop_back();
}

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);

	scanf("%d", &n);

	LP(i, 0, n)
		blocks[i].push_back(i);

	char buff[100];

	while (true) {
		scanf("%s", buff);

		if (strcmp(buff, "quit") == 0)
			break;

		bool returnFirst = (strcmp(buff, "move") == 0);
		int from;
		scanf("%d", &from);

		scanf("%s", buff);
		bool returnSecond = (strcmp(buff, "onto") == 0);
		int to;
		scanf("%d", &to);

		PII fromPos = Find(from);
		PII toPos = Find(to);
		if (fromPos.first == toPos.first)
			continue;

		if (returnFirst)
			ReturnToInit(fromPos);
		if (returnSecond)
			ReturnToInit(toPos);

		PutOver(fromPos, toPos);
	}

	LP(i, 0, n)
	{
		printf("%d:", i);

		LP(j, 0, blocks[i].size())
			printf(" %d", blocks[i][j]);

		printf("\n");
	}

	return 0;
}
