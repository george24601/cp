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
typedef pair<int, int> PII;
#define INF 2000000000
#define Ep 1e-9

/*
 every time if we read a new char
 if it is not possible to be part of target, go to next char
 if it is possible
 	 subproblem: n(i, j) = subsequence of input(1...i) that forms subseqneuc of target(1...j)
 	 for each possible match at mj in the target
 	 	 n(i, mj + 1) = n (i - 1, mj+1)  //not using the last char
 	 	 +  mn(i - 1, mj) //using the last char

 	Lession learned: the power of table-driven design with 2-d array
 */

int T;
string input;
int const MaxLen = 500;
string target = "welcome to code jam";
int const tarLen =19;

int res [MaxLen] [tarLen];

bool match[MaxLen][tarLen];

void process(){
	//init: get all w

	LP(i, 0, input.length()){
		if ('w' == input[i]){
			res[i][0] = i == 0? 1 : res[i -1][0] + 1;
			res[i][0] %= 10000;
		}else {
			res[i][0] = i == 0? 0 : res[i - 1][0];
		}
	}

	//both i and j start from 1 because we already considered the w matching case
	LP(i, 1, input.length()){

		LP(j, 1, target.length()){
			if (match[i][j]){
				res[i][j] = res[i-1][j-1] + res[i-1][j];
				res[i][j] %= 10000;
			}else{
				res[i][j] = res[i-1] [j];
			}
		}
	}
}

void populateMap(){
	LP(i, 0, input.length()){
		LP(j, 0, target.length())
			 match[i][j] = input[i] == target[j];
	}
}

int main() {
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/qual_C.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	cin >> T;
	getline(cin, input); //newline char


	LPE(cn, 1, T)
	{
		getline(cin, input);

//		cout << input << endl;

		LP(i, 0, MaxLen)
			memset(res[i], 0, sizeof(res[i]));

		populateMap();
		process();

		printf("Case #%d: %04i\n", cn, res[input.length()-1][target.length() - 1]);

	}

	return 0;
}
