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
	freopen("/Users/georgeli/A_1.in", "r", stdin);

	string s;

	cin >> s;

	string rs;

	int N = s.length();

	LP(i, 0,N)
		rs.push_back(s[N - i]);

	bool can2[MaxSize];
	memset(can2, false, sizeof(can2));

	bool can3[MaxSize];
	memset(can3, false, sizeof(can3));

	can2[1] = true;
	can2[2] = true;

	LP(i, 3, N - 4)
	{
		if (rs[i] == rs[i - 2] && rs[i-1] == rs[i - 3])
			can2[i] = false;
		else
			can2[i] = true;
	}

	can3[2] = true;
	can3[3] = true;
	can3[4] = true;

	LP(i, 5, N - 4)
	{
		bool hasDup = true;
		LP(j, 0, 3){

			if(rs[i - j - 3] != rs[i -j])
				hasDup = false;
		}

		can3[i] = !hasDup;
	}

	vector<string> res;

	LP(i, 0, N){
		if(can2[i])
			res.push_back(s.substr(N - 1 -i, 2));

		if(can3[i])
			res.push_back(s.substr(N - 1 -i, 3));
	}

	sort(res.begin(), res.end());

	LP(i, 0, res.size())
		cout << res[i] << endl;

	return 0;
}
