#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10491 Cows and Cars
//Probability

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;
int Cow, Car, Show;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d %d", &Cow, &Car, &Show) == 3) {
		int top = (Car * (Car - 1)) + (Car * Cow);
		int bottom = (Cow + Car) * (Cow + Car - Show - 1);

		printf("%.5lf\n", (double) top / (double) bottom);
	}

	return 0;
}
