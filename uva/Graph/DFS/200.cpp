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
using namespace std;

//UVa 200 Rare order
//topological sort
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

char input[5000][21];
int inSize;
bool visited[26];
vector<int> order;

bool adj[27][27];

void BuildEdge(int first, int second) {
	int length = Min(strlen(input[first]), strlen(input[second]));

	LP(i, 0, length)
	{
		char firstC = input[first][i];
		char secondC = input[second][i];

		if (firstC == secondC)
			continue;

		adj[firstC - 'A'][secondC - 'A'] = true;
		return;
	}
}

void P_r(int cIndex) {
	if (visited[cIndex])
		return;
	else
		visited[cIndex] = true;

	LP(i, 0, 27)
	{
		if (adj[cIndex][i])
			P_r(i);

	}

	order.push_back(cIndex);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	inSize = 0;
	memset(visited, false, sizeof(visited));

	LP(i, 0, 27)
		memset(adj[i], false, sizeof(adj[i]));

	while (true) {

		scanf("%s", input[inSize]);

		if (strlen(input[inSize]) == 1 && input[inSize][0] == '#')
			break;

		inSize++;
	}

	LP(firstIndex, 0, inSize)
	{
		LP(secondIndex, firstIndex + 1, inSize)
			BuildEdge(firstIndex, secondIndex);
	}

	P_r(input[0][0] - 'A');

	for (int i = order.size() - 1; i >= 0; i--)
		printf("%c", order[i] + 'A');

	printf("\n");

	return 0;
}
