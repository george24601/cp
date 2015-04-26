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

//UVa 639 dont get rooked
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n;
bool walls[4][4];
int rows[4];

int Count(int choice) {
	int num = 0;

	LP(i, 0 , n)
	{
		if (((choice >> i) & 1) == 1)
			num++;
	}

	return num;
}

bool Occupied(int row, int colIndex) {
	return ((rows[colIndex] >> row) & 1) == 1;
}

bool ValidRow(const int row, const int colIndex) {

	for (int curCol = colIndex - 1; curCol >= 0; curCol--) {
		if (Occupied(row, curCol))
			return false;

		if (walls[row][curCol])
			return true;
	}

	return true;
}

bool ValidCol(const int row, const int col, const int choice) {
	for (int curRow = row - 1; curRow >= 0; curRow--) {

		if (((choice >> curRow) & 1) == 1)
			return false;

		if (walls[curRow][col])
			return true;
	}

	return true;
}

bool Valid(int colIndex, int choice) {
	LP(row, 0 , n)
	{
		if (((choice >> row) & 1) == 0)
			continue;

		if (walls[row][colIndex])
			return false;

		bool good = ValidRow(row, colIndex) && ValidCol(row, colIndex, choice);

		if (!good)
			return false;
	}

	return true;
}

int Process_r(int colIndex) {
	if (colIndex >= n)
		return 0;

	int choices = pow(2, n) - 1;

	int curMax = 0;
	LPE(choice, 0, choices)
	{
		if (!Valid(colIndex, choice))
			continue;

		int numR = Count(choice);
		rows[colIndex] = choice;
		int remaining = Process_r(colIndex + 1);

		curMax = Max(remaining + numR, curMax);
	}

	return curMax;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d", &n)) {
		if (n == 0)
			break;

		char buff[4];

		LP(i, 0, n)
		{
			scanf("%s", buff);

			LP(j, 0, n)
			{
				if (buff[j] == '.')
					walls[i][j] = false;
				else
					walls[i][j] = true;
			}
		}

		printf("%d\n", Process_r(0));
	}

	return 0;
}
