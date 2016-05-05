#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

/* UVA 11616: Roman numerals
 * ad hoc
 */

const char I = 'I';
const int IVal = 1;
const char V = 'V';
const int VVal = 5;
const char X = 'X';
const int XVal = 10;
const char L = 'L';
const int LVal = 50;
const char C = 'C';
const int CVal = 100;
const char D = 'D';
const int DVal = 500;
char M = 'M';
const int MVal = 1000;


void ValToLetter_r(int i)
{
	if (i == 0)
	{
		cout << endl;
	}else if (i >= 1000)
	{
		cout << M;
		ValToLetter_r(i - MVal);
	}else if (i >= 900)
	{

		cout << C << M;
		ValToLetter_r(i - MVal + CVal);
	}else if (i >= 500)
	{
		cout << D;
		ValToLetter_r(i - DVal);
	}else if (i >= 400)
	{
		cout << C << D;
		ValToLetter_r(i - DVal + CVal);
	}else if (i >= 100)
	{
		cout << C;
		ValToLetter_r(i - CVal);
	}else if (i >= 90)
	{
		cout << X << C;
		ValToLetter_r(i - CVal + XVal);
	}else if(i >= 50)
	{
		cout << L;
		ValToLetter_r(i - LVal);
	}else if (i >= 40)
	{
		cout << X << L;
		ValToLetter_r(i - LVal + XVal);
	}else if (i >= 10)
	{
		cout << X;
		ValToLetter_r(i - XVal);
	}else if (i >= 9)
	{
		cout <<I << X;
		ValToLetter_r(i - XVal + IVal);
	}else if (i >= 5)
	{
		cout << V;
		ValToLetter_r(i - VVal);
	}else if (i >= 4)
	{
		cout << I << V;
		ValToLetter_r(i - VVal + IVal);
	}else if (i >= 1)
	{
		cout << I;
		ValToLetter_r(i - IVal);
	}
}

int Val(char c)
{
	if (c == M)
		return MVal;
	if (c == D)
		return DVal;
	if (c == C)
		return CVal;
	if (c == L)
		return LVal;
	if (c == X)
		return XVal;
	if (c == V)
		return VVal;
	if (c == I)
		return IVal;

	return 0;
}

void LetterToValue_r(string line, int index, int sum)
{
	if (index == line.length())
	{
		cout << sum << endl;
		return;
	}

	char curChar = line[index];

	if (index == line.length() -1)
	{
		LetterToValue_r(line, index + 1, sum + Val(curChar));
	}else if (curChar == M || curChar == D || curChar == L || curChar == V)
	{
		LetterToValue_r(line, index + 1, sum + Val(curChar));
	}else if (curChar == C || curChar == X || curChar == I)
	{
		char nextChar = line[index + 1];

		if (Val(curChar) < Val(nextChar))
			LetterToValue_r(line, index + 2, sum -  Val(curChar) + Val(nextChar));
		else
			LetterToValue_r(line, index + 1, sum + Val(curChar));
	}
}

int main(int argc, const char * argv[]) {


	string line;
	while (cin >> line)
	{


			if (line[0] >= '0' && line[0] <= '9')
			{
				stringstream convert(line);
				int result;
				convert >> result;
				ValToLetter_r(result);
			}
			else
			{
				LetterToValue_r(line, 0, 0);
			}
	}
	return 0;
}
