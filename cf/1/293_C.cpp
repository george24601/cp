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
sort by value,



 */

int const MaxSize = 100010;
int n, m, k;

int appToPos[MaxSize];
int posToApp[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);

	LPE(i, 1, n){
		int app;
		scanf("%d", &app);

		appToPos[app] = i;
		posToApp[i] = app;
	}

	LL total = 0;

	LP(i, 0, m){
		int newA;
		scanf("%d", &newA);

		int curPos = appToPos[newA];

		total += (LL) ((curPos - 1)/k);
		total++;

		//cout << newA << " " << curPos << " " << total << endl;

		if(curPos > 1){
			int toSwap = posToApp[curPos - 1];
			swap(posToApp[curPos], posToApp[curPos-1]);
			swap(appToPos[newA], appToPos[toSwap]);
		}
	}

	cout << total << endl;

	return 0;
}

