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
#define Ep 1e-9

/*
string matching: similar to KMP?
E(targetI, len) =
totalE = 0;
	for each letter in keyboard {
		Pr(letter) * (nextI(targetI, letter), len--)
	}


 */
int K, wLen, S;
int keyCount [26];
char W[110];
int T[110];

///Borrowed from KMP
void BuildT() {
	T[0] = -1; //special case
	T[1] = 0; //0 because we have no suffix right now

	int i = 2;
	int tI = 0;

	while (i < wLen) {
		//if(i >= 6)
		//	printf("%d %d %d\n", i, tI, T[tI]);

		if (W[i - 1] == W[tI]) {
			//i - 1 can extend an existing suffix which is also a prefix
			T[i] = tI + 1;
			i += 1;
			tI = tI + 1;
		} else if (tI > 0) {
			//so the suffix ending at i-1 will not work for current starting point, can we try a shorter suffix?
			//notice the suffix ending at i-2 has T[tI] matches already, so we will try that match's starting point,i.e, that matching's length
			tI = T[tI];
		} else {
			//tI== 0, i.e., first character doesnt match
			T[i] = 0;
			i += 1;
		}
	}

}


double pr(int i){
	return (double)keyCount[i] / (double) K;
}

//TODO: probably cache it
double fallback(int targetI, int thisChar){
	int mLen = targetI;//since we start index at 0

	while(mLen){
		mLen = T[mLen];

		if(W[mLen] - 'A' == thisChar){
			return mLen + 1;
		}
	}

	return mLen;
}

double E(int targetI, int len){
	if(len == 0)
		return 0;

	double prNextMatch = pr(W[targetI] - 'A');
	double matchExp = targetI == wLen -1 ? prNextMatch * (1 + E(0, len-1))  :  prNextMatch * E(targetI+1, len-1);

	double unmatchedE = 0;

	LP(i, 0, 26){
		if (W[targetI] - 'A' == i)
			continue; //matching letter: handled this case already

		unmatchedE += pr(i) * E(fallback(targetI, i), len - 1);
	}

	return matchExp + unmatchedE;
}

int main() {
	freopen("/Users/georgeli/B_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/A-small-practice.in", "r", stdin);
	//freopen("/Users/georgeli/A_small.out", "w", stdout);

	int T;

	scanf("%d", &T);
	printf("%d\n", T);

	LPE(cn, 1, T){
		memset(keyCount, 0, sizeof(keyCount));

		scanf("%d %d %d", &K, &wLen, &S);
		printf("%d %d %d\n", K, wLen, S);

		char keys [100];
		scanf("%s", keys);
		printf("%s\n", keys);

		LP(i,0, K)
		 keyCount[keys[i] - 'A']++;

		scanf("%s", W);
		printf("%s\n", W);

		BuildT();

		printf("TBuild!\n");

		double finalE = E(0, S);

		printf("Case #%d: %.6lf\n", cn, finalE);
	}

	return 0;
}
