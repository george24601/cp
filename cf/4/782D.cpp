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
//typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-7

#define INF 1e9
/*
 create a graph
 with each node is (id, option), connect them if they are not in conflict

 and then traverse the graph, for each component, see if size of component >=n, and then print out the answer
 */

int const MaxSize = 1000;

int n;
bool use2[MaxSize];
string ff[MaxSize], sf[MaxSize];

void checkSF(int i){
	if(!use2[i])
		return;

	LP(j, 0, n){
		if(i == j){
			continue;
		}

		if(!use2[j] && sf[i] == ff[j]){
			use2[j] = true;
			checkSF(j);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
	{
		string fh, sh;
		cin >> fh >> sh;
		ff[i] = fh.substr(0, 3);
		sf[i] = fh.substr(0, 2) + sh.substr(0, 1);
	}

	LP(i, 0, n)
	{
		LP(j, i+1, n)
		{
			if (ff[i] == ff[j]) {
				use2[i] = true;
				use2[j] = true;
			}
		}
	}

	LP(i, 0, n)
		checkSF(i);

	LP(i, 0, n)
	{
		LP(j, i+1, n)
		{
			string iAns = use2[i] ? sf[i] : ff[i];
			string jAns = use2[j] ? sf[j] : ff[j];

			if (iAns == jAns) {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES" << endl;

	LP(i, 0, n)
	{
		if (use2[i])
			cout << sf[i] << endl;
		else
			cout << ff[i] << endl;
	}

	return 0;
}
