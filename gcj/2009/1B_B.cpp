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

int T;
char c[100];
int numC;
deque<char> q;

int main() {

	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/B_large.out", "w", stdout);

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%s", c);
		numC = strlen(c);

		q.clear();

		LP(i, 0, numC)
			q.push_back(c[i]);

		q.push_front('0');
		next_permutation(q.begin(), q.end());

		while(q.front() == '0')
			q.pop_front();

		printf("Case #%d: ", cn);

		LP(i, 0, q.size())
			printf("%c", q[i]);

		printf("\n");
	}

	return 0;
}
