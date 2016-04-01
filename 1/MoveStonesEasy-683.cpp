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
#define MOD 1000000007

/*
 at left, if same nothg
 if more, move extra to right, target same, current changed

 if less, add extra to right, target changed, current changed, add to steps

 when there is one, they must match or bad
 */

class MoveStonesEasy{
public:
	int get(vector<int> a, vector<int> b){
		int n = a.size();
		int total = 0;

		LP(i, 0, n - 1){
			int delta = a[i] -b[i];
			if (0 == delta)
				continue;
			else if(delta > 0){
				a[i+ 1] += delta;
				total += delta;
			}else{
				b[i + 1] -= delta;
				total -= delta;
			}
			//cout << total << endl;
		}

		return (a[n - 1] == b[n - 1]) ? total : -1;
	}
};

int main() {
	static const int aA [] =  {3,10,0,4,0,0,0,1,0};
	static const int aB [] = {5,5,0,7,0,0,0,0,1};

	MoveStonesEasy obj;

	vector<int> a (aA, aA + sizeof(aA) / sizeof(aA[0]) );

	vector<int> b (aB, aB + sizeof(aB) / sizeof(aB[0]) );

	cout << obj.get(a, b) << endl;

	return 0;
}
