#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;

//UVa 10730 - Antiarithmetic?
//Complete Search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b

const int MaxSize = 10000;

int n;
int indices[MaxSize];

void Process() {
	LP(i, 0, n)
	{
		for (int diff = 1; (i + 2 * diff) < n; diff++) {
			int firstIndex = indices[i];
			int secondIndex = indices[diff + i];
			int thirdIndex = indices[2 * diff + i];

			if ((firstIndex < secondIndex && secondIndex < thirdIndex)
					|| (firstIndex > secondIndex && secondIndex > thirdIndex)) {
				cout << "no" << endl;
				return;
			}
		}
	}

	cout << "yes" << endl;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d:", &n) && n) {

		int num;
		LP(i, 0, n)
		{
			scanf("%d", &num);
			indices[num] = i;
		}

		Process();
	}

	return 0;
}
