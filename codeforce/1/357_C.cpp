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
 suppose only getMin, no removeMin
 1. for insert, we need to keep doing that
 2. for getMin, if currentMin has that value, might as well remove
 otherwise, either queue is empty or currentMin is greater than that
 => we must insert that value right before it!

 suppose only removeMin, no getMin
 1. for insert, do same
 2. for remove, insert any value would do

 combine them
 1. getMin value different, but still has value

 if curV < correctV
 we know there is removal => remove all until curMin >= correctV
 if curV = correctV
 same case, just proceed
 if curV > correctV
 insert that correctV

 2. removeMin
 if PQ already empty, just insert any value
 else
 suppose we missed an insert which should be the min value => fixing that requires only 1 fix anyway, same cost
 suppose we missed an insert which is not the min value => we should proceed



 */

vector<string> res;
vector<int> rV;
priority_queue<int> q;

string const removeMin = "removeMin";
string const insert = "insert";

void fixByInsert(int iv) {
	q.push(-iv);
	res.push_back(insert);
	rV.push_back(iv);
}

void fixByRemove() {
	q.pop();
	res.push_back(removeMin);
	rV.push_back(0);
}

void fixGetMin(int target) {

	while (q.size() > 0 && -q.top() < target)
		fixByRemove();

	if (q.size() == 0 || -q.top() != target)
		fixByInsert(target);
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	LP(i, 0, n)
	{
		string action;

		cin >> action;

		if (action == "insert") {
			int value;
			cin >> value;

			fixByInsert(value);
		} else if (action == "getMin") {
			int value;
			cin >> value;

			if (q.size() == 0) {
				fixByInsert(value);
			} else if (-q.top() != value)
				fixGetMin(value);

			res.push_back(action);
			rV.push_back(value);
		} else {
			assert(action == removeMin);
			if (q.size() == 0)
				fixByInsert(1);

			fixByRemove();
		}

	}

	int m = res.size();
	cout << m << endl;

	LP(i, 0, m)
	{
		if (res[i] == removeMin)
			cout << res[i] << endl;
		else
			cout << res[i] << " " << rV[i] << endl;
	}

	return 0;
}
