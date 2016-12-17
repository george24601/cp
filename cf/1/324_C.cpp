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
 */

int n, t;
string a, b;

int move(char c, int step) {
	return 'a' + ((c - 'a' + step) % 26);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> t;
	cin >> a >> b;

	int existingDiff = 0;

	LP(i, 0, n)
	{
		if (a[i] != b[i])
			existingDiff++;
	}

	int minDiff = (existingDiff + 1) / 2;

	if (t < minDiff) {
		printf("-1\n");
		return 0;
	}

	string ans;

	if (t >= existingDiff) {

		int commonChange = t - existingDiff;

		LP(i, 0, n)
		{
			char c;
			if (a[i] == b[i]) {

				if (commonChange) {
					commonChange--;
					c = move(a[i], 1);
				} else {
					c = a[i];
				}
			} else {
				int step = 1;

				while (move(a[i], step) == b[i])
					step++;

				c = move(a[i], step);
			}

			ans.push_back(c);
		}
	} else {
		int delta = existingDiff - t;

		int firstPartDelta = delta;
		int secondPartDelta = delta;

		LP(i, 0, n)
		{
			char c;

			if (a[i] == b[i]) {
				c = a[i];
			} else {
				if (firstPartDelta) {
					firstPartDelta--;
					c = a[i];
				} else if (secondPartDelta) {
					secondPartDelta--;
					c = b[i];
				} else {

					int step = 1;

					while (move(a[i], step) == b[i])
						step++;

					c = move(a[i], step);

				}
			}

			ans.push_back(c);
		}
	}

	cout << ans << endl;

	return 0;
}

