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
#define INF 2000000000
#define Ep 1e-8

/*
 He does not visit

 start = smallest of biggest index to appear
 end = biggest of smallest index to appear
 */

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> s;

	set<char> totalUnique;

	LP(i, 0, n)
		totalUnique.insert(s[i]);

	int targetSize = totalUnique.size();

	int curMin = n;

	int curStart = 0;

	map<char, int> curSaved;

	LP(i, 0, n)
	{
		char c = s[i];

		curSaved[c]++;

		while (curStart < i) {

			char hc = s[curStart];

			if (curSaved[hc] > 1) {
				curSaved[hc]--;
				curStart++;
			} else {
				break;
			}
		}

		if (curSaved.size() == targetSize) {
			curMin = min(curMin, i - curStart + 1);
		//	cout << curStart << " " << i << endl;
		}
	}

	cout << curMin << endl;

	return 0;
}

