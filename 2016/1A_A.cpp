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
 when seeing a new letter
 if the new letter < current head, put to tail
 otherwise, head
 */


int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/A-large.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	//cout << T << endl;

	LPE(cn, 1, T)
	{
		string s;
		cin >> s;
		//cout << "!!!" << s << endl;

		int n = s.length();

		string res = s.substr(0, 1);

		LP(i, 1, n){
			char next = s[i];

			if(next < res[0])
				res.push_back(next);
			else
				res = s.substr(i,1) + res;//res.insert(0, next);

		}

		cout << "Case #" << cn << ": "<< res<<endl;
	}

	return 0;

}
