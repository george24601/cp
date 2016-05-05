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
using namespace std;

//UVa 10336 Rank the Languages
//graph - DFS
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

int H, W;

const int MaxSize = 500;
bool visited[MaxSize][MaxSize];

int pixel[MaxSize][MaxSize];

bool Valid(int row, int col, int curNum) {
	if (row < 0 || row >= H)
		return false;
	if (col < 0 || col >= W)
		return false;

	return pixel[row][col] == curNum;
}

void V_r(int row, int col) {
	if (visited[row][col])
		return;
	else
		visited[row][col] = true;

	int nextXs[13] = { row - 1, row, row, row + 1 };
	int nextYs[13] = { col, col + 1, col - 1, col };
	int choices = 4;

	LP(i, 0, choices)
	{
		if (Valid(nextXs[i], nextYs[i], pixel[row][col]))
			V_r(nextXs[i], nextYs[i]);
	}
}

bool sf(pair<char, int> a, pair<char, int> b) {
	if (a.second > b.second)
		return true;
	else if (a.second < b.second)
		return false;

	return a.first < b.first;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	scanf("%d", &caseNum);

	LPE(numCase, 1, caseNum)
	{
		scanf("%d %d", &H, &W);

		LP(i, 0, H)
		{
			char line[W];

			scanf("%s", line);

			LP(j, 0, W)
			{
				pixel[i][j] = line[j] - 'a';

				visited[i][j] = false;
			}
		}

		map<int, int> charToCount;

		LP(i, 0, H)
		{
			LP(j, 0, W)
			{
				if (!visited[i][j]) {

					V_r(i, j);

					charToCount[pixel[i][j]]++;
				}
			}
		}

		vector< pair<int, int> > toSort;

		for (map<int, int>::iterator it = charToCount.begin();
				it != charToCount.end(); it++) {
			pair<int, int> p = make_pair(it->first, it->second);
			toSort.push_back(p);
		}

		sort(toSort.begin(), toSort.end(), sf);

		printf("World #%d\n", numCase);

		LP(i, 0, toSort.size())
			printf("%c: %d\n", toSort[i].first + 'a', toSort[i].second);
	}

	return 0;
}

