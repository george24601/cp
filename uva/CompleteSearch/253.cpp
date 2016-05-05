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

//UVa 253 cube painting
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

char source[8];
char target[8];

void RotateH() {
	char One = source[1];

	source[1] = source[5];
	source[5] = source[6];
	source[6] = source[2];
	source[2] = One;
}

void RotateV() {
	char Two = source[2];

	source[2] = source[4];
	source[4] = source[5];
	source[5] = source[3];
	source[3] = Two;

}

void RotateZ() {
	char One = source[1];

	source[1] = source[4];
	source[4] = source[6];
	source[6] = source[3];
	source[3] = One;

}


bool Same() {
	LPE(i, 1, 6)
	{
		if (source[i] != target[i])
			return false;

	}

	return true;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	char buff[20];
	while (scanf("%s", buff) != EOF) {
		target[0] = 'A';
		source[0] = 'A';

		LP(i, 0, 6)
			target[i + 1] = buff[i];

		LP(i, 6, 12)
			source[i - 5] = buff[i];

		LP(x, 0, 4)
		{
			RotateH();

			LP(y, 0, 4)
			{
				RotateV();

				LP(z, 0, 4)
				{
					RotateZ();

					if (Same()) {
						printf("TRUE\n");
						goto Next;

					}
				}
			}
		}

		printf("FALSE\n");

		Next: continue;
	}

	return 0;
}
