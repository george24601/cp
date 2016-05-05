#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12149 Feyman 
//simple math

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;


int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	char word[50];
	int N;
	scanf("%d", &N);


	LP(i, 0, N)
	{
		scanf("%s", &word);

		if (strlen(word) == 5)
		{
			printf("3\n");
		}else
		{

			int totalDiff = 0;

			if (word[0] != 'o')
				totalDiff++;
			if (word[1] != 'n')
				totalDiff++;
			if (word[2] != 'e')
				totalDiff++;


			if (totalDiff <= 1)
				printf("1\n");
			else
				printf("2\n");
		}



	}


	return 0;
}
