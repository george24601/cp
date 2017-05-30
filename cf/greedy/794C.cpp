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
#define Ep 1e-13

#define INF 1e16
const int MaxSize = 200000 + 10;
const LL MOD = 1e9 + 7;

string s, t;
int n, cnt, sis, sie, tsi, tei;

void playS();

void playT(){
	if(tsi > tei){
		return;
	}else if(s[sis] < t[tei]){
		//cout << sis << " " << tei << endl;

		cout << t[tei];
		tei--;
		playS();
	}else{
		char smallest = t[tsi];
		tsi++;
		playS();
		cout << smallest;
	}
}

void playS(){
	if(sis > sie)
		return;
	else if(tsi > tei){
		cout << s[sis];
	}else if(s[sis] < t[tei]){
		cout << s[sis];
		sis++;
		playT();
	}else{
		char largest = s[sie];
		sie--;
		playT();
		cout << largest;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> s >> t;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	n = s.size();

	sis = 0, sie = (n + 1)/2 - 1;

	tsi = sie + 1, tei = n - 1;

	playS();


	return 0;
}
