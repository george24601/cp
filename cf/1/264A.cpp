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

string s;

void p(int i){
	if(i == s.length())
		return;

	if(s[i] == 'l'){
		p(i+1);
		printf("%d\n", i+1);
	}else{
		printf("%d\n", i+1);
		p(i+1);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> s;

	p(0);



	return 0;
}

