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

int T, K, n;
int const MaxK = 1000010;
bitset<MaxK> occupied;

class SegTree {
private:
	int start;
	int end;

	SegTree() {
		start = -1;
		end = -1;
		left = NULL;
		right = NULL;
	}

public:
	SegTree* left;
	SegTree* right;

	int uo;

	SegTree(int s, int e, SegTree* l, SegTree* r, int c) {
		start = s;
		end = e;
		left = l;
		right = r;

		uo = c;
	}

	~SegTree() {
		delete left;
		delete right;
	}

	void mark(int i) {
		assert(i >= start && i <= end);
		uo--;

		if (left == NULL)
			return;

		assert(left != NULL && right != NULL);

		if (i <= left->end)
			left->mark(i);
		else
			right->mark(i);
	}

	//how many unoccupied do we have to the right, excluding i
	int free(int i) {
		assert(i >= start && i <= end);

		if (left == NULL) {
			assert(right == NULL);
			assert(i == start && i == end);
			return 0;
		}

		assert(right != NULL);

		if (i > left->end)
			return right->free(i);
		else {
			int leftFree = left->free(i);

			return leftFree + right->uo;
		}
	}

	/*
	 to answer: given index i, what is the index j , which has k unoccupied between i and j, excluding i
	 our tree is a binary tree, i.e., either both children or 0
	 */
	int Q(int i, int k) {
		//printf("%d %d %d %d %d\n", i, k, start, end, uo);

		assert(i >= start && i <= end && uo >= k);

		if (left == NULL) {
			assert(right == NULL);
			assert(k == 0);
			assert(i == start && i == end);
			assert(!occupied[start]);
			return start;
		}

		assert(right != NULL);

		if (i > left->end) {
			int rightFree = right->free(i);

			if (rightFree >= k)
				return right->Q(i, k); //right alone is enought

			int lsOccupied = occupied[left->start] ? 0 : 1;
			int remainingK = k - rightFree - lsOccupied;

			assert(remainingK <= left->uo - lsOccupied);
			return right->Q(left->start, remainingK);

		} else {
			int leftFree = left->free(i);

			//printf("%d\n", leftFree);

			if (leftFree >= k)
				return left->Q(i, k); //left tree alone is enough

			int rsOccupied = occupied[right->start] ? 0 : 1;
			int remainingK = k - leftFree - rsOccupied;

			assert(remainingK <= right->uo - rsOccupied); //left + right alone is enough
			return right->Q(right->start, remainingK);
		}
	}
};

//Used during init only, should NOT be called afterwards
//Note: by this logic, a node has either 2 nodes or none
SegTree* BuildTree(int start, int end) {
	if (start == end) {
		return new SegTree(start, end, NULL, NULL, 1);
	}

	int mid = (start + end) / 2;

	SegTree* l = BuildTree(start, mid);

	SegTree* r = BuildTree(mid + 1, end);

	//merge val here
	return new SegTree(start, end, l, r, end - start + 1);
}

int const Maxn = 100;
int qs[Maxn];
int ans[MaxK];

void process() {
	SegTree * tree = BuildTree(1, K);

	int cur = 1;
	occupied.flip(cur);
	ans[1] = cur;
	tree->mark(cur);

	LPE(val, 2, K)
	{
		int free = tree->free(cur);
		int actualVal = val;

		if (free < actualVal){
			//printf("%d %d %d %d\n", cur, free, actualVal, tree->uo);
			actualVal -= free; //roundabout
			cur = 1;

			actualVal = (actualVal -1) % tree->uo;
			actualVal++;

			if (!occupied[1])
				actualVal --;
		}

		int next = tree->Q(cur, actualVal);

		occupied.flip(next);
		cur = next;
		ans[cur] = val;
		tree->mark(cur);

		//printf("cur: %d\n", cur);
	}

	delete tree;
}

int main() {
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	cin >> T;

	LPE(cn, 1, T)
	{
		cin >> K >> n;

		LP(i, 0, n)
			cin >> qs[i];

		memset(ans, 0, sizeof(ans));
		occupied.reset();
		process();

		printf("Case #%d:", cn);

		LP(i, 0, n)
			printf(" %d", ans[qs[i]]);

		printf("\n");
	}

	return 0;
}
