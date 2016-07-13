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

string sig(string s){
	if(s.length() <= 1 || s.length() % 2)
		return s;

	int halfLen = s.length()/2;

	string first = sig(s.substr(0, halfLen));
	string second = sig(s.substr(halfLen));

	if(first < second)
		return first + second;
	else
		return second + first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	string first, second;

	cin >> first >> second;

	//cout << first << second << endl;

	if(sig(first) == sig(second))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

