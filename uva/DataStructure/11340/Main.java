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

/* UVA 11340 Newspaper
 */
class Main {

	void Run() {
		InputStream inStream = System.in;

		
		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\11340\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		

		Scanner s = new Scanner(inStream);

		int N = Integer.parseInt(s.nextLine());

		for (int i = 0; i < N; i++)
		{
			int K = Integer.parseInt(s.nextLine());
			
			Map<Character, Long> charToVal = new HashMap<Character, Long>();
			
			for (int j = 0; j < K; j++)
			{
				StringTokenizer tokens = new StringTokenizer(s.nextLine());
				char c = tokens.nextToken().charAt(0);
				long cents = Long.parseLong(tokens.nextToken());
				
				charToVal.put(c, cents);
			}

			int M = Integer.parseInt(s.nextLine());
			
			long sum = 0;
			
			for (int j = 0; j < M; j++)
			{
				String line = s.nextLine();
				for (int k = 0; k < line.length(); k++)
				{
					char c = line.charAt(k);
					
					if (charToVal.containsKey(c))
						sum += charToVal.get(c);
				}
			}
			
			System.out.println(String.format("%d.%d$", sum/100, sum % 100));
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
