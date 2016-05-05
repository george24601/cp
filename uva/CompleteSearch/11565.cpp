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

//UVa 11571 Simple Equations
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

L A, B, C;

const int OM = 1000000;

L SqRoot_r(L target, L min, L max) {

	if (min >= max)
		return min;

	L mid = (min + max) / 2;

	if (mid * mid > target)
		return SqRoot_r(target, min, mid - 1);
	else if (mid * mid == target)
		return mid;
	else
		return SqRoot_r(target, mid + 1, max);

}

int Cur_r(L target, L min, L max) {
	if (min >= max)
		return min;

	L mid = (min + max) / 2;

	if (mid * mid * mid > target)
		return Cur_r(target, min, mid - 1);
	else if (mid * mid * mid == target)
		return mid;
	else
		return Cur_r(target, mid + 1, max);
}

bool SearchNeg(int y) {
	L absY = abs(y);

	if (B % absY != 0)
		return false;

	L absXZ = B / absY;

	if (C <= absY * absY)
		return false;

	L X2PZ2 = C - absY * absY;

	L XMZ2 = X2PZ2 + 2 * absXZ;

	if (XMZ2 == 0)
		return false;

	L ZMX = SqRoot_r(XMZ2, 0, 2500000);

	if (ZMX * ZMX != XMZ2)
		return false;

	L XPZ = A + absY;
	L TwoZ = ZMX + XPZ;

	L Z = TwoZ / 2;

	if (TwoZ % 2 != 0 || Z < XPZ)
		return false;

	L absX = Z - XPZ;

	if (absX + y == 0)
		return false;

	if (absY * absY + absX * absX + Z * Z != C)
			return false;

	printf("-%llu %d %llu\n", absX, y, Z);

	return true;
}

bool SearchZero() {

	/*
	 L root = SqRoot_r(2 * C, 0, 3500000);

	 if (A > root)
	 return false;
	 */

	int delta = 2 * C - A * A;

	if (delta <= 0)
		return false;

	L root = SqRoot_r(delta, 0, 2000000);

	if (root * root != delta)
		return false;

	if (A == root)
		return false;

	if (A > root) {
		L y = A - root;

		if (y % 2 != 0)
			return false;

		y = y / 2;

		printf("%d %llu %llu\n", 0, y, A - y);
	} else {

		L absX = root - A;

		if (absX % 2 != 0)
			return false;

		absX = absX / 2;

		printf("%llu %d %llu\n", absX, 0, A + absX);
	}

	return true;
}

bool SearchPos(int x) {

	L absX = x;

	if (B % absX != 0)
		return false;

	L absYZ = B / absX;

	if (A < absX)
		return false;
	L YPZ = A - absX;

	if (C <= absX * absX)
		return false;
	L Y2PZ2 = C - absX * absX;

	if (Y2PZ2 <= 2 * absYZ)
		return false;

	L YMZ2 = Y2PZ2 - 2 * absYZ;

	L ZMY = SqRoot_r(YMZ2, 0, 2500000);

	if (ZMY * ZMY != YMZ2)
		return false;

	L TwoZ = ZMY + YPZ;

	L Z = TwoZ / 2;

	if (TwoZ % 2 != 0 || YPZ < Z)
		return false;

	L Y = YPZ - Z;

	if (x == Y)
		return false;

	if (Y * Y + absX * absX + Z * Z != C)
			return false;

	printf("%d %llu %llu\n", x, Y, Z);

	return true;
}

void Process() {

	if (B == 0) {
		if (SearchZero())
			return;

	} else {
		int cuR = Cur_r(B, 0, 2000000);

		for (int y = -1; y >= -cuR; y--) {
			if (SearchNeg(y))
				return;
		}

		LPE(x, 1, cuR)
		{
			if (SearchPos(x))
				return;
		}
	}

	printf("No solution.\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	LP(i, 0, N)
	{
		scanf("%llu %llu %llu", &A, &B, &C);

		Process();

	}

	return 0;
}

