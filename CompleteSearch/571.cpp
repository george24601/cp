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
using namespace std;

//UVa 571 Jugs
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int cA, cB, N;

int state[1001][1001];
int prev[1001][1001];

bool done;

void Print_r(int a, int b) {
	if (a == 0 && b == 0)
		return;

	if (prev[a][b] == 1) {
		Print_r(state[a][b], b);
		printf("fill A\n");

	} else if (prev[a][b] == 2) {

		Print_r(a, state[a][b]);
		printf("fill B\n");
	} else if (prev[a][b] == 3) {

		Print_r(state[a][b], b);
		printf("empty A\n");
	} else if (prev[a][b] == 4) {

		Print_r(a, state[a][b]);
		printf("empty B\n");
	} else if (prev[a][b] == 5) {
		Print_r(state[a][b], a + b - state[a][b]);

		printf("pour A B\n");

	} else if (prev[a][b] == 6) {
		Print_r(a + b - state[a][b], state[a][b]);

		printf("pour B A\n");
	}

}

void Process_r(int a, int b, int prevAction, int prevState) {

	if (done)
		return;

	if (prev[a][b] == 0) {
		prev[a][b] = prevAction;
		state[a][b] = prevState;

		if (b == N) {
			done = true;
			//backtrack here

			Print_r(a, b);
			printf("success\n");
			return;
		}
	} else
		return; //visited already

	Process_r(cA, b, 1, a);

	Process_r(a, cB, 2, b);

	Process_r(0, b, 3, a);

	Process_r(a, 0, 4, b);

	if (a + b > cB)
		Process_r(a + b - cB, cB, 5, a);
	else
		Process_r(0, a + b, 5, a);

	if (a + b > cA)
		Process_r(cA, a + b - cA, 6, b);
	else
		Process_r(0, a + b, 6, b);

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d %d", &cA, &cB, &N) == 3) {

		LPE(i, 0, cA)
		{
			LPE(j, 0, cB)
				prev[i][j] = 0;
		}

		done = false;
		Process_r(0, 0, 0, -1);
		done = false;
	}

	return 0;
}

