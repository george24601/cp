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

int const MaxSize = 26;

int alias[MaxSize];
int prim[MaxSize];
SAL str;
string line;

bool defined[MaxSize];

int result[MaxSize][MaxSize];

void Parse() {
	int i = 5;

	while (line[i] < 'A' || line[i] > 'Z')
		i++;

	int lh = line[i] - 'A';

	defined[lh] = true;

	int eqIndex = line.find('=');

	i = eqIndex + 1;

	while (line[i] == ' ')
		i++;

	char next = line[i];

	if (next <= 'Z' && next >= 'A') {
		alias[lh] = next - 'A';
	} else if (next == 'i') {
		prim[lh] = 26;
	} else if (next == 'r') {
		prim[lh] = 27;

	} else if (next == 'c') {
		prim[lh] = 28;
	} else {
		i = line.find("(") + 1;

		while (true) {
			if (line[i] == ' ') {
				i++;
				continue;
			}

			if (line[i] == ')')
				break;

			str[lh].push_back(line[i] - 'A');
			i++;
		}
	}
}

bool Same(int const i, int const j) {
	if (i == j)
		return true;

	if (result[i][j] >= 0)
		return result[i][j];

	if (alias[i] >= 0)
		result[j][i] = result[i][j] = Same(alias[i], j);
	else if (alias[j] >= 0)
		result[j][i] = result[i][j] = Same(i, alias[j]);
	else if (prim[i] > 0 || prim[j] > 0)
		result[j][i] = result[i][j] = prim[i] == prim[j];

	if (result[i][j] >= 0)
		return result[i][j];

	if (str[i].size() != str[j].size()) {
		result[j][i] = result[i][j] = 0;
		return result[i][j];
	}

	result[j][i] = result[i][j] = 2; //processing
	LP(ii, 0, str[i].size())
	{
		if (!Same(str[i][ii], str[j][ii])) {
			result[j][i] = result[i][j] = 0;
			return result[i][j];
		}
	}

	result[j][i] = result[i][j] = 1;
	return result[i][j];
}

void Process() {
	LP(i, 0, MaxSize)
	{
		if (!defined[i])
			continue;

		bool already = false;

		LP(j, 0, i)
		{
			if (!defined[j])
				continue;

			if (Same(i, j))
				already = true;
		}

		if (already)
			continue;

		vector<int> ans;
		LP(j, i+1, MaxSize)
		{
			if (!defined[j])
				continue;

			if (Same(i, j))
				ans.push_back(j);
		}

		printf("%c", i + 'A');

		LP(j, 0, ans.size())
			printf(" %c", ans[j] + 'A');

		printf("\n");
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\E.0.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	bool isFirst = true;
	bool done = false;
	while (!done) {
		str = SAL(MaxSize);
		memset(prim, -1, sizeof(prim));
		memset(alias, -1, sizeof(alias));
		memset(defined, false, sizeof(defined));

		LP(i, 0, MaxSize)
			memset(result[i], -1, sizeof(result[i]));

		if (isFirst)
			isFirst = false;
		else
			printf("\n");

		while (true) {
			getline(cin, line);

			if (line == "-") {
				Process();
				break;
			} else if (line == "--") {
				Process();
				done = true;
				break;
			}

			Parse();
		}

	}
	return 0;
}
