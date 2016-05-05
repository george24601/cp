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

//UVa 10006 Carmichael Numbers
//mathematics
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int ans[] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341,
		41041, 46657, 52633, 62745, 63973 };
L n;

L PowMod(L a, L pow) {
	if (pow == 1)
		return a % n;

	L half = PowMod(a, pow / 2);
	L twoH = (half * half) % n;

	if (pow % 2 == 0)
		return twoH;
	else
		return (twoH * a) % n;
}

bool IsPrime() {

	for (L i = 2; i < n; i++) {
		if (i * i > n)
			break;

		if (n % i == 0)
			return false;

	}

	return true;
}

bool IsChar() {

	LP(i, 0, 15)
	{
		if (ans[i] == n)
			return true;
	}

	return false;

	/*
	 for (L a = 2; a < n; a++) {
	 if (PowMod(a, n) != a)
	 return false;
	 }

	 return !IsPrime();
	 */
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {

		scanf("%llu", &n);

		if (n == 0)
			break;

		if (IsChar())
			printf("The number %llu is a Carmichael number.\n", n);
		else
			printf("%llu is normal.\n", n);

	}

	return 0;
}

