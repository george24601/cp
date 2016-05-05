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
using namespace std;

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define INF 2000000000
#define Ep 1e-9

/*
 build a dictory first, maybe sorted

 generate all pairs => see if it matches,
 optimization: dont generate all that wont match,probaly dict needs partial stuff as well
 prefix dictiory: 75k *15 around 1 mil chars

 how to generate?

 scanning (prefix, index)
 	 if (prefix doesnt exist)
 	 	 return;

 	 if (index == length)
 	 	 final count++, return

 	 if index is normal char
 	 	 scanning(prefix + char, index+1);

 	 if index is (
 	 	 find ) index
 	 	 for each char between the two
 	 	 	 scanning(prefxi + 1, ) index + 1)

THis solution is correct, but took 2 mins to generate solutions for large dataset

 */

int tL, D, N;
int const MaxL = 15;
int const MaxD = 5000;
int const MaxN = 500;
set<string> prefixes;
int res;
string pattern;

void p_r(string prefix, int iToRead){
	//cout << prefix << endl;

	if (prefix.length() != 0 && prefixes.count(prefix) == 0)
		return;

	if(iToRead == pattern.length()){
		res++;
		return;
	}

	char curC = pattern[iToRead];

	if('(' == curC)
	{
		int rBI = iToRead + 1;

		while(pattern[rBI] != ')')
			rBI++;

		LP(i, iToRead+1, rBI)
		{
			char orChar = pattern[i];
			p_r(prefix + orChar, rBI + 1);
		}
	}else{
		p_r(prefix + curC, iToRead + 1);
	}
}

int main() {
	freopen("/Users/georgeli/Downloads/A-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/qual_A.in", "r", stdin);
	freopen("/Users/georgeli/A_in.out", "w", stdout);

	cin >> tL >> D >> N;

	LP(i, 0, D)
	{
		string word;
		cin >> word;

		LPE(subL, 1, tL)
			prefixes.insert(word.substr(0, subL));
	}

//	cout << "start!" <<endl;

	LPE(cn, 1, N)
	{
		res = 0;

		cin >> pattern;

		p_r("", 0);

		printf("Case #%d: %d\n", cn, res);
	}

	return 0;

}
