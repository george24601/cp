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
 because base 7
 only 0 - 7 possible

 int ways(useDigits, int maxN){


 }

 if 0 not used

 based on n, we know # of digits hours will have
 if nd > 7, ans will be 0,

 other wise, the we need to generate all subset with size nd, on different perms, and filter out those > maxN

 so generate all 8! combos,
 for each combo,
 take the nd



 */

int const MaxSize = 110;
int nums[MaxSize];
int correct[MaxSize];

vector<int> partial;
int nd, md;
int res;

int const Seven = 7;
int used;
LL n, m;

LL toNum(int from, int to) {
	LL res = 0;
	LP(i, from, to)
	{
		res *= Seven;
		res += partial[i];
	}

	return res;
}

void gen() {
	if (partial.size() == nd + md) {
		if (toNum(0, nd) < n && toNum(nd, nd + md) < m) {

			res++;

			/*
			cout << "testN: " << toNum(0, nd) << endl;

			LP(i, 0, partial.size())
				cout << partial[i] << " ";
			cout << endl;
			*/
		}

		return;
	}

	LP(i, 0, Seven)
	{
		if ((used >> i) & 1)
			continue;

		//cout << "used "<< used << " append " << i << endl;

		int toRevert = used;

		used = used | (1 << i);

		partial.push_back(i);

		gen();

		partial.pop_back();

		//cout << "unappend " << i << endl;

		used = toRevert;
	}
}

int numD(LL num) {
	LL digit = 1;
	int curMax = Seven;

	while (curMax < num) {
		curMax *= (LL) Seven;
		digit++;
	}

	return digit;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> m;

	nd = numD(n);
	md = numD(m);

	if (nd + md > Seven) {
		cout << 0 << endl;
		return 0;
	}

	used = 0;
	res = 0;
	gen();

	assert(0 == used);

	cout << res << endl;
	return 0;
}

