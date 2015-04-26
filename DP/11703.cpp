#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;

//UVA 11703 sqrt log sin
//DP
typedef unsigned long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

#define LPE(i, a, b) \
	for (int i = int(a); i <= int(b); i++)

#define Min(a ,b ) a < b ? a : b

const int MaxVal = 1000000;

int Ks[20];
int prices[20][20];
bool possible[21][201];

L total[MaxVal + 1];

void Process() {
	total[0] = 1;

	LPE(i, 1, MaxVal)
	{
		int first = (int)(i - sqrt(i));
		int second = (int)(log(i));
		double sinVal = sin(i);
		int third = (int) (i * (sinVal  * sinVal));

		total[i] = total[first] + total[second] + total[third];
		total[i] = total[i] % MaxVal;
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);
	Process();
	while (true) {
		int N;
		scanf("%d", &N);
		if (N == -1)
			break;

		printf("%d\n", total[N]);
	}

	return 0;
}
