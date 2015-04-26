#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 10446 The Marriage Interview
//DP
typedef unsigned long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Max(a,b) a>b?a:b

const int MaxN = 61;
const int MaxBack = 60;

L total[MaxN + 1][MaxBack + 1];

L trib(int n, int back) {

	if (back < 0)
		return 1;
	if (n <= 1)
		return 1;

	if (total[n][back] > 0)
		return total[n][back];

	L count = 0;
	int i;
	count++;
	for (i = 1; i <= back; i++)
		count += trib(n - i, back);

	total[n][back] = count;
	return count;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Users\\George\\c1\\test\\src\\t.txt", "r", stdin);

	LPE(i, 0, MaxN)
	{
		LPE(j, 0, MaxBack)
			total[i][j] = 0;
	}

	int n, s;
	int caseNum = 0;

	while (scanf("%d %d", &n, &s) == 2) {
		if (n > 60)
			break;

		caseNum++;
		L result = trib(n, s);
		printf("Case %d: %llu\n", caseNum, result);
	}

	return 0;
}
