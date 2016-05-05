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

const int MaxSize = 30000;
int parent[MaxSize];
int size[MaxSize];

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

	parent[Max(aP, bP)] = Min(aP, bP);
	size[Min(aP, bP)] = size[aP] + size[bP];
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		int n, m;
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0)
			break;

		LP(i, 0, n)
		{
			parent[i] = i;
			size[i] = 1;
		}

		LP(i, 0, m)
		{
			int k;
			scanf("%d", &k);

			if (k == 0)
				continue;
			int first = 0;

			scanf("%d", &first);

			LP(j, 1, k)
			{
				int member;
				scanf("%d", &member);

				Union(first, member);
			}

		}

		printf("%d\n", size[0]);

	}

	return 0;
}
