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
//typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e17
/*

 */

int const MaxSize = 1e3 + 1;

int m, n;
string s;

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> m >> s;
	n = s.size();

	for (char lastC = 'a'; lastC <= 'z'; lastC++) {
		//cout << "nextC:" << lastC << endl;
		vector<int> cnt(26);
		int segBeginI = -1;
		int rightmostI = -10;

		bool enough = true;
		LP(i, 0, s.size())
		{
			if (s[i] < lastC) {
				segBeginI = i;

				cnt[s[i] - 'a']++;
			} else if (s[i] == lastC)
				rightmostI = i;

			if (i - segBeginI == m) {
				if (rightmostI >= segBeginI) {
					cnt[s[rightmostI] - 'a']++;

					segBeginI = rightmostI;
					rightmostI = -1;

				} else {
					enough = false;
					break;
				}
			}
		}

		if (enough) {
			LP(i, 0, 26)
			{
				LP(j, 0, cnt[i])
					cout << (char) ('a' + i);
			}

			break;
		}
	}
}
