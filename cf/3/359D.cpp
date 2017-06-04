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

#define INF 1e9
int const MaxSize = 3e5 + 10;
int n, len[MaxSize][2];
vector<int> a;

void calc(int ti) {
	int curStart = 0;

	LP(i, 0, n)
	{
		if (a[i] % a[curStart]) {

			int segLen = i - curStart - 1;

			LP(j, curStart, i)
			{
				//cout << j << " " << segLen << endl;
				len[j][ti] = segLen;
				segLen--;
			}

			curStart = i;
		}
	}

	int segLen = n - curStart - 1;

	LP(j, curStart, n)
	{
		len[j][ti] = segLen;
		segLen--;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
	{
		int ai;
		cin >> ai;
		a.push_back(ai);
	}

	calc(0);

	reverse(a.begin(), a.end());
	calc(1);

	int maxL = 0;
	vector<int> ans;
	set<int> added;

	LP(i, 0 , n)
	{
		//cout << i << " " << len[i][0] << " " << len[n - 1 - i][1] << endl;

		int segLen = len[i][0] + len[n - 1 - i][1];

		if (segLen > maxL) {
			ans.clear();
			added.clear();
		}

		int startI = i - len[n - 1 - i][1] + 1;

		if (segLen >= maxL) {

			maxL = segLen;
			//cout << i << " " <<  startI - 1 << " " <<  segLen << endl;
			if (!added.count(startI)) {
				ans.push_back(startI);
				added.insert(startI);
			}
		}
	}

	cout << ans.size() << " " << maxL << endl;

	LP(i, 0, ans.size())
		cout << ans[i] << " ";

	return 0;
}
