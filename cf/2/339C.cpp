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
int const MaxSize = 1010;
char s[12];
int m;
bool good[MaxSize][12][12];
int prevW[MaxSize][12][12];

void p_r(int r, int w, int b) {

	if (r == 1) {

		assert(w == b);
		printf("YES\n");
		printf("%d ", w);
		return;
	}

	int pW = prevW[r][w][b];
	int pB = w - b;

//	cout << r << " " << w << " " << b << " "<< pW << " " << pB << endl;

	p_r(r - 1, pW, pB);

	if (r == m)
		printf("%d\n", w);
	else
		printf("%d ", w);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%s", s);
	scanf("%d", &m);
	int const Ten = 10;

	LPE(i, 0, m)
	{
		LPE(w, 1 , Ten)
			memset(good[i][w], false, sizeof(good[i][w]));
	}

	LPE(w, 1, Ten)
	{
		if (s[w - 1] == '0')
			continue;

		good[1][w][w] = true;
	}

	LPE(round, 2, m)
	{
		LPE(thisW, 1, Ten)
		{
			if (s[thisW - 1] == '0')
				continue;

			LP(thisBalance, 1, thisW)
			{
				int prevBalance = thisW - thisBalance;

				LPE(pW, prevBalance, Ten)
				{
					if (s[pW - 1] == '0')
						continue;

					if (pW == thisW)
						continue;

					if (good[round - 1][pW][prevBalance]) {

						good[round][thisW][thisBalance] = true;
						prevW[round][thisW][thisBalance] = pW;
						//cout << round << " " << thisW << " " << endBalance << " " << pW << endl;
						//	cout << pW << " " <<  prevW[round][thisW][endBalance] << endl;
					}
				}
			}
		}
	}

	LPE(lastW, 1, Ten)
	{
		LPE(lastB, 1, Ten)
		{
			if (good[m][lastW][lastB]) {
				p_r(m, lastW, lastB);
				return 0;
			}
		}
	}

	printf("NO\n");

	return 0;
}
