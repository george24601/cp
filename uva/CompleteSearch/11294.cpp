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

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

int const MaxSize = 1000;

//no h and w sit on the same side
//bride see both members of special pair
//find people on the same side as bride

int n, np;

SAL adj;

int used[MaxSize];

void Print() {
	vector<int> ids;
	LP(i, 1, n)
	{
		if (used[i] == 0)
			ids.push_back(i);
		if (used[i + n] == 0)
			ids.push_back(i + n);
	}

	LP(i, 0, ids.size())
	{
		int id = ids[i];

		if (i > 0)
			printf(" ");

		if (id >= n)
			printf("%d%c", id - n, 'h');
		else
			printf("%d%c", id, 'w');
	}

	printf("\n");
}

bool sameSide(int id) {
	vector<int> neighbors = adj[id];

	LP(i, 0, neighbors.size())
	{
		int neighbor = neighbors[i];

		if (used[neighbor] == used[id])
			return true;
	}

	return false;
}

bool TryP(int p) {
	if (p >= n) {
		Print();
		return true;
	}

	used[p] = 1;
	used[p + n] = 0;

	if (!sameSide(p)) {
		bool done = TryP(p + 1);
		if (done)
			return done;
	}

	used[p] = 0;
	used[p + n] = 1;

	if (!sameSide(p + n)) {
		bool done = TryP(p + 1);
		if (done)
			return done;
	}
	used[p] = -1;
	used[p + n] = -1;

	return false;
}

int StrToId(string s) {
	string numS = s.substr(0, s.length() - 1);

	int base = atoi(numS.c_str());

	if (s[s.length() - 1] == 'h')
		base += n;

	return base;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\E.1.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		cin >> n >> np;

		if (n == 0 && np == 0)
			break;

		memset(used, -1, sizeof(used));
		used[0] = 0;
		used[n] = 1;

		adj = SAL(2 * n);

		LP(i, 0, np)
		{
			string first, second;
			cin >> first >> second;

			int firstId = StrToId(first);
			int secondId = StrToId(second);

			adj[firstId].push_back(secondId);
			adj[secondId].push_back(firstId);
		}

		bool hasResult = TryP(1);

		if (!hasResult)
			printf("bad luck\n");
	}

	return 0;
}
