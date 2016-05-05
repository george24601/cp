import java.io.FileInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/* UVA 661 blowing fuses
 * simulation
 */
class Main
{
	void Process(int n, int m, int c, Scanner s)
	{
			boolean[] devices = new boolean[n];
			int[] capacity = new int[n];
			
			for(int i = 0; i < n; i ++)
				capacity[i] = s.nextInt();
				
			int curMax = 0;
			int curSum = 0;
			boolean blown = false;

			for (int i = 0; i < m; i++)
			{
				int device = s.nextInt();
				
				if (blown)
					continue;

				devices[device -1] = !devices[device - 1];
				
				if (devices[device - 1])
				{
					curSum += capacity[device - 1];
					
					if (curSum > curMax)
					{
						curMax = curSum;
						
						if (curMax > c)
							blown = true;
					}
					
				}else
				{
					curSum -= capacity[device - 1];
				}
			}
			
			if (blown)
			{
				System.out.println("Fuse was blown.");
			}
			else
			{
				System.out.println("Fuse was not blown.");
				System.out.println(String.format("Maximal power consumption was %d amperes.", curMax));
			}
	
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try
		{
			inStream = new FileInputStream("D:\\PersonalCode\\Algorithms\\UVA\\661\\Test.txt");
		} catch(Exception e)
		{
			
		}
		*/

		Scanner s = new Scanner(inStream);
		int counter = 0;
		
		while(s.hasNextLine())
		{
			int n = s.nextInt();
			int m = s.nextInt();
			int c = s.nextInt();
			
			if (n == 0 && m == 0 && c == 0)
				break;
			
			counter++;
			
			System.out.println(String.format("Sequence %d", counter));
			Process(n, m, c, s);
			
			System.out.println();
		}
	}

	public static void main (String args[]) {
		(new Main()).Run();
	}
}

