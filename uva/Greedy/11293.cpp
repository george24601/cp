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

int const MaxSize = 2510;

string names[MaxSize];
PII abilities[MaxSize];

int minDiff[MaxSize][MaxSize / 2];
bool pick[MaxSize][MaxSize / 2];

int k;

int FirstRound(int k) {
	if(k == 2)
		return 1;

	int totalRound = 0;

	while(pow(2, totalRound) < k)
	{
		totalRound ++;
	}

	int lastRoundNum = pow(2, totalRound -1);

	LPE(pair, 1, k/2)
	{
		int byes = k - pair * 2;

		if(byes + pair <= lastRoundNum)
			return pair;
	}

	return -1;
}

int DFS_r(int nk, int nm) {
	if (minDiff[nk][nm] == -1)
		minDiff[nk][nm] = -2;
	else
		return minDiff[nk][nm];

	if (nm == 0) {
		minDiff[nk][nm] = 0;
		return minDiff[nk][nm];

	} else if (nk < nm * 2) {
		return minDiff[nk][nm];
	}

	int pickDiff = (abilities[nk].first - abilities[nk - 1].first);
	pickDiff = pickDiff * pickDiff;
	int pickAfter = DFS_r(nk - 2, nm - 1);

	if (pickAfter < 0)
		pickDiff = -2;
	else
		pickDiff += pickAfter;

	int noPickDiff = DFS_r(nk - 1, nm);

	if (noPickDiff >= 0 && pickDiff >= 0) {
		minDiff[nk][nm] = min(noPickDiff, pickDiff);
		pick[nk][nm] = pickDiff < noPickDiff;
	} else if (noPickDiff >= 0) {
		minDiff[nk][nm] = noPickDiff;
		pick[nk][nm] = false;
	} else if (pickDiff >= 0) {
		minDiff[nk][nm] = pickDiff;
		pick[nk][nm] = true;
	} else {
		minDiff[nk][nm] = -2;
	}

	return minDiff[nk][nm];
}

void BT_r(int nk, int nm) {

	if (0 == nk)
		return;

	if (pick[nk][nm])
		BT_r(nk - 2, nm - 1);
	else {
		cout << names[abilities[nk].second] << endl;
		BT_r(nk - 1, nm);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\D.1.dat", "r", stdin);
	//freopen("C:\\Test\\out", "w", stdout);

	bool isFirst = true;

	while (true) {
		cin >> k;

		if(k == 0)
			break;

		if(isFirst)
			isFirst = false;
		else
			cout << endl;

		LPE(i, 1, k)
		{
			cin >> names[i];

			int a;
			cin >> a;
			abilities[i] = PII(a, i);

			memset(pick[i], false, sizeof(pick[i]));
			memset(minDiff[i], -1, sizeof(minDiff[i]));
		}

		abilities[0] = PII(-1, -1);
		memset(pick[0], false, sizeof(pick[0]));
		memset(minDiff[0], -1, sizeof(minDiff[0]));

		int matchInFirst = FirstRound(k);

		sort(abilities + 1, abilities + k + 1);

		DFS_r(k, matchInFirst);

		BT_r(k, matchInFirst);
	}

	return 0;
}
