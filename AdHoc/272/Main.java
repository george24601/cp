import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;

/* UVA 272 TEX Quotes, just replace all double quotes to TEX() quotes*/
class Main
{
	void ProcessStream_r(Scanner s, boolean isNextOpen)
	{
		if (!s.hasNextLine())
			return;
		
		String line = s.nextLine();
		
		for(int i = 0; i < line.length(); i++)
		{
			if(line.charAt(i) != '"')
			{
				System.out.print(line.charAt(i));
			}
			else 
			{
				if (isNextOpen)
					System.out.print("``");
				else
					System.out.print("''");

				isNextOpen = !isNextOpen;
			}
		}
		
		System.out.println();
		
		ProcessStream_r(s, isNextOpen);
		
	}
	
	void Run() {
		InputStream inStream = System.in;

		/*
		try
		{
			inStream = new FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\272\\Test2.txt");
		} catch(Exception e)
		{
			
		}
		*/

		Scanner s = new Scanner(inStream);

		ProcessStream_r(s, true);
	}

	public static void main (String args[]) {
		(new Main()).Run();
	}
}

