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

int const MaxSize = 120;

int k, w;

char buff[MaxSize][MaxSize];

int dup(int a, int b)
{
	for(int commonLength = k; commonLength> 0; commonLength--)
	{
		bool possible = true;
		LP(dist, 0, commonLength)
		{
			if(buff[b][dist] == buff[a][k - commonLength + dist])
			{

			}else
			{
				possible = false;
				break;
			}
		}

		if(possible)
			return commonLength;
	}


	return 0;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\E.1.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d %d", &k, &w);

		LP(i, 0, w)
			scanf("%s", buff[i]);

		int total = w * k;

		LP(i, 1, w)
			total -= dup(i - 1, i);

		printf("%d\n", total);

	}

	return 0;
}
