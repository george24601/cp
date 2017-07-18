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
int n, completeI;
char s[2 * MaxSize];
string t[MaxSize];
vector<PII> appears;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/george/A_1.in", "r", stdin);

	memset(s, '?', sizeof(s));

	cin >> n;

	LP(i, 0, n)
	{
		int k;
		cin >> t[i] >> k;

		LP(j, 0, k)
		{
			int xij;
			cin >> xij;
			appears.push_back(PII(xij, i));
		}
	}

	sort(appears.begin(), appears.end());

	int nextI = 0;

	LP(ai, 0, appears.size())
	{
		int sI = appears[ai].first;
		int tI = appears[ai].second;

		int fillStart = max(sI, nextI);

		LP(i,fillStart, sI + t[tI].size())
		{
			s[i] = t[tI][i - sI];
		}

		nextI = max(nextI, (int) (sI + t[tI].size()));
	}

	for (int i = MaxSize - 1; i >= 0; i--) {
		if (s[i] != '?') {
			LPE(j, 1, i)
			{
				if (s[j] == '?') {
//					cout << endl;
					cout << 'a';
				} else
					cout << s[j];

			}

			break;
		}
	}

	return 0;
}
