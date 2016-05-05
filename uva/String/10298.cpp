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

int const MaxSize = 1000009;
char str[MaxSize];
int len;

bool isConst(int curLen)
{
	LP(i, 1, curLen)
	{
		if(str[i] != str[i - 1])
			return false;

	}

	return true;
}

bool good(int curLen, int numSeg)
{
	int segLen = curLen/numSeg;
	LP(segCount, 1, numSeg)
	{
		LP(i, 0, segLen)
		{
			if(str[i] != str[i + segLen * segCount])
				return false;
		}
	}

	return true;
}

void Process()
{
	int n = 1;

	int numSeg = 2;

	int curLen = len;

	while(numSeg <= len/2)
	{
		if(curLen %numSeg != 0)
		{
			numSeg++;
			continue;
		}

		if (good(len/n, numSeg))
		{
			n *= numSeg;
			curLen /= numSeg;
		}else
		{
			while(curLen %  numSeg == 0)
				curLen /= numSeg;
		}
	}

	if(isConst(len/n))
		n = len;

	printf("%d\n", n);
}


int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\D.0.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	while(scanf("%s", str))
	{
		len = strlen(str);

		if(len == 1 && str[0] == '.')
			break;

		Process();
	}

	return 0;
}
