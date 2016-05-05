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

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\C.1.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		int gs[MaxSize], ss[MaxSize], bs[MaxSize];
		int c;
		int cg, cs, cb;
		cin >> c;

		if (c == 0)
			break;

		LP(i, 0, c)
		{
			string name;
			int g, s, b;
			cin >> name >> g >> s >> b;

			gs[i] = g;
			ss[i] = s;
			bs[i] = b;

			if (name == "Canada") {
				cg = g;
				cs = s;
				cb = b;
			}
		}

		LPE (gw, 1, 3)
		{
			LPE(sw, 1, 3)
			{
				LPE(bw, 1, 3)
				{
					int ct = gw * cg + sw * cs + bw * cb;

					bool canWin = true;

					LP(i, 0, c)
					{
						int weight = gw * gs[i] + sw * ss[i] + bw * bs[i];

						if (weight > ct) {
							canWin = false;
							break;
						}
					}

					if (canWin) {
						printf("Canada wins!\n");
						goto NextCase;
					}
				}
			}
		}

		printf("Canada cannot win.\n");

		NextCase: continue;
	}

	return 0;
}
