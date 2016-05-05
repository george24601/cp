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
while string is not empty
	scan through the string
	next

	while(i < length)
		if (cur[i] != look[j])
			i++;
			next += current;
		else
			j++; i++
			if(j == size)
				j = 0;



*/

class 	  Quacking{
public:
	 int quack(string s){
		 if (s.length() == 0)
			 return 0;

		 int i = 0;
		 int j = 0;
		 char tbl [5] = {'q', 'u', 'a', 'c', 'k'};

		 string next = "";

		 while(i < s.length()){
			 if(tbl[j] == s[i]){
				 j++;
				 if(j == 5)
					 j = 0; //reset
			 }else{
				 next.push_back(s[i]);
			 }

			 i++;
		 }

		 if(j != 0) //incomplete
			 return -1;

		 if(next.length() == s.length())
			 return -1; //no matching at all

		 int nextR = quack(next);

		 if (-1 == nextR)
			 return -1;
		 else
			 return nextR + 1;
	 }
};

int main() {
	Quacking test;
	cout << test.quack("quqacukqauackck") << endl;
	cout << test.quack("quqaquuacakcqckkuaquckqauckack") << endl;

	return 0;
}
