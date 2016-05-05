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
	int caseNum = 0;
	while(true)
	{
		scanf("%s", &word);

		caseNum++;

		if (strcmp(word, "#") == 0)
			break;
		else if (strcmp(word, "HELLO") == 0)
			printf("Case %d: ENGLISH\n", caseNum);
		else if (strcmp(word, "HOLA") == 0)
			printf("Case %d: SPANISH\n", caseNum);
		else if (strcmp(word, "HALLO") == 0)
			printf("Case %d: GERMAN\n", caseNum);
		else if (strcmp(word, "BONJOUR") == 0)
			printf("Case %d: FRENCH\n", caseNum);
		else if (strcmp(word, "CIAO") == 0)
			printf("Case %d: ITALIAN\n", caseNum);
		else if (strcmp(word, "ZDRAVSTVUJTE") == 0)
			printf("Case %d: RUSSIAN\n", caseNum);
		else 
			printf("Case %d: UNKNOWN\n", caseNum);


	}


	return 0;
}
