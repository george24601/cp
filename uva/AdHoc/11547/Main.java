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

/* UVA 11547 Newspaper
 */
class Main {

	void Run() {
		InputStream inStream = System.in;

		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\11547\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		

		Scanner s = new Scanner(inStream);

		int t = Integer.parseInt(s.nextLine());

		for (int i = 0; i < t; i++)
		{
			long n = Long.parseLong(s.nextLine());
			
			long result = (((n * 63) + 7492) * 5) - 498;
			
			if (result <0 )
				result = result * -1;
			
			System.out.println((result / 10) % 10);
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
