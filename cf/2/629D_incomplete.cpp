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

int const MaxSize = 100010;
map<LL, int> valToID;

LL tree[MaxSize * 3];
int numLeaves;

//range on [l, r), notice right is NOT inclusive
LL get(int l, int r) {
	LL res = 0;

	for (l += numLeaves, r += numLeaves; l < r; l >>= 1, r >>= 1) {

		if (l & 1) {
			//left is a right child, need to include this one,
			//and ignore the current parent by going to the next leave node
			res += tree[l];
			l++;
		}

		if (r & 1) {
			//right is right child,
			res += tree[--r]; //it is --r, because r is not inclusive
		}
	}
	return res;
}

//p is value of a LEAF node in [0, numLeaves)
void update(int p, LL value) {

	for (tree[p += numLeaves] = value; p > 1; p >>= 1) {
		tree[p >> 1] = tree[p] + tree[p ^ 1]; //p^1 flips the last bit
	}
}

void buildTree() {
	for (int i = numLeaves - 1; i > 0; --i)
		tree[i] = tree[2 * i] + tree[2 * i + 1];
}

int n, iToOI[MaxSize];
pair<LL, int> r2h[MaxSize];
vector<LL> sortedVs;

int getSortedI(int i) {
	return iToOI[i];
}

void calcOrder() {
	sort(r2h, r2h + n);
	LP(i, 0, n)
	{
		LL curV = r2h[i].first;

		if (i == 0 || curV > sortedVs[sortedVs.size() - 1]) {
			sortedVs.push_back(curV);
		}

		iToOI[r2h[i].second] = sortedVs.size() - 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n;

	LP(i, 0, n)
	{
		LL r, h;
		cin >> r >> h;
		r2h[i] = pair<LL, int>(r * r * h, i);
	}

	calcOrder();
	numLeaves = sortedVs.size();

	LP(i, 0, n)
	{
		int si = getSortedI(i);

		LL bestPrev = get(0, si);

		LL curTry = bestPrev + sortedVs[si];

		LL curBest = get(si, si + 1);

		if (curBest < curTry) {
			cout << i << " " << si << " " << curBest << " " << curTry << endl;
			update(si, curTry);
		}
	}

	double ans = 3.14159265358979323846 * get(0, numLeaves);
	cout << setprecision(10) << fixed;
	cout << ans << endl;
}
