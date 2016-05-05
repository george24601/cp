#include <cstdio>

#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

/* UVA 913 Joana and the Odd Numbers
 * simple math
 */


int main(int argc, const char * argv[]) {

	long n;
	while (scanf("%d", &n) != EOF)
	{
		//3/2 (t+1)^2 - 9
		unsigned long long step1 = (n+1)/2;
		unsigned long long step2 = ((unsigned long long) (n+ 1)) * 3;
		unsigned long long step3 = step1 * step2;
	//	cout << "---"<<step1 << "--"<<step2 <<"--" << step3 << endl;
		unsigned long long result = step3 - 9;
		cout << result << endl;
	}

	return 0;
}
