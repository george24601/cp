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

int const MaxSize = 1001;

string first;
int fLen, sLen;
string second;


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);

	while(getline(cin, first))
	{
		getline(cin, second);

		fLen = first.size();
		sLen = second.size();

		sort(first.begin(), first.end());
		sort(second.begin(), second.end());

		vector<char> ans;

		int j = 0;
		int i =0;

		while(true)
		{
			while(i <= fLen && j <= sLen && first[i] != second[j])
			{
				if(first[i] < second[j])
					i++;
				else if(first[i] > second[j])
					j++;
			}

			if(i>= fLen || j >= sLen)
				break;

			if(first[i] == second[j])
			{
				ans.push_back(first[i]);
				i++;
			    j++;
			}

		}

		LP(i, 0, ans.size())
			printf("%c", ans[i]);

		printf("\n");
	}



	return 0;
}
