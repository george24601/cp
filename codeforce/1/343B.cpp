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
*/


int const MaxSize=100010;

int pr[MaxSize];

string s;
int n;


int main() {
	ios_base::sync_with_stdio(false);
//	freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> s;
	n = s.length();

	LPE(i, 0, n)
		pr[i] = i - 1;

	LP(i, 1, n){
		int prevI = pr[i];
		if(prevI >= 0 && s[i] == s[prevI]){
			pr[i + 1] = pr[prevI];
		}
	}

	if (pr[n] == -1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}

