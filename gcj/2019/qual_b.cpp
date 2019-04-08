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
typedef long double LD;
#define LP(i, a, b) for (LL i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (LL i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

LL const MaxSize = 1000 + 5;
LL const MOD = 1e9 + 7;

/*

 */

int n;
string path;
int state[MaxSize][MaxSize];
bool canUse[MaxSize][MaxSize][2];
vector<char> revAns;

void reset(){
	cin >> n >> path;
	revAns.clear();
	LP(i, 0, n)
	{
		memset(state[i], 0, sizeof(state[i]));
	}

	LP(i, 0, n){
		LP(j, 0, n){
			canUse[i][j][0] = true;
			canUse[i][j][1] = true;
		}
	}

	LP(i, 0, n){
		canUse[i][n - 1][0] = false;
		canUse[n - 1][i][1] = false;
	}
}

void popBad() {

	int curR = 0;
	int curC = 0;
	LP(i, 0, path.size())
	{

		if (path[i] == 'S') {
			canUse[curR][curC][1] = false;
			curR++;
		} else {
			canUse[curR][curC][0] = false;
			curC++;
		}
	}
}

int tryPath(int r, int c) {
	if (state[r][c] != 0)
		return state[r][c];

	if (r == n - 1 && c == n - 1)
		return 1;

	state[r][c] = 1;

	if (canUse[r][c][0]) {
		int res = tryPath(r, c + 1);
		if (res == 1) {
			//cout << r << " E " << c << endl;
			revAns.push_back('E');
			return 1;
		}
	}

	if (canUse[r][c][1]) {
		int res = tryPath(r + 1, c);
		if (res == 1) {
			//cout << r << " S " << c << endl;
			revAns.push_back('S');
			return 1;
		}
	}

	return state[r][c] = -1;
}

void run() {
	popBad();

	tryPath(0, 0);

	reverse(revAns.begin(), revAns.end());

	LP(i, 0, revAns.size())
		cout << revAns[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	int T;
	cin >> T;

	LPE(tc, 1, T)
	{
		cout << "Case #" << tc << ": ";
		reset();
		run();
		cout << endl;
	}

	return 0;
}
