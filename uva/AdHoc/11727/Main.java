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
		  "D:\\PersonalCode\\Algorithms\\UVA\\11727\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		

		Scanner s = new Scanner(inStream);
		int T = Integer.parseInt(s.nextLine());

		for (int i = 0; i < T; i++)
		{
			StringTokenizer tokens = new StringTokenizer(s.nextLine());
			
			List<Integer> list = new ArrayList<Integer>();

			list.add(Integer.parseInt(tokens.nextToken()));
			list.add(Integer.parseInt(tokens.nextToken()));
			list.add(Integer.parseInt(tokens.nextToken()));
			
			Collections.sort(list);
			
			System.out.println(String.format("Case %d: %d", i+1, list.get(1)));
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
