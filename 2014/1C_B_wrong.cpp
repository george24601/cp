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
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9
#define every(iter, iterable) typeof(iterable.begin()) iter = iterable.begin(); iter != iterable.end(); iter++
//for (every(iter, iterable))
/*
 if head and tail can merge, merge them all
 once no more head-tail merge is possible
 is, within each segment, letters must be continous
 between segments, letters must be unique, otherwise, they should've been merged




 */

vector<string> segs;
int const NumLetters = 26;
int singles[NumLetters];

void countDups(string& buf) {
	bool isSingle = true;

	LP (i, 1, buf.length())
	{
		if (buf[i] != buf[i - 1]) {
			isSingle = false;
			return;
		}
	}

	singles[buf[0] - 'a']++;
}

void merge() {
	while (true) {
		vector<string> nextRound;
		bool used[200];
		memset(used, false, sizeof(used));

		LP(i, 0, segs.size())
		{
			if (used[i])
				continue;

			string curStr = segs[i];

			//cout << curStr << endl;

			LP(j, i+1, segs.size())
			{
				string potential = segs[j];

				if (curStr[curStr.size() - 1] == potential[0]) {
					used[i] = true;
					used[j] = true;
					nextRound.push_back(curStr + potential);
					break;
				} else if (curStr[0] == potential[potential.size() - 1]) {
					used[i] = true;
					used[j] = true;
					nextRound.push_back(potential + curStr);
					break;
				}

			}

			if (!used[i]) {
				nextRound.push_back(curStr);
			}
		}

		if (nextRound.size() == segs.size())
			break;
		else
			segs = nextRound;
	}
}

bool isValid() {
	bool appeared[NumLetters];
	memset(appeared, false, sizeof(appeared));

	//cout << segs.size() << endl;

	for (every(iter, segs)) {
		string curStr = *iter;

		//cout << curStr << endl;

		int lastApp[NumLetters];

		memset(lastApp, -1, sizeof(lastApp));

		LP(i, 0, curStr.size())
		{
			int li = curStr[i] - 'a';

			if (appeared[li])
				return false;

			if (lastApp[li] == -1)
				lastApp[li] = i;
			else if (lastApp[li] == i - 1)
				lastApp[li] = i;
			else
				return false;
		}

		LP(i, 0, curStr.size())
		{
			int li = curStr[i] - 'a';
			appeared[li] = true;
		}
	}

	return true;
}

LL ways() {
	LL res = 1;
	LPE(i, 1, segs.size())
	{
		res *= i;
	}

	LP(i, 0, NumLetters)
	{
		LPE(j, 1, singles[i])
			res *= j;
	}

	return res;
}

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
freopen("/Users/georgeli/Downloads/B-small-practice.in", "r", stdin);
freopen("/Users/georgeli/B_small_mine.out", "w", stdout);

	int T, N;

	cin >> T;

	LPE(cn, 1, T)
	{
		segs.clear();
		memset(singles, 0, sizeof(singles));

		cin >> N;

		LP(i, 0, N)
		{
			string buf;
			cin >> buf;

			countDups(buf);
			segs.push_back(buf);
		}

		merge();

		printf("Case #%d: %lld\n", cn, isValid() ? ways() : 0);
	}

	return 0;
}
