#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

#define INF 2000000100

//LL const LINF = 1e18;
/*
 possible(nr, ng, nb, fc) =
 {

 for each different color combo
 possible(nr, nq, nb, fc) try opinion 1

 for each color try opiton 2

 }

 3 * 8 * 10^6 * 3
 */

int const MaxSize = 210;

int good[MaxSize][MaxSize][MaxSize][3];

int possible(int nr, int ng, int nb, int fc) {
	if (nr < 0 || ng < 0 || nb < 0)
		return false;

	if ((nr + ng + nb) == 1) {

		if (nb && (fc == 0))
			return true;
		else if (ng && (fc == 1))
			return true;
		else if (nr && (fc == 2))
			return true;

		return false;
	}

	//cout << nr << " " << ng << " " << nb << endl;

	if (good[nr][ng][nb][fc] >= 0) {

		//cout << nr << " " << ng << " " << nb << " " << good[nr][ng][nb][fc]		<< endl;
		return good[nr][ng][nb][fc];
	}

	bool ans = false;

	ans = ans || possible(nr - 1, ng - 1, nb + 1, fc);
	ans = ans || possible(nr - 1, ng + 1, nb - 1, fc);
	ans = ans || possible(nr + 1, ng - 1, nb - 1, fc);

	if (nr >= 2)
		ans = ans || possible(nr - 1, ng, nb, fc);

	if (ng >= 2)
		ans = ans || possible(nr, ng - 1, nb, fc);

	if (nb >= 2)
		ans = ans || possible(nr, ng, nb - 1, fc);

	return good[nr][ng][nb][fc] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;
	string s;

	cin >> n >> s;

	int nr = 0, ng = 0, nb = 0;
	LP(i, 0, n)
	{
		if ('R' == s[i])
			nr++;
		else if ('G' == s[i])
			ng++;
		else
			nb++;
	}

	LPE(i, 0, n)
	{
		LPE(j, 0, n)
		{
			LPE(k, 0, n)
			{
				memset(good[i][j][k], -1, sizeof(good[i][j][k]));
			}

		}
	}

	if (possible(nr, ng, nb, 0))
		cout << "B";

	if (possible(nr, ng, nb, 1))
		cout << "G";

	if (possible(nr, ng, nb, 2))
		cout << "R";

	return 0;
}
