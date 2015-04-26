#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

//UVa 1197: War
//UnionFind

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 10000;
int parent[MaxSize];
int balance[MaxSize];

int Find(int a) {
	if (parent[a] != a)
		parent[a] = Find(parent[a]);

	return parent[a];
}

void Union(int a, int b) {

	int aP = Find(a);
	int bP = Find(b);

	if (aP == bP)
		return;

	parent[aP] = bP;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int N = 0;
	scanf("%d", &N);

	LPE(caseNum, 1, N) {
		int n, m;
		scanf("%d %d", &n, &m);

		LP(i, 0, n)
		{
			parent[i] = i;
			scanf("%d", &balance[i]);
		}

		LP(i, 0, m)
		{
			int first = 0, second = 0;
			scanf("%d %d", &first, &second);

			Union(first, second);
		}

		LP(i, 0, n)
		{
			int root = Find(i);

			if (root == i)
				continue;

			balance[root] += balance[i];
		}

		LP(i, 0, n)
		{
			int root = Find(i);

			if (root == i && balance[i] != 0)
				goto Bad;
		}

		printf("POSSIBLE\n");
		continue;
		Bad:
		printf("IMPOSSIBLE\n");

	}

	return 0;
}
