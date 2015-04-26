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
#define Ep 1e-9

int const MaxSize = 100000;
char W[MaxSize];
int wLen;
int T[MaxSize];  //length of suffix that ends at previous char which is also a prefix of W
char S[MaxSize];
int sLen;

void BuildT()
{
	T[0] =-1; //special case
	T[1] = 0;//0 because we have no suffix right now

	int i = 2;
	int tI = i - 1;

	while(i < wLen)
	{
		if(W[i - 1] == W[T[tI]])
		{
			//i - 1 can extend an existing suffix which is also a prefix
			T[i] = T[tI] + 1;
			i += 1;
			tI = tI + 1;
		}else if (T[tI] > 0)
		{
			//so the suffix ending at i-1 will not work for current starting point, can we try a shorter suffix?
			//notice the suffix ending at i-2 has T[tI] matches already, so we will try that match's starting point
			tI = T[tI];
		}else
		{
			//i -2 is not part of prefix, and i-1 is not same as the first char, so no valid suffix => reset to a fresh start
			T[i] = 0;
			i += 1;
			tI = i - 1;
		}
	}

}

bool KMP()
{
	wLen = strlen(W);

	int mStart = 0; //current match's starting index in S
	int mLen = 0;//current match's len

	while(mStart + mLen < sLen) //no match found yet, more left in S to inspect
	{
		if(S[mStart + mLen] == W[mLen]) //current mStart is good
		{
			mLen++;
			if(mLen == wLen)
				return true; //matching found
		}else if (mLen == 0)//no matching whatsoever
		{
			mStart++;
		}else
		{
			//current mStart wont work, need to move it up, notice that T[mLen] chars are matched already ending at mLen - 1 in W
			//and mStart + mLen -1 in S
			//so we can move mStart to the start of this match
			mStart = mStart + mLen - T[mLen];
			mLen = T[mLen];
		}
	}

	return false;
}


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\B.1.dat", "r", stdin);
	//freopen("C:\\Test\\out", "w", stdout);

	int k;
	scanf("%d", &k);

	LP(caseN, 0, k)
	{
		scanf("%s", S);
		sLen = strlen(S);

		int q;
		scanf("%d", &q);

		LP(i, 0, q)
		{
			scanf("%s", W);
			bool result = KMP();

			if(result)
				printf("y\n");
			else
				printf("n\n");
		}
	}

	return 0;
}
