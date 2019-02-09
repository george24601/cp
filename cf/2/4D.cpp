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
 for each entry, look for the max value += 1, and update the the
 1. update 0 to or 1
 2. scan again, update only if longest > 0, also keep the previous I
 3. add the answer to the vecotr, and then sort it

 CATCH CASES:
 1. no match
 2. only 1 match
 3. 2 matches
 4. with same first edges

 The main mistake i did was not to init max value and i properly even though i separated the single len and multiple len case

 */

int const MaxSize = 5000 + 5;
int n, w, h, maxLen[MaxSize], prevI[MaxSize];
vector<pair<int, PII> > envs;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> w >> h;

	LP(i, 0, n)
	{
		int wi, hi;
		cin >> wi >> hi;
		envs.push_back(pair<int, PII>(wi, PII(hi, i)));
	}

	sort(envs.begin(), envs.end());

	int curMaxI;
	int curMax = 0;
	LP(i, 0, n)
	{
		if (envs[i].first > w && envs[i].second.first > h) {
			maxLen[i] = 1;
			curMax = 1;
			curMaxI = i;
		} else {
			maxLen[i] = 0;
		}
		prevI[i] = i;
	}


	LP(i, 1, n)
	{
		LP(j, 0, i)
		{
			if (maxLen[j] && envs[j].first < envs[i].first &&
					envs[j].second.first < envs[i].second.first) {
				//cout << j << " " << i << endl;
				if (maxLen[j] + 1 > maxLen[i]) {
					maxLen[i] = maxLen[j] + 1;
					prevI[i] = j;
					if (maxLen[i] > curMax) {
						curMax = maxLen[i];
						curMaxI = i;
					}
				}
			}
		}
	}

	//cout << curMaxI << " " << curMax << endl;

	vector<int> is;
	if (curMax) {
		int i = curMaxI;
		while(true){
			is.push_back(envs[i].second.second + 1);
			if(prevI[i] == i)
				break;
			else
				i = prevI[i];
		}
	}

	reverse(is.begin(), is.end());
	cout << is.size() << endl;
	LP(i, 0, is.size())
		cout << is[i] << " ";

	return 0;
}
