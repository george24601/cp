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

int const MaxSize = 100010;
int n, l[MaxSize];
PII ld[MaxSize];

LL totalC;
priority_queue<int> candCosts;

int processBand(int sI, int nextI) {
	int bandL = nextI - sI;

	int bandCost = 0;

	vector<int> toBeAdded;

	LP(i, sI, nextI)
	{
		int singleC = ld[i].second;
		bandCost += singleC;
		toBeAdded.push_back(singleC);
	}

	int counter = 0;
	int prevKeptC = 0;

	while (candCosts.size() && counter < bandL - 1) {

		int singleC = candCosts.top();
		candCosts.pop();

		toBeAdded.push_back(singleC);
		prevKeptC += singleC;
		counter++;
	}

	LP(i, 0, toBeAdded.size())
		candCosts.push(toBeAdded[i]);

	//cout << sI << " " << nextI << endl;
	//cout << totalC << " " << prevKeptC << " " << bandCost << endl;

	return totalC - prevKeptC - bandCost;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	totalC = 0;

	LP(i, 0, n)
		scanf("%d", &l[i]);

	LP(i, 0, n)
	{
		int di;
		scanf("%d", &di);
		totalC += di;

		ld[i] = PII(l[i], di);
	}

	sort(ld, ld + n);

	int bandV = ld[0].first;
	int bandStart = 0;

	int ans = INF;

	LP(i, 1, n)
	{
		int curV = ld[i].first;

		if (curV != bandV){
			ans = min(ans, processBand(bandStart, i));
			bandV = curV;
			bandStart = i;
		}
	}


	ans = min(ans, processBand(bandStart, n));

	cout << ans << endl;

	return 0;
}
