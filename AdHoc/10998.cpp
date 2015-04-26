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

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\D.1.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	int caseNum = 0;

	while (true) {
		double H, V, h, v;
		scanf("%lf %lf %lf %lf", &H, &V, &h, &v);

		if (H == 0 && V == 0 && h == 0 && v == 0)
			break;

		caseNum++;

		int n;
		scanf("%d", &n);

		printf("Case %d:\n", caseNum);

		LP(i, 0, n)
		{
			double x, y;
			scanf("%lf %lf", &x, &y);

			double tlx = 0, tly = V, brx = H, bry = 0;
			bool black = true;
			while (true) {
				double parX = tlx * (1-h) + brx * h;
				double parY = bry * (1-v) + tly * v;

				if(parX < x && parY < y)
				{
					tlx = parX;
					bry = parY;

					black =!black;
				}else if(parX > x && parY > y)
				{
					tly = parY;
					brx = parX;

					black =!black;
				}else
					break;

			}

			if (black)
				printf("black\n");
			else
				printf("white\n");
		}

	}

	return 0;
}
