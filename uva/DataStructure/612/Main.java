import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/* UVA 612 DNA sorting. stable sort needed
 */
class Main {
	
	Map<String, Integer> lineToII;
	
	final Comparator<String> sorter = new Comparator<String>()
			{
				public int compare (String s1, String s2)
				{
					int val1 = lineToII.get(s1);
					int val2 = lineToII.get(s2);
					
					if (val1 < val2)
						return -1;
					if (val1 > val2)
						return 1;
					else
						return 0;
								
				}
			};

	int GetII(String line)
	{
		int count = 0;
		for (int i = 0; i < line.length(); i++)
		{
			char curChar = line.charAt(i);
			for (int j = i + 1; j < line.length(); j++)
			{
				if (curChar > line.charAt(j))
					count++;
			}
		}
		
		return count;
	}


	void Run() {
		InputStream inStream = System.in;

		/*
		 try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\612\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		 */ 
		  
		  
		

		Scanner s = new Scanner(inStream);

		int  M = Integer.parseInt(s.nextLine());

		for (int i = 0; i < M; i++)
		{
			s.nextLine();
			StringTokenizer tokens = new StringTokenizer(s.nextLine());
			int n  = Integer.parseInt(tokens.nextToken());
			int m  = Integer.parseInt(tokens.nextToken());

			lineToII = new HashMap<String, Integer>();
			String[] lines = new String[m];
			for (int j = 0; j < m; j++)
			{
				String line = s.nextLine();
				int ii = GetII(line);
				lineToII.put(line, ii);
				lines[j] = line;
			}
			
			List<String> toSort = Arrays.asList(lines);
			
			Collections.sort(toSort, sorter);
			
			if (i > 0)
				System.out.println();
			
			for (int j = 0; j < m; j++)
				System.out.println(toSort.get(j));
			
		}
		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
