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
#define Ep 1e-8
#define INF 2000000100
LL const LINF = LL(1e18);

/*
 maintain a heap for diff cost in front me

 sort by ballon

 populate PQ by teams in front of me

 starting from the nextRankI

 while(nextRankI < n)

 ToNextRank()
 tryImprove()

 */

int const MaxSize = 300010;
pair<LL, LL> teams[MaxSize];
int n;
LL mt, mw, surplus;
priority_queue<LL> balance;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;

	cin >> mt >> mw;

	LP(i, 0,n - 1)
	{
		LL t, w;
		cin >> t >> w;
		teams[i] = pair<LL, LL>(-t, w);
	}

	sort (teams, teams+ n-1);

	int i = 0;
	while(true){
		LL t = -teams[i].first;
		LL w = teams[i].second;

		if(t <= mt)
			break;
		else
			i++;

		balance.push(w - t);
	}


	int bestRank = balance.size();
	int surplus = 0;
	int si = i;
	while(i < n){
		int nextT = -teams[i].first;
		LL nextW = teams[i].second;

		surplus += mt - nextT;
		mt = nextT;

		if(mt < -teams[si].first){

			LP(i, 0,  )


			si = i;
		}

		if(bestRank > balance.size())
			bestRank = balance.size();

		i++;
	}

	cout << bestRank << endl;

	return 0;
}
