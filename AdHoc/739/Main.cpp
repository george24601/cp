#include <iostream>
using namespace std;

int LetterToCode(char c) {
	switch (c) {
	case 'B':
	case 'P':
	case 'F':
	case 'V':
		return 1;
	case 'C':
	case 'S':
	case 'K':
	case 'G':
	case 'J':
	case 'Q':
	case 'X':
	case 'Z':
		return 2;
	case 'D':
	case 'T':
		return 3;
	case 'L':
		return 4;
	case 'M':
	case 'N':
		return 5;
	case 'R':
		return 6;
	default:
		return -1;
	}
}

void PrintFromCol10ToCol35(string name, string col2) {
	cout << "         ";

	cout << name;

	for (int i = 9 + name.length(); i <= 33; i++)
		cout << ' ';

	cout << col2 << endl;
}

bool IsNeverEncoded(char c) {
	switch (c) {
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'Y':
	case 'W':
	case 'H':
		return true;
	default:
		return false;
	}
}

void Process(string input) {
	string code = "";

	for (int i = 0; i < input.length(); i++) {

		char currentChar = input[i];
		if (0 == i) {
			code += currentChar;
			continue;
		}

		if (IsNeverEncoded(currentChar))
			continue;

		int curCharEncode = LetterToCode(currentChar);
		char prevChar = input[i - 1];

		if (IsNeverEncoded(prevChar)
				|| curCharEncode != LetterToCode(prevChar)) {
			code += (char) ('0' + curCharEncode);

			if (code.length() >= 4)
				break;
			else
				continue;

		}
	}

	while (code.length() != 4) {
		code = code + '0';
	}

	PrintFromCol10ToCol35(input, code);

}

int main(int argc, const char * argv[]) {

	string input;
	cout << "         NAME                     SOUNDEX CODE" << endl;

	while (cin >> input)
		Process(input);

	cout << "                   END OF OUTPUT" << endl;
	return 0;
}
