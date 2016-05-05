#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;

//UVA 10110 Light, more light
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


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);
	while (true) {
		L N;
		scanf("%llu", &N);
		if (N == 0)
			break;

		L root = (L) (sqrt(N));

		if (root * root == N)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
