import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Collections;
import java.util.Comparator;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedMap;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;

/* UVA 10928: My Dear Neighbours 
 * simple graph
 */
class Main {

	
	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10928\\Test.txt");
		} catch (Exception e) {

		}
		*/
		

		Scanner s = new Scanner(inStream);
		int N = Integer.parseInt(s.nextLine());

		for (int i = 0; i < N; i++)
		{
			if (i >  0)
				s.nextLine();
			
			int P = Integer.parseInt(s.nextLine());
			
			int min = P;
			List<Integer> winners = new ArrayList<Integer>();

			for (int j = 1; j <= P; j++)
			{
				StringTokenizer tokens = new StringTokenizer(s.nextLine());
				HashSet<Integer> neighbors = new HashSet<Integer>();
				
				while(tokens.hasMoreTokens())
					neighbors.add(Integer.parseInt(tokens.nextToken()));

				int numNeighbors =  neighbors.size();
				
				if (numNeighbors < min)
				{
					min = numNeighbors;
					winners.clear();
					winners.add(j);
					
				}else if (numNeighbors == min)
				{
					winners.add(j);
				}
			}
			
			for (int j = 0; j < winners.size(); j++)
			{
				if (j > 0)
					System.out.print(" ");
				
				System.out.print(winners.get(j));
			}
			
			System.out.println();
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
