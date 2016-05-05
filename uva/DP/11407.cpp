#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 11407 Squares
//DP
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

#define LPE(i, a, b) \
	for (int i = int(a); i <= int(b); i++)

#define Min(a ,b ) a < b ? a : b

const int MaxVal = 10000;

int total[MaxVal + 1];

void Process() {

	total[0] = 0;

	LPE(i, 1, MaxVal)
	{
		total[i] = MaxVal * 100;

		for (int j = 1; j <= MaxVal; j++) {
			int square = j * j;

			if (square > i)
				break;

			total[i] = Min(total[i], total[i - square] + 1);
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	Process();
	int t;
	scanf("%d", &t);

	LP(i, 0, t)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", total[n]);
	}

	return 0;
}
