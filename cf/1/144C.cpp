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

/*
 keep track of total missing chars, and total ?s

 on introducing a new char
 cnt[c]++;

 introduce a newchar
 cnt[c] ++, if cnt[c] <= tarcnt[c], deficit--
 delete the curhead
 cnt[c] --, if cnt[c] < tarcn[c], deficit++;

 is total deficit = total # of ?s, if is, then we are good

 */

string s, p;

int tar[26];
int cur[26];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> s >> p;

	memset(tar, 0, sizeof(tar));
	memset(cur, 0, sizeof(cur));

	int pl = p.length();
	LP(i, 0, pl)
		tar[p[i] - 'a']++;

	int numQ = 0;
	int deficit = pl;
	int ans = 0;

	LP(i, 0, s.length())
	{
		char c = s[i];
		if (c == '?') {
			numQ++;
		} else {
			int ci = c - 'a';
			cur[ci]++;

			if (cur[ci] <= tar[ci])
				deficit--;
		}

		int rmi = i - pl;

		if (rmi >= 0) {
			char dc = s[rmi];

			if (dc == '?') {
				numQ--;
			} else {
				int ci = dc - 'a';
				cur[ci]--;

				if (cur[ci] < tar[ci])
					deficit++;
			}
		}

		//cout << i << " " << deficit << " " << numQ << endl;

		if (deficit == numQ)
			ans++;
	}

	cout << ans << endl;

	return 0;
}
