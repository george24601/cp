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
typedef long double LD;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

/*
 count [i][j], where x is a subtring ends at i, y is a subsequence ends at j
 the number of pairs, in the sbu string x[...i]y[...j]

 if(x[i] == y[j]){
 total[i][j] = total[i - 1]y[j - 1] + total [i - 1]y[j - 1]
 }else{
 total [i][j] = total [i][j - 1];
 }

 answer is sum total [i][n];


 */

int const MaxSize = 5000 + 5;
int const MOD = 1e9 + 7;

//NOTE WORKS ONLY WHEN MOD IS PRIME
//catch n = 1, 2, 3, 4
string s, t;
LL total[MaxSize][MaxSize];//we count only non-empties! and this means we will move the 1 to the formula!

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> s >> t;
	int sCnt = s.size();
	int tCnt = t.size();
	LPE(i, 0, sCnt)
	{
		memset(total[i], 0, sizeof(total[i]));
	}


	LPE(si, 1, sCnt)
	{
		LPE(ti, 1 ,tCnt)
		{
			if (s[si - 1] == t[ti - 1]) { //catch: offset by 1
			//	cout << si << " " << ti << " " << total[si - 1][ti - 1]  << " " <<  total[si][ti - 1] << endl;
				total[si][ti] = total[si - 1][ti - 1] + total[si][ti - 1] + 1;
				total[si][ti] %= MOD;
			} else {
				total[si][ti] = total[si][ti - 1];
			}
		}

	}

	/*
	LPE(si, 0, sCnt)
	{
		LPE(ti, 0 ,tCnt)
		{
			cout << total[si][ti] << " ";
		}
		cout << endl;
	}*/

	int ans = 0;
	LPE(si, 1, sCnt)
	{
		ans += total[si][tCnt];
		ans %= MOD;
	}

	cout << ans;

	return 0;
}
