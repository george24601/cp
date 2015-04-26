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

int const MaxSize = 365;

double change(double amount)
{
	double first = amount * 0.97;

	double toReturn = (int)(first * 100)/100.0;
	return toReturn;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\A.1.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		int d;
		cin >> d;

		if(0 == d)
			break;

		double ca[MaxSize];
		double us[MaxSize];

		double rates[MaxSize];

		LP(i, 0, d)
			cin >> rates[i];

		ca[0] = 1000;
		us[0] = change(1000 / rates[0]);

		LP(i, 1, d)
		{
			ca[i] = max(ca[i-1], change(us[i -1] * rates[i]));
			us[i] = max(us[i -1], change(ca[i - 1]/rates[i]));
		}

		double result = max(ca[d-1], change(us[d - 1]*rates[d - 1]));

		printf("%.2lf\n", result);
	}

	return 0;
}
