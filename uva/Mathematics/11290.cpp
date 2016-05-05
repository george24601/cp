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

L tw[21];

L T(int n) {
	return tw[n];
}

pair<int, L> GetFirstSize(int size, L m) {

	if (1 == size)
		return pair<int, L>(1, 1);

	L totalNum = 0;

	for (int fs = size; fs >= 1; fs--) {
		L firstChoices = T(fs - 1);
		L secondChoices = T(size - fs);

		L newTotal = totalNum + firstChoices * secondChoices;

		if (newTotal >= m)
			return pair<int, L>(fs, m - totalNum);
		else
			totalNum = newTotal;

	}

	return pair<int, L>(0, 0);
}

string P_r(int size, L rank) {
	if (rank < 1 || rank > T(size)) //check this
		return "";

	pair<int, L> fsAndm = GetFirstSize(size, rank);
	int firstSize = fsAndm.first;
	L m = fsAndm.second;

	if (firstSize == size) {
		string result = "";

		if (size > 1)
			result = P_r(size - 1, m);

		return "E" + result + "S";

	} else if (firstSize < size && firstSize >= 1) {
		L secondHalfChoices = T(size - firstSize);

		string first = P_r(firstSize, (m - 1) / secondHalfChoices + 1);
		string second = P_r(size - firstSize, (m - 1) % secondHalfChoices + 1);

		return first + second;

	} else {
		return "";
	}
}

void ComputeT() {
	tw[0] = 1;
	tw[1] = 1;

	LPE(size, 2, 20)
	{
		tw[size] += tw[size - 1];

		tw[size] += tw[size - 1];

		LP(first, 2, size)
			tw[size] += tw[first - 1] * tw[size - first];
	}

}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\A.1.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	ComputeT();

	while (true) {
		int n, m;
		scanf("%d %d", &n, &m);

		if (0 == n && 0 == m)
			break;

		if (n == 1) {
			if (m == 1)
				cout << endl;
			else
				cout << "ERROR" << endl;
		} else {
			string result = P_r(n - 1, m);

			if (result.length() != 2 * n - 2)
				cout << "ERROR" << endl;
			else
				cout << result << endl;
		}
	}

	return 0;
}
