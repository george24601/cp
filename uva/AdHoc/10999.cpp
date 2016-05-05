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

int const MaxSize = 10;

char dict [100000][50];
int dictSize;
int P;

pair<char, int> tiles [MaxSize];

int play(int dictIndex)
{
	int len = strlen(dict[dictIndex]);

	int total = 0;
	int curTileIndex = 0;

	LP(i, 0, len)
	{
		while(curTileIndex < P)
		{
			if(tiles[curTileIndex].first ==  dict[dictIndex][i])
			{
				total += tiles[curTileIndex].second;
				curTileIndex++;
				goto NextChar;
			}else
				curTileIndex++;
		}

		if(curTileIndex >= P)
			return 1;

		NextChar: continue;
	}

	return total;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\1.txt", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	int N;
	cin >> N;

	LP(i, 0, N)
	{
		string buff;
		cin >> buff;

		strcpy (dict[dictSize], buff.c_str());

		if(buff.length() > 10)
			continue;

		sort(dict[dictSize], dict[dictSize] + buff.length());
		dictSize++;
	}

	int M;
	cin >> M;

	LP(i, 0, M)
	{
		cin>> P;

		LP(j, 0, P)
		{
			char c;
			int v;
			cin >> c >> v;
			tiles[j] = pair<char, int>(c, -v);
		}

		sort(tiles, tiles + P);

		int maxScore = 0;
		LP(i, 0, dictSize)
			maxScore = min(maxScore, play(i));

		printf("%d\n", -maxScore);
	}


	return 0;
}
