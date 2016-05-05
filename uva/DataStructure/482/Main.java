import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 11727 Cost cutting
 */
class Main {
	


	void Run() {
		InputStream inStream = System.in;

		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\482\\test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		  
		

		Scanner s = new Scanner(inStream);
		int T = Integer.parseInt(s.nextLine());

		for (int i = 0; i < T; i++)
		{
			s.nextLine(); //blank line
			
			StringTokenizer tokens = new StringTokenizer(s.nextLine());
			
			Map<Integer, Integer> perms = new HashMap<Integer, Integer>();
			
			int count = 0;
			while(tokens.hasMoreTokens())
			{
				perms.put(Integer.parseInt(tokens.nextToken()), count);
				count ++;
			}
				

			List<String> vals = new ArrayList<String>();
			
			tokens = new StringTokenizer(s.nextLine());
			while(tokens.hasMoreTokens())
				vals.add(tokens.nextToken());
			
			for (int j = 1; j <= perms.size(); j++)
				System.out.println(vals.get(perms.get(j)));
			
			if (i < T - 1)
				System.out.println();
		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
