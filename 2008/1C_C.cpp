#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

LL N, n, m, X, Y, Z;
int const MaxN = 500000;
int const MOD = 1000000007;

map<LL, int> valToID;

int tree[MaxN * 3];
int numLeaves;
LL nums[MaxN];

void normalize() {
	int sorted[MaxN];
	LP(i, 0, n)
		sorted[i] = nums[i];

	sort(sorted, sorted + n);

	LP(i, 0, n)
	{
		LL val = sorted[i];
		if (valToID.count(val) == 0) {
			valToID[val] = valToID.size();
		}
	}

	numLeaves = valToID.size();
}

//range on [l, r), notice right is NOT inclusive
LL get(int l, int r) {
	LL res = 0;

	for (l += numLeaves, r += numLeaves; l < r; l >>= 1, r >>= 1) {

		if (l & 1) {
			//left is a right child, need to include this one,
			//and ignore the current parent by going to the next leave node
			res += tree[l];
			l++;
			res %= MOD;
		}

		if (r & 1) {
			//right is right child,
			res += tree[--r]; //it is --r, because r is not inclusive
			res %= MOD;
		}
	}
	return res;
}

void update(int p, int value) {

	for (tree[p += numLeaves] = value; p > 1; p >>= 1){
		tree[p >> 1] = tree[p] + tree[p ^ 1]; //p^1 flips the last bit
		tree[p >> 1] %= MOD;
	}
}

void buildTree() {
	for (int i = numLeaves - 1; i > 0; --i)
		tree[i] = tree[2 * i] + tree[2 * i + 1];
}

int toID(int val) {
	return valToID[val];
}

int main() {
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	cin >> N;

	LPE(cn, 1, N)
	{
		scanf("%lld %lld %lld %lld %lld\n", &n, &m, &X, &Y, &Z);

	//	printf("%d %d %d %d %d\n", n, m, X, Y, Z);

		LL A[MaxN];

		LP(i, 0, m)
			scanf("%ld", &A[i]);

		/*
		LP(i, 0, m)
			printf("%d ", A[i]);

		printf("\n");
		*/

		LP (i, 0, n)
		{
			nums[i] = A[i % m];
			//printf("%d ", nums[i]);
			A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
			//printf("%d\n", A[i % m]);
		}

		valToID.clear();

		/*
		LP(i, 0, m)
			printf("%d ", A[i]);

		printf("\n");
			*/

		/*
		LP(i, 0, n)
			printf("%ld ", nums[i]);
			*/

		normalize();
		memset(tree, 0, sizeof(tree)); //build tree init all to 0

		//printf("numLeaves: %d\n", numLeaves);


		LP(i, 0, n)
		{
			int id = toID(nums[i]);
			int ans = 1;

			int smaller = get(0, id);
			ans += smaller;
			ans %= MOD;

			int same = get(id, id+1);
			ans += same;
			ans %= MOD;

//			printf("%d %d\n", id, ans);

			update(id, ans);
		}

		printf("Case #%d: %d\n", cn, tree[1]);
	}

	return 0;
}
