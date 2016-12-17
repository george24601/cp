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
 Reverse the string

 canCut2(i)
 canCut3(i)

 scan through i, add result to final set

 */

int const MaxSize = 10010;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	string s;

	cin >> s;

	string rs;

	int N = s.length();

	LP(i, 0,N)
		rs.push_back(s[N - 1 - i]);

	bool can2[MaxSize];
	memset(can2, false, sizeof(can2));

	bool can3[MaxSize];
	memset(can3, false, sizeof(can3));

	LP(i, 1, N - 5)
	{
		if(i == 1){
			can2[i] = true;
			continue;
		}else if(i == 2){
			can3[i] = true;
			continue;
		}

		bool hasDup = true;
		int len = 2;
		LP(j, 0, len)
		{
			if (rs[i - j - len] != rs[i - j])
				hasDup = false;
		}

		can2[i] = can3[i - len] || (can2[i - len] && !hasDup);

		hasDup = true;
		len = 3;

		LP(j, 0, len)
		{
			if (rs[i - j - len] != rs[i - j])
				hasDup = false;
		}

		can3[i] = can2[i-len] || (can3[i - len] && !hasDup);
	}

	set<string> uniques;

	LP(i, 0, N)
	{
		if (can2[i])
			uniques.insert(s.substr(N - 1 - i, 2));

		if (can3[i])
			uniques.insert(s.substr(N - 1 - i, 3));
	}

	vector<string> res;
	set<string>::iterator it;

	for (it = uniques.begin(); it != uniques.end(); it++)
		res.push_back(*it);

	sort(res.begin(), res.end());

	cout << res.size() << endl;
	LP(i, 0, res.size())
		cout << res[i] << endl;

	return 0;
}
