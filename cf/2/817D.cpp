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
int const MaxSize = 1e6 + 10;
int n;

vector<int> smallToLeft(vector<int> a) {
	vector<int> ans(n);
	stack<PII> soFar;

	LP(i, 0, n)
	{
		while (soFar.size() && soFar.top().first > a[i]) {
			soFar.pop();
		}

		if (soFar.size()) {
			ans[i] = soFar.top().second;
		} else {
			ans[i] = -1;
		}

		soFar.push(PII(a[i], i));
	}

	return ans;
}

vector<int> smallToRight(vector<int> a) {
	vector<int> ans(n);
	stack<PII> soFar;

	for (int i = n - 1; i >= 0; i--) {
		while (soFar.size() && soFar.top().first >= a[i]) {
			soFar.pop();
		}

		if (soFar.size()) {
			ans[i] = soFar.top().second;
		} else {
			ans[i] = -1;
		}

		soFar.push(PII(a[i], i));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	vector<int> a;
	vector<int> negA;

	LP(i, 0, n)
	{
		int num;
		cin >> num;

		a.push_back(num);
		negA.push_back(-num);
	}

	vector<int> smallToLeftI = smallToLeft(a);

	vector<int> bigToLeftI = smallToLeft(negA);

	vector<int> smallToRightI = smallToRight(a);
	vector<int> bigToRightI = smallToRight(negA);

	LL ans = 0;
	LP(i, 0, n)
	{
		LL maxLeftL = bigToLeftI[i] < 0 ? i : i - bigToLeftI[i] - 1;

		LL maxRightL = bigToRightI[i] < 0 ? n - 1 - i : bigToRightI[i] - i - 1;

		LL times = maxLeftL * maxRightL + maxLeftL + maxRightL + 1;

		LL minLeftL = smallToLeftI[i] < 0 ? i : i - smallToLeftI[i] - 1;

		LL minRightL =
				smallToRightI[i] < 0 ? n - 1 - i : smallToRightI[i] - i - 1;

		times -= minLeftL * minRightL + minLeftL + minRightL + 1;

	//	cout << maxLeftL << " " << maxRightL << " " << minLeftL << " "
	//			<< minRightL << endl;

		ans += times * a[i];
	}

	cout << ans;

	return 0;
}
