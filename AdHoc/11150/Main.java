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

/* UVA 11150 Cola
 */
class Main {

	int Process (int N)
	{
		int totalDrank = N;
		int currentEmpty = N;
		
		while (currentEmpty > 1)
		{
			int returned = currentEmpty/3;
			totalDrank += returned;

			if (currentEmpty % 3 == 0)
			{
				currentEmpty = returned;
			}else if (currentEmpty % 3 == 1)
			{
				currentEmpty = returned  + 1;
				
			}else  if(currentEmpty % 3 == 2)
			{
				totalDrank += 1;
				currentEmpty = returned;
			}
		}
		
		return totalDrank;
	}

	void Run() {
		InputStream inStream = System.in;

		
		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\11150\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		

		Scanner s = new Scanner(inStream);

		while (s.hasNextLine()) {
			StringTokenizer tokens = new StringTokenizer(s.nextLine());
			int N = Integer.parseInt(tokens.nextToken());

			int result = Process(N);
			System.out.println(result);
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
