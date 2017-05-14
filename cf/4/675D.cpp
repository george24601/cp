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
 it is parent must be either lower bound or upper bound of number

 find upper bound;
 if uper bound has no left

 */

int const MaxSize = 100010;

int n;
set<int> a;
map<int ,int> l;
map<int, int> r;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d", &n);

	int curN;
	scanf("%d", &curN);

	a.insert(curN);

	LP(i, 1, n)
	{
		scanf("%d", &curN);

		auto it = a.upper_bound(curN);

//		cout << "curN:" << curN << endl;

		int parent;

//		if(it != a.end())
//			cout << "has upper bound" << endl;

		if (it != a.end() && l.count(*it) == 0) { //there exists upper bound, and it has no left child

			int ub = *it;
			parent = ub;
			l[ub] = curN;

		} else {
//			cout << "found lower bound" << endl;
			it--;
			int lb = *it;
			parent = lb;
			r[lb] = curN;

		}

		printf("%d", parent);

		if (i == n - 1)
			printf("\n");
		else
			printf(" ");

		a.insert(curN);
	}

	return 0;
}
