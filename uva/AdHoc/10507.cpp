#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

//UVa 10507:  Waking up brain
//AdHoc

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 10000;
int N;

bool active[26];
char buffer[5];

bool connection[26][26];

void Process() {

	int years = 0;
	int newActive[26];
	int sleptArea = N - 3;
	while (sleptArea > 0) {
		years++;

		LP(i, 0, 26)
			newActive[i] = false;

		int newActiveCount = 0;

		LP(i, 0, 26)
		{
			if (active[i])
				continue;

			int activeNeighbor = 0;
			LP(neighbor, 0, 26)
			{
				if (connection[i][neighbor] && active[neighbor])
					activeNeighbor++;
			}

			if (activeNeighbor >= 3) {
				newActive[i] = true;
				newActiveCount++;
			}

		}

		if (newActiveCount == 0) {
			printf("THIS BRAIN NEVER WAKES UP\n");
			return;
		}

		sleptArea -= newActiveCount;

		LP(i, 0, 26)
		{
			if (newActive[i])
				active[i] = true;
		}

	}

	printf("WAKE UP IN, %d, YEARS\n", years);
}

int main(int argc, const char * argv[]) {

	///freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d", &N) == 1) {
		LP(i, 0, 26)
		{
			active[i] = false;

			LP(j, 0, 26)
				connection[i][j] = false;

		}

		int M = 0;
		scanf("%d", &M);

		scanf("%s", buffer);

		LP(i, 0, 3)
			active[buffer[i] - 'A'] = true;

		LP(i, 0, M)
		{
			scanf("%s", buffer);
			int first = buffer[0] - 'A';
			int second = buffer[1] - 'A';

			connection[first][second] = true;
			connection[second][first] = true;

		}

		Process();

	}

	return 0;
}
