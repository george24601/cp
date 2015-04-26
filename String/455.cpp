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
#define INF 2000000000
#define Ep 1e-9

int const MaxSize = 90;
string W;
int wLen;
int T[MaxSize];

void BuildT() {
	T[0] = -1; //special case
	T[1] = 0; //0 because we have no suffix right now

	int i = 2;
	int tI = 0;

	while (i < wLen) {
		//if(i >= 6)
		//	printf("%d %d %d\n", i, tI, T[tI]);

		if (W[i - 1] == W[tI]) {
			//i - 1 can extend an existing suffix which is also a prefix
			T[i] = tI + 1;
			i += 1;
			tI = tI + 1;
		} else if (tI > 0) {
			//so the suffix ending at i-1 will not work for current starting point, can we try a shorter suffix?
			//notice the suffix ending at i-2 has T[tI] matches already, so we will try that match's starting point,i.e, that matching's length
			tI = T[tI];
		} else {
			//tI== 0, i.e., first character doesnt match
			T[i] = 0;
			i += 1;
		}
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int caseNum;
	cin >> caseNum;

	//cout << W;
	getline(cin, W);
	//cout << W;
	LPE(cn, 1, caseNum)
	{
		if (cn > 1)
			printf("\n");

		getline(cin, W);
	//cout << W;
		getline(cin, W);
		wLen = W.size();

		//cout << W << "!!" << endl;

		BuildT();

		int firstSegLen = wLen - 1 - T[wLen - 1];

		if (firstSegLen > 0 && wLen % firstSegLen == 0) {
			int numSeg = wLen / firstSegLen;

			LP(i, 0, numSeg)
			{
				LP(j, 0, firstSegLen)
				{
					if (W[i * firstSegLen + j] == W[j])
						continue;

					goto Bad;
				}

			}
		} else {
			goto Bad;
		}

		printf("%d\n", firstSegLen);
		continue;

		Bad: printf("%d\n", wLen);
	}

	return 0;
}
