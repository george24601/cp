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
using namespace std;

//UVa 11959 Dice
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

char source[10];
char target[10];

void RotateX() {
	char Zero = target[0];

	target[0] = target[4];
	target[4] = target[1];
	target[1] = target[2];
	target[2] = Zero;
}

void RotateY() {
	char Two = target[2];

	target[2] = target[5];
	target[5] = target[4];
	target[4] = target[3];
	target[3] = Two;
}

void RotateZ() {
	char Zero = target[0];

	target[0] = target[5];
	target[5] = target[1];
	target[1] = target[3];
	target[3] = Zero;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LP(i, 0, T)
	{
		scanf("%s %s", source, target);

		LP(x, 0, 4)
		{
			RotateX();
			LP(y, 0, 4)
			{
				RotateY();
				LP(z, 0, 4)
				{
					RotateZ();

					if (strcmp(source, target) == 0) {
						printf("Equal\n");
						goto Next;
					}

				}
			}

		}

		printf("Not Equal\n");
		Next: continue;
	}

	return 0;
}

