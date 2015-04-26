import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/* UVA 483 Word Scamble
 *output will consist of the same lines and words as the input file.
 * However, the letters within each word must be reversed.
 */
class Main
{
	boolean isWhiteSpace(char c)
	{
		return c == ' ' || c == '\t';
	}

	int nextSpaceIndex(String s, int start)
	{
		int nextSpace = s.indexOf(' ', start);
		int nextTab = s.indexOf('\t', start);
		
		if (nextSpace == -1 && nextTab == -1)
			return s.length();
		else
			return Math.max(nextSpace, nextTab);
	}

	void Process_r(String line, int currentIndex)
	{
		if (currentIndex >= line.length())
		{
			System.out.println();
			return;
		}

		char currentChar = line.charAt(currentIndex);

		if (isWhiteSpace(currentChar))
		{
			System.out.print(currentChar);
			Process_r(line, ++currentIndex);
			return;
		}
		else
		{
			int nextSpaceIndex = nextSpaceIndex(line, currentIndex);
			
			for (int i = nextSpaceIndex - 1; i >= currentIndex; i--)
				System.out.print(line.charAt(i));
			
			Process_r(line, nextSpaceIndex);
		}
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try
		{
			inStream = new FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\483\\Test.txt");
		} catch(Exception e)
		{
			
		}
		*/

		Scanner s = new Scanner(inStream);
		
		while(s.hasNextLine())
			Process_r(s.nextLine(), 0);
	}

	public static void main (String args[]) {
		(new Main()).Run();
	}
}

