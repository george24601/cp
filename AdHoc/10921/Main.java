import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 10921 Find the Telephone
 */
class Main {

	char Convert(char curChar)
	{
		switch (curChar)
		{
			case 'A':
			case 'B':
			case 'C':
				return '2';
			case 'D':
			case 'E':
			case 'F':
				return '3';
			case 'G':
			case 'H':
			case 'I':
				return '4';
			case 'J':
			case 'K':
			case 'L':
				return '5';
			case 'M':
			case 'N':
			case 'O':
				return '6';
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				return '7';
			case 'T':
			case 'U':
			case 'V':
				return '8';
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				return '9';
			default:
				return '0';
		}
	}
	
	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10921\\Test.txt");
		} catch (Exception e) {

		}*/

		Scanner s = new Scanner(inStream);



		while(s.hasNextLine())
		{
			String line = s.nextLine();

			for (int i = 0; i < line.length(); i++)
			{
				char curChar = line.charAt(i);

				if (curChar >= 'A' && curChar <= 'Z')
					System.out.print(Convert(curChar));
				else
					System.out.print(curChar);

			}

			System.out.println();
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
