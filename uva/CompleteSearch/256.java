import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* UVA 256 quirksome's squares 
 * simple complete search 
 */
class Main {

	void PrintCase2()
	{
		System.out.println("00");
		System.out.println("01");
		System.out.println("81");
	}
	
	void PrintCase4()
	{
		System.out.println("0000");
		System.out.println("0001");
		System.out.println("2025");
		System.out.println("3025");
		System.out.println("9801");
	}
	
	void PrintCase6()
	{
		System.out.println("000000");
		System.out.println("000001");
		System.out.println("088209");
		System.out.println("494209");
		System.out.println("998001");
	}

	void PrintCase8()
	{
		System.out.println("00000000");
		System.out.println("00000001");
		System.out.println("04941729");
		System.out.println("07441984");
		System.out.println("24502500");
		System.out.println("25502500");
		System.out.println("52881984");
		System.out.println("60481729");
		System.out.println("99980001");
	}
	
	void Process(int val) {
		
		int factor = 1;
		for (int i = 0; i < val/2; i++)
			factor *= 10;
		
		for (int i = 0; i < factor; i++)
		{
			for (int j = 0; j < factor; j++)
			{
				int num = i * factor + j;
				if ((i + j) * (i + j) == num)
					System.out.println(num);
			}
		}

	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\256\\Test.txt");
		} catch (Exception e) {
		}
		*/

		try {
			Reader r = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer s = new StreamTokenizer(r);

			while (s.nextToken() != s.TT_EOF)
			{
				int val = (int) s.nval;
				
				if (val == 2)
					PrintCase2();
				else if (val == 4)
					PrintCase4();
				else if (val == 6)
					PrintCase6();
				else
					PrintCase8();
				//Process(val);
			}
		} catch (IOException e) {
				
		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
