#include <iostream>
#include <list>
#include <map>
#include <sstream>
using namespace std;

bool isLetter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int Process_r(string line, int index)
{
	if (isLetter(line [index]))
	{
		for (int i = index; i < line.length(); i++)
		{
			if (!isLetter(line[i]))
				return 1 + Process_r(line, i);

		}

		return 1;
	}else
	{
		for (int i = index; i < line.length(); i++)
		{
			if (isLetter(line[i]))
				return Process_r(line, i);

		}

		return 0;
	}
}

//UVA 494: c++ test lol
int main(int argc, const char * argv[]) {

	string line;

	while(getline(cin, line))
	{
		cout << Process_r(line, 0) << endl;
	}
	return 0;
}
