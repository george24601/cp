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

int const MaxSize = 1000010;

int nums[MaxSize];
int n;

/*

 at each new item
 if not exist
 current length++
 if exisits
 truncate current lenght
 get last existing index
 update the last exisitng index
 update current length
 */

void Solve() {
	int maxSize = 0;

	int curSize = 0;

	map<int, int> firstAt;
	//firstAt.clear();

	LP(i, 0, n)
	{
		int num = nums[i];

		if (firstAt.count(num) == 0) {
			curSize++;
			maxSize = max(maxSize, curSize);
		} else {
			int lastAt = firstAt[num];

			int curPStart = i - curSize;

			if (curPStart > lastAt) {
				curSize++;
				maxSize = max(maxSize, curSize);
			} else {
				curSize = i - lastAt;
				//maxSize = max(maxSize, curSize);
			}
		}

		firstAt[num] = i;
	}

	printf("%d\n", maxSize);
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\A.1.dat2", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d", &n);

		LP(i, 0, n)
			scanf("%d", &nums[i]);

		Solve();

	}

	return 0;
}
