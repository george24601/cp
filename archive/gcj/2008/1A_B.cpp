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

/*
 allgood = false
 while(!allgood)
 allgood = true;

 if (not satifisied)
 {
 allgood is false
 }



 */

//literal starts with 1
//clause starts with 0
int const MaxLit = 2020;
int const MaxClause = 2020;

bitset<MaxLit> ans; //all 1, turn to 0

int clausePs[MaxClause];
bitset<MaxLit> clauseNs[MaxClause]; //all 0s, turn to 1

int C, numLit, numClause; //N: literal count, M: clause count

void reset() {
	memset(clausePs, 0, sizeof(clausePs));

	ans.reset();
	LPE(i, 1, numLit)
		ans.flip(i);

	LP(i, 0, numClause){
		clauseNs[i].reset();
	}
}

bool unitProp() {
	bool success = false;

	while (!success) {
		success = true;

		LP(clause, 0, numClause)
		{
			int posLit = clausePs[clause];
			bool posGood = posLit && !ans[posLit]; //1 in ans means it is FALSE
			bool negGood = (clauseNs[clause] & ans).any();

			//cout << clause << " "<< posLit << " " << posGood << " " << negGood << endl;

			if (posGood || negGood)
				continue;

			//both pos and neg are false, this means we are at form 1...10

			success = false;

			if (posLit) {
				ans.flip(posLit); //only choice is to flip 0
			} else {
				return false; //we can not flip anymore, as it will revert previous step!
			}
		}

	}

	return true;
}

int main() {
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/B_small.out", "w", stdout);

	cin >> C;
	LPE(cn, 1, C)
	{
		cin >> numLit >> numClause;

		reset();

		LP(clause,0, numClause)
		{
			int T;
			cin >> T;

			LP(lit, 0, T)
			{
				int X, Y;
				cin >> X >> Y;

				if (Y)
					clausePs[clause] = X;
				else
					clauseNs[clause].flip(X);
			}
		}

		bool result = unitProp();

		if (result){
			printf("Case #%d:", cn);

			LPE(i, 1, numLit){
				printf(" %d", !ans[i]);
			}

			printf("\n");
		}else{
			printf("Case #%d: IMPOSSIBLE\n", cn);
		}
	}

	return 0;
}
