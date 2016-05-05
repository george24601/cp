#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 10354 avoiding your boss
//SSSP
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxSize = 100;

int nums[MaxSize];

int n;
stringstream ss;

void Flip(int const index) {
	int start = 0;
	int end = index;

	while (start < end) {
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;

		start++;
		end--;
	}

	cout << n - index << " ";
}

void Process_r(int const endIndx) {
	if (endIndx < 0) {
		cout << "0" << endl;
		return;
	}

	int curMax = -1;
	int curMaxIndex;

	LPE(i, 0, endIndx)
	{
		if (nums[i] > curMax) {
			curMax = nums[i];
			curMaxIndex = i;
		}
	}

	if (curMaxIndex == endIndx) {
		Process_r(endIndx - 1);
		return;
	}

	if (curMaxIndex != 0)
		Flip (curMaxIndex);

	Flip(endIndx);

	Process_r(endIndx - 1);
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	string line;
	while (getline(cin, line)) {

		ss.clear();
		ss.str(line);
		int num;
		n = 0;

		while (ss >> num) {
			nums[n] = num;
			n++;
		}

		cout << line << endl;
		Process_r(n - 1);
	}

	return 0;
}
