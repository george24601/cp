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

int const MaxSize = 1020;

int r, c;

char dir[MaxSize][MaxSize];

int fR, fC, tR, tC;

int visited[MaxSize][MaxSize];

bool IsValid(int cr, int cc) {
	if (cr >= r || cr < 0)
		return false;
	if (cc >= c || cc < 0)
		return false;

	return !visited[cr][cc];
}

int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void GetC0(int cr, int cc, vector<PII>& toR) {

	while (IsValid(cr, cc)) {
		toR.push_back(PII(cr, cc));
		visited[cr][cc] = 1;
		int dI = dir[cr][cc] - '0';
		cr += dr[dI];
		cc += dc[dI];
	}
}

void GetC1Neighbors(int cr, int cc, vector<PII>& toR) {

	LP(i, 0, 8)
	{
		if (i == (dir[cr][cc] - '0'))
			continue;

		GetC0(cr + dr[i], cc + dc[i], toR);
	}
}

int Solve() {
	LP(i, 0,r)
		memset(visited[i], 0, sizeof(visited[i]));

	vector<PII> curDist;

	GetC0(fR, fC, curDist);

	LPE(dist, 0, MaxSize * 2)
	{
		vector<PII> nextDist;
		LP(i, 0, curDist.size())
		{
			PII curPoint = curDist[i];
			int cr = curPoint.first;
			int cc = curPoint.second;

			if (cr == tR && cc == tC)
				return dist;

			GetC1Neighbors(cr,cc, nextDist);
		}

		curDist.clear();

		curDist = nextDist;
	}

	return -1;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\B.2.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	scanf("%d %d", &r, &c);

	LP(i, 0, r)
		scanf("%s", dir[i]);

	int numC;
	scanf("%d", &numC);

	LPE(i, 1, numC)
	{
		scanf("%d %d %d %d", &fR, &fC, &tR, &tC);
		fR--;
		fC--;
		tR--;
		tC--;
		printf("%d\n", Solve());
	}

	return 0;
}
