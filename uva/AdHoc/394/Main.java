import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/* UVA 394 Mapmaker
 * array manipulation
 */
class Main
{
	static void ParseArray(Scanner s, Map<String, long[]> nameToC)
	{
		String name = s.next();
		long B = s.nextLong();
		long Cd = s.nextLong();
		int D = s.nextInt();// 1 to 10 inclusive
		long[] Ls = new long[D];
		long[] Us = new long[D];
		
		for (int i = 0; i < D; i++)
		{
			Ls[i] = s.nextLong();
			Us[i] = s.nextLong();
		}

		long[] Cs = new long[D + 1];
		
		Cs [D] = Cd;
		
		for (int i = D-1; i >= 1; i--)
			Cs[i] = Cs[i+1] *(Us[i] - Ls[i] + 1);
		
		Cs[0] = B;
		
		for (int i = 1; i  <= D; i++ )
			Cs[0] -= Cs[i] * Ls[i - 1];
		
		nameToC.put(name, Cs);
	}

	void ProcessArrayRef(Scanner s, Map<String, long[]> nameToC)
	{
		String name = s.next();
		int length = nameToC.get(name).length - 1;
		long[] arrayRef = new long[length];

		for(int i = 0; i < length; i++)
			arrayRef[i] = s.nextLong();
		
		
		long addr = Calc(nameToC.get(name), arrayRef);
		Print(name, arrayRef, addr);
	}
	
	long Calc(long[] Cs, long[] arrayRef)
	{
		long result = Cs[0];
		
		for (int i = 0; i < arrayRef.length; i++)
		{
			result += Cs[i+ 1] * arrayRef[i];
		}
		
		return result;
	}
	
	void Print(String name, long[] arrayRef, long addr)
	{
		System.out.print(name);
		System.out.print('[');
		
		for (int i = 0; i < arrayRef.length; i++)
		{
			System.out.print(arrayRef[i]);
			
			if ( i < arrayRef.length -1)
				System.out.print(", ");
		}

		System.out.print("] = ");
		System.out.print(addr);
		System.out.println();
	}
	
	void Run() {
		InputStream inStream = System.in;

		/*
		try
		{
			inStream = new FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\394\\Test1.txt");
		} catch(Exception e)
		{
			
		}
		*/

		Scanner s = new Scanner(inStream);

		int N = s.nextInt();
		int R = s.nextInt();
		
		Map<String, long[]> nameToC = new HashMap<String, long[]>();

		for (int i = 0; i < N; i++)
			ParseArray(s, nameToC);
		
		for (int i = 0; i <R; i++)
			ProcessArrayRef(s, nameToC);
	}

	public static void main (String args[]) {
		(new Main()).Run();
	}
}

