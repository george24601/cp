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

int const MaxSize = 20;

int Common(string a, string b) {
	int totalCommon = 0;

	for (int i = 0; i < a.length();) {
		if (a[i] == b[i] && a[i + 1] == b[i + 1]) {
			if (i + 2 < a.length() && a[i + 1] == '0') {
				if (a[i + 2] == b[i + 2]) {
					totalCommon++;
					i += 3;
				} else
					break;
			} else {
				totalCommon++;
				i += 2;
			}
		} else
			break;
	}

	//cout << a <<" " << b << " " << totalCommon << endl;
	return totalCommon;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\B.10.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		int nHands;
		cin >> nHands;

		if (nHands == 0)
			break;

		vector<string> cardSs;
		map<string, int> cardSToNC;
		LP(i, 0, nHands)
		{
			int nC;
			cin >> nC;
			vector<string> cards;

			LP(j, 0, nC)
			{
				string card;
				cin >> card;
				cards.push_back(card);
			}

			string combined;

			for (int j = nC - 1; j >= 0; j--)
				combined += cards[j];

			cardSs.push_back(combined);
			cardSToNC[combined] = nC;
		}

		sort(cardSs.begin(), cardSs.end());

		int totalNodes = cardSToNC[cardSs[0]];

		LP(i, 1, nHands)
		{
			totalNodes += cardSToNC[cardSs[i]];
			totalNodes -=
					cardSs[i - 1].length() < cardSs[i].length() ?
							Common(cardSs[i - 1], cardSs[i]) :
							Common(cardSs[i], cardSs[i - 1]);
		}

		cout << totalNodes << endl;
	}

	return 0;
}
