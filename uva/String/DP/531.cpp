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

//UVa 164 String Computer
//string DP
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 110;
const int INF = 2000000000;

int match[MaxSize][MaxSize];

vector<string> first;
vector<string> second;
char op[MaxSize][MaxSize];

bool isFirst;
void Print_r(int fI, int sI) {
	if (fI <= 0 || sI <= 0)
		return;

	if (op[fI][sI] == 'I') {
		Print_r(fI, sI - 1);

		//length here
	} else if (op[fI][sI] == 'C') {
		Print_r(fI - 1, sI - 1);

	} else if (op[fI][sI] == 'D') {
		Print_r(fI - 1, sI);

	} else {
		Print_r(fI - 1, sI - 1);

		if (isFirst)
			isFirst = false;
		else
			cout << " ";

		cout << first[fI - 1];
	}
}

void Process() {
	int fLen = first.size();
	int sLen = second.size();
	isFirst = true;

	//init 00

	match[0][0] = 0;
	op[0][0] = 'N';

	//init r0
	LPE(si, 1, sLen)
	{
		match[0][si] = match[0][si - 1]; //just keep insertiong
		op[0][si] = 'I';
	}

	LPE(fi, 1, fLen)
	{
		match[fi][0] = match[fi - 1][0]; //just keepdeleting
		op[fi][0] = 'D';
	}

	//init col 0

	LPE(fl, 1, fLen)
	{
		string fc = first[fl - 1];
		LPE(sl, 1, sLen)
		{
			string sc = second[sl - 1];

			int cC =
					fc == sc ?
							match[fl - 1][sl - 1] + 1 :
							match[fl - 1][sl - 1] - INF; //change last

			int iC = match[fl][sl - 1]; //add last
			int dC = match[fl - 1][sl]; //remove last

			if (cC >= iC && cC >= dC) {
				match[fl][sl] = cC;
				op[fl][sl] = fc == sc ? 'N' : 'C';

			} else if (iC >= cC && iC >= dC) {
				match[fl][sl] = iC;
				op[fl][sl] = 'I';

			} else {
				match[fl][sl] = dC;
				op[fl][sl] = 'D';
			}
		}
	}

	Print_r(fLen, sLen);
	cout << endl;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	char buff[50];

	while (scanf("%s", buff) == 1) {

		first.clear();
		second.clear();

		first.push_back(string(buff));

		while (true) {
			scanf("%s", buff);

			if (buff[0] == '#')
				break;

			first.push_back(string(buff));
		}

		while (true) {
			scanf("%s", buff);

			if (buff[0] == '#')
				break;

			second.push_back(string(buff));
		}

		Process();

	}

	return 0;
}
