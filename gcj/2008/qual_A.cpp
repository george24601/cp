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
using namespace std;

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define INF 2000000000
#define Ep 1e-9

/*

 Input size: Q < 100
 unknown:
 number of switches

 condition:
 each time your query meets a match, you have to switch

 Known:
 query list

 Insight:
 1. you have to switch when the room is full => i.e., if no one queries an SE, all queries can go there
 2. when you switch, the black list got reset

 So consider when switch happens => that marks the last search engine we sent to!

 Subproblem:
 1. given the switch location => what is the earliest backtrack I can do?
 but this is greedy

 another insight, starting the switch later doesnt matter overall count , as long as it makes the same switch

 so at each spot, we know if it is at a certain SE, we will finish it in n switchs

 switch(q, s) =
 switch(q + 1, s) if  qs[q+ 1]!= s
 if q + 1 = s
 min (switch(q +1, s')) where s' != s

 */

int N, S, Q;
int const MaxS = 100;
int const MaxQ = 1000;
int const MaxNL = 100;
map<string, int> seToID;
int qs[MaxQ + 1];
int ans[MaxQ + 1][MaxS + 1];

void process() {
	LP(s, 0, S)
	{
		if (qs[Q] == s)
			ans[Q][s] = 1;
		else
			ans[Q][s] = 0;
	}

	for (int q = Q - 1; q >= 1; q--) {

		LP(s, 0, S){
			if (qs[q] == s){
				int nextRes = INF;

				LP(nextS, 0, S)
				{
					if (nextS == s)
						continue;

					nextRes = min(nextRes, ans[q+1][nextS]);
				}

				ans[q][s] = 1 + nextRes;
			}else{
				ans[q] [s] = ans[q + 1][s];
			}
		}
	}

}

int main() {
	freopen("/Users/georgeli/Downloads/A-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/qual_A.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	cin >> N;

	LPE(cn, 1, N)
	{
		seToID.clear();

		cin >> S;
		string name;
		getline(cin, name);//return char

		LP(i, 0, S)
		{
			getline(cin, name);
			seToID[name] = seToID.size();
		}

		cin >> Q;
		getline(cin, name);//return char

		LPE(i, 1 , Q)
		{
			getline(cin, name);
			qs[i] = seToID[name];
		}

		process();

		int res = INF;
		LP(s, 0, S){
			res = min(res, ans[1][s]);
		}

		printf("Case #%d: %d\n", cn, res);
	}

	return 0;
}
