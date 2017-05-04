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
#define Ep 1e-7

#define INF 2000000000

/*

 */

int const MaxSize = 2010;
int n, m, a[MaxSize];
int cnt[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m;

	memset(cnt, 0, sizeof(cnt));

	LP(i, 0, n)
	{
		cin >> a[i];

		if (1 <= a[i] && a[i] <= m)
			cnt[a[i]]++;
	}

	int target = n / m;

	queue<int> toInsert;

	LPE(band, 1, m)
	{
		LP(c, cnt[band], target)
		//cout << band << endl;
			toInsert.push(band);
	}

	int total = 0;

	for (int i = 0; i < n && toInsert.size(); i++) {
		int band = a[i];
		if (band < 1 || band > m) {
			a[i] = toInsert.front();
			toInsert.pop();
			cnt[a[i]]++;
			total++;

		} else if (cnt[band] > target + 1) {
			a[i] = toInsert.front();
			toInsert.pop();
			cnt[a[i]]++;
			cnt[band]--;
			total++;
		}
	}

	//cout << "first round : " << endl;

	for (int i = 0; i < n && toInsert.size(); i++) {
		int band = a[i];

		if (band < 1 || band > m)
			continue;

		if (cnt[band] > target) {
			a[i] = toInsert.front();
			toInsert.pop();
			cnt[a[i]]++;
			cnt[band]--;
			total++;
		}
	}

	cout << target << " " << total << endl;

	LP(i, 0, n)
		cout << a[i] << " ";

	return 0;
}
