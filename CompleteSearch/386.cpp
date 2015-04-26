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

//UVa 386 perfect cubes
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int GetCRoot_r(int cube, int min, int max) {
	if (min > max)
		return -1;

	if (min == max) {
		if (pow(min, 3) == cube)
			return min;
		else
			return -1;
	}

	int mid = (min + max) / 2;

	int midC = pow(mid, 3);

	if (midC > cube)
		return GetCRoot_r(cube, min, mid - 1);
	else if (midC == cube)
		return mid;
	else
		return GetCRoot_r(cube, mid + 1, max);
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	LPE(cube , 2, 200)
	{
		int targetC = pow(cube, 3);
		LP(first, 2, cube)
		{
			int firstC = pow(first, 3);
			LP(second, first, cube)
			{
				int secondC = pow(second, 3);

				int thirdC = targetC - firstC - secondC;

				if (thirdC < secondC)
					break;

				int c = GetCRoot_r(thirdC, 1, cube);

				if (c > 0) {
					printf("Cube = %d, Triple = (%d,%d,%d)\n", cube, first,
							second, c);
				}
			}
		}
	}

	return 0;
}

