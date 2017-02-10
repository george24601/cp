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
#define Ep 1e-7

#define INF 2000000000
//#define INF 1e18
/*

 */

class BalancedStrings {

public:
	vector<string> findAny(int N) {

		vector<string> ans(N, "");

		ans[0].push_back('a');

		if (N > 1)
			ans[1].push_back('c');

		LP(i, 2, N)
		{
			int newC = (i - 2) % 22;
			newC += 'e';

			//cout << i << " " << newC << endl;
			ans[i].push_back((char) newC);
		}

		int sim = 0;

		LP(i, 2, N)
		{
			LP(j, i + 1, N)
			{
				if (ans[i] == ans[j])
					sim++;
			}
		}

		bool other = true;
		while (sim > 0 && ans[0].length() < 100) {

			ans[0].push_back(other ? 'b' : 'a');
			sim--;
			other = !other;
		}

		other = true;
		while (sim > 0 && ans[1].length() < 100) {

			ans[1].push_back(other ? 'd' : 'c');
			sim--;
			other = !other;
		}

		return ans;
	}
};

/*
 int main() {
 BalancedStrings test;
 int n = 100;
 vector<string> ans = test.findAny(n);

 LP(i, 0, n)
 cout << i << " " << ans[i] << endl;

 return 0;
 }
 */
