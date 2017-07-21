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
#define Ep 1e-13

#define INF 2e9 + 20
int const MaxSize = 1e6 + 10;
int n;
string t[MaxSize];
vector<PII> appears;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
	{
		int k;
		cin >> t[i] >> k;

		LP(j, 0, k)
		{
			int xij;
			cin >> xij;
			xij--;
			appears.push_back(PII(xij, i));
		}
	}

	sort(appears.begin(), appears.end());

	int toFillI = 0;

	LP(i, 0, appears.size())
	{
		int startI = appears[i].first;
		while (toFillI < startI) {
			cout << 'a';
			toFillI++;
		}

		string& sToFill = t[appears[i].second];

		while (toFillI < startI + sToFill.size()) {
			cout << sToFill[toFillI - startI];
			toFillI++;
		}
	}

	return 0;
}
