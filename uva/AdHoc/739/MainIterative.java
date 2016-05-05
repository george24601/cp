import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/* UVA 739 Soundex Indexing
 */
class Main {

	final int SoundexSize = 4;

	void PrintFromCol10ToCol35(String name, String col2) {
		System.out.print("         ");

		System.out.print(name);

		for (int i = 9 + name.length(); i <= 33; i++)
			System.out.print(' ');

		System.out.println(col2);
	}

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

	boolean isNeverEncoded(char c) {
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

	void Process(String name) {
		String soundex = "";

		for (int i  = 0; i < name.length();i++)
		{
			char currentChar = name.charAt(i);
			if (i == 0)
			{
				soundex += currentChar; 
				continue;
			}else if (isNeverEncoded(currentChar))
			{
				continue;
			}else{
				 int curCharEncode = LetterToCode(currentChar);
				 char prevChar = name.charAt(i -1);

				if (isNeverEncoded(prevChar) || curCharEncode != LetterToCode(prevChar))
				{
					soundex +=  (char) ('0' + curCharEncode);

					if (soundex.length() >= SoundexSize)
						break;
					else
						continue;

				}

			}
		} 

		for (int i = soundex.length(); i < SoundexSize; i++)
			soundex += '0';

		PrintFromCol10ToCol35(Name, soundex);
	}

	void Run() {
		InputStream inStream = System.in;
		/*
		 try { inStream = new
		  FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\739\\st.txt");
		  } catch(Exception e) {
		  
		  }
		  */

		Scanner s = new Scanner(inStream);

		PrintFromCol10ToCol35("NAME", "SOUNDEX CODE");

		while (s.hasNextLine())
			Process(s.nextLine());
		
		System.out.println("                   END OF OUTPUT");
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
