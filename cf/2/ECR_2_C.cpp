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

 if 1 odd
 good

 if 2 odds
 change the bigger to smaller

 if 3 odds
 a, b, c => aba

 if 4 odds
 abcd => abba

 if 5 odds
 abcde => abcba


 */

int const MaxSize = 200010;

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	char input[MaxSize];

	scanf("%s", input);
	int n = strlen(input);

	int const alphaSize = 26;
	int cc[alphaSize];

	memset(cc, 0, sizeof(cc));

	LP(i, 0, n)
		cc[input[i] - 'a']++;


	vector<int> odds;

	LP(i, 0, alphaSize)
	{
		if (cc[i] % 2)
			odds.push_back(i);
	}

	int numOdds = odds.size();

	LP(i, 0, numOdds/2){
		cc[odds[i]]++;
		cc[odds[numOdds - i - 1]]--;

//		cout << odds[i] << " " << odds[numOdds - i - 1] << endl;
		//cout << cc[odds[i]] << " " << cc[odds[numOdds - i - 1]] << endl;
	}


	int firstOdd = n % 2? odds[numOdds/2] : -1;

	//cout << firstOdd << endl;

	LP(i, 0, alphaSize)
	{
		LP(j, 0, cc[i]/2)
			printf("%c", 'a' + i);
	}

	if (firstOdd >= 0 && n % 2)
			printf("%c", 'a' + firstOdd);

	for (int i = alphaSize - 1; i >= 0; i--) {
		LP(j, 0, cc[i]/2)
			printf("%c", 'a' + i);
	}

	return 0;
}
