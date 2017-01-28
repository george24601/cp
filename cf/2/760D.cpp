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
#define Ep 1e-7

#define INF 2000000000
//#define INF 1e18

/*

 without the direction constraint, then obvibously as long as there is 1 cycle and we are good
 each extra cycle gives 2

 keep 1 for example, if going back to 1 is same orientation => bad, need to flip it just once somewhere!

 */

int const MaxSize = 100010;

LL n, t[MaxSize];
LL best[MaxSize];

/* Idea 1: bsearch
 set<LL> starts;
 map<LL, int> timeToI;

 int findI(int time) {

 set<LL>::iterator it = starts.upper_bound(time);

 if (it == starts.end()) {
 return -1;
 }

 return timeToI[*it] - 1;
 }

 int main() {
 ios_base::sync_with_stdio(0);
 //freopen("/Users/george/A_1.in", "r", stdin);

 cin >> n;

 LP(i, 0, n)
 {
 cin >> t[i];
 starts.insert(t[i]);
 timeToI[t[i]] = i;
 }

 LL totalC = 0;

 LP(i, 0, n)
 {
 LL curCost = totalC + 20;

 int i90 = findI(t[i] - 90); //bsearch to find i;

 curCost = min(curCost, (i90 >= 0 ? best[i90] : 0) + 50);

 int iDay = findI(t[i] - 1440);

 curCost = min(curCost, (iDay >= 0 ? best[iDay] : 0) + 120);

 cout << curCost - totalC << endl;


 //cout << totalC << " " << i90 << " " << iDay << endl;

 best[i] = curCost;
 totalC = curCost;
 }

 return 0;
 }
 */

//idea 2: amortize cost
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> t[i];

	int i90 = -1, iDay = -1;

	best[0] = 20;

	cout << 20 << endl;

	LP(i, 1, n)
	{
		best[i] = best[i - 1] + 20;

		while ((i90 + 1) < i && t[i90 + 1] <= (t[i] - 90))
			i90++;

		best[i] = min(best[i], (i90 >= 0 ? best[i90] : 0) + 50);

		while ((iDay + 1) < i && t[iDay + 1] <= (t[i] - 1440))
			iDay++;

		best[i] = min(best[i], (iDay >= 0 ? best[iDay] : 0) + 120);

//		cout << t[i] << " " <<  i90 << " " << iDay << " ";

		cout << best[i] - best[i - 1] << endl;
	}

	return 0;
}

