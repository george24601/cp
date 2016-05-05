import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/* UVA 10082 QWERTY 
 */
class Main {

	char Correct (char c)
	{
		switch(c)
		{
			//first line
			case '1':
				return '`';
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				return (char) (c - 1);
			case '0':
				return '9';
			case '-':
				return '0';
			case '=':
				return '-'; 
			//second line
			case 'W':
				return 'Q';
			case 'E':
				return 'W';
			case 'R':
				return 'E';
			case 'T':
				return 'R';
			case 'Y':
				return 'T';
			case 'U':
				return 'Y';
			case 'I':
				return 'U';
			case 'O':
				return 'I';
			case 'P':
				return 'O';
			case '[':
				return 'P';
			case ']':
				return '[';
			case '\\':
				return ']';
			//third line
			case 'S':
				return 'A';
			case 'D':
				return 'S';
			case 'F':
				return 'D';
			case 'G':
				return 'F';
			case 'H':
				return 'G';
			case 'J':
				return 'H';
			case 'K':
				return 'J';
			case 'L':
				return 'K';
			case ';':
				return 'L';
			case '\'':
				return ';';
			//last line;
			case 'X':
				return 'Z';
			case 'C':
				return 'X';
			case 'V':
				return 'C';
			case 'B':
				return 'V';
			case 'N':
				return 'B';
			case 'M':
				return 'N';
			case ',':
				return 'M';
			case '.':
				return ',';
			case '/':
				return '.';
			default:
				return c;
		}
	}

	void Process(String line)
	{
		for (int i = 0; i<line.length(); i++)
			System.out.print(Correct(line.charAt(i)));

		System.out.println();

	}

	void Run() {
		InputStream inStream = System.in;
		
		/*
		 try { inStream = new
		  FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\10082\\Test.txt");
		  } catch(Exception e) {
		  
		  }
		  */
		  

		Scanner s = new Scanner(inStream);


		while (s.hasNextLine()) {
			Process(s.nextLine());//digits, spaces, upper case letters (except Q, A, Z), or punctuation shown above [except back-quote (`)]. Keys labelled with words [Tab, BackSp, Control, etc.] are not represented in the input.
		}
		
		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
