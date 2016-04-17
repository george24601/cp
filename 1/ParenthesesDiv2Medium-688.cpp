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
 when balanced: scan from l to r, balance >=0
 i.e., when balance about to < 0, must filp that ) to (
 note that pairs are even, i.e., when you have a balance, you know there must exist corresponding # of oppsoite signs
 otherwise sum may become odd, (balanced pairs are even by default)
 when balance reaches n/2, the remaining ones must be ), i.e., flip possible ( to )

 balance = 0
 for i in [0, n)
 	 if balance == 0 and s[i] == ')'
 	 	 add i to flip
 	 	 balance++;
 	 else if balance == remaining # of chars && s[i] == '('
 	 	 add i to flip
 	 	 balance--;
 	 else if(s[i] == 0)
 	 	 balance++;
 	 else
 	 	 balance--;
 */

class ParenthesesDiv2Medium {
public:
	vector <int> correct(string s){
		int n = s.length();

		int balance = 0;
		vector<int> res;

		LP(i, 0, n){
			if(balance == 0 && s[i] == ')'){
				res.push_back(i);
				s[i] = '(';
			}else if(balance == (n - i) && s[i] == '('){
				res.push_back(i);
				s[i] = ')';
			}

			//cout << s[i] << endl;
			if('(' == s[i])
				balance++;
			else
				balance--;

			//cout << balance << endl;
		}

		return res;
	}
};

int main() {
ParenthesesDiv2Medium test;
cout << test.correct(")(").size() << endl;

	return 0;
}
