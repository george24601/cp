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

int const MaxSize = 210;
string s;
stack<PII> balance;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> s;

	int curBest = 0;
	int bestCount = 1;

	LP(i, 0,s.length())
	{
		int c = s[i] == '(';
		if (!balance.size()) {
			balance.push(PII(c, i));
			continue;
		}

		PII top = balance.top();

		if (top.first && !c) {
			balance.pop();

			int subLen = i + 1;

			if(balance.size())
				subLen = subLen  - balance.top().second - 1;

			if (subLen > curBest) {
				curBest = subLen;
				bestCount = 1;
			} else if (subLen == curBest)
				bestCount++;

			//cout << i << " " << top.first << " " << c << endl;

		} else {
			balance.push(PII(c, i));
		}
	}

	cout << curBest << " " << bestCount << endl;

	return 0;
}

