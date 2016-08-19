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

int const MaxSize = 510;
int n, m, r1, c1, r2, c2;

bool visited[MaxSize][MaxSize];
char cells[MaxSize][MaxSize];

int deltaR[4] = { 0, 1, 0, -1 };
int deltaC[4] = { 1, 0, -1, 0 };

bool visit(int r, int c) {
	assert(!visited[r][c]);

	visited[r][c] = true;

	if (r == r2 && c == c2)
		return true;

	if (cells[r][c] == 'X' && !(r == r1 && c == c1))
		return false;

	LP(i, 0, 4)
	{
		int newR = r + deltaR[i];
		int newC = c + deltaC[i];

		if (newR < n && newR >= 0 && newC < m && newC >= 0
				&& !visited[newR][newC]) {

			bool res = visit(newR, newC);

			if (res)
				return true;
		}

	}

	return false;
}

int numDot(int r, int c) {

	int ans = 0;
	LP(i, 0, 4)
	{
		int newR = r + deltaR[i];
		int newC = c + deltaC[i];

		if (newR < n && newR >= 0 && newC < m && newC >= 0
				&& cells[newR][newC] == '.')
			ans++;
	}

	return ans;

}

bool good(){
	bool reachable = visit(r1, c1);

	if(!reachable)
		return false;

	int numDs = numDot(r2, c2);
	if(r1 == r2 && c1 == c2)
		return numDs >= 1;

	if(cells[r2][c2] == 'X')
		return true;

	if (cells[r2][c2] == '.'){
		if(1 == abs(r2 - r1) + abs(c2 - c1))
			return numDs >= 1;
		else
			return numDs >= 2;

	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &m);

	LP(i, 0, n)
	{
		memset(visited[i], false, sizeof(visited[i]));
		scanf("%s", cells[i]);
	}

	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	r1--;
	c1--;
	r2--;
	c2--;

	if(good())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

