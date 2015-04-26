#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

//UVa 10685: Nature
//UnionFind

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

int parent[5000];
int size[5000];

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

	size[bP] += size[aP];
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		int C, R;
		scanf("%d %d", &C, &R);

		if (C == 0 && R == 0)
			break;
		map<string, int> nameToIndex;

		char name[40];

		LP(i, 0, C)
		{
			scanf("%s", name);
			nameToIndex[string(name)] = i;

			parent[i] = i;
			size[i] = 1;
		}

		char f[40];
		char s[40];

		LP(i, 0, R)
		{
			scanf("%s %s", f, s);

			Union(nameToIndex[string(f)], nameToIndex[string(s)]);
		}

		int maxVal = 0;

		LP(i, 0, C)
			maxVal = Max(maxVal, size[i]);

		printf("%d\n", maxVal);
	}

	return 0;
}
