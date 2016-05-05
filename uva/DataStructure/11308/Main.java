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

/* UVA 11308:  Bankrupt Baker
 * simple data structure problem
 */
class Main {

	class Result implements Comparable<Result> {
		public String Key;
		public long Value;

		public Result(String key, long value) {
			Key = key;
			Value = value;
		}

		public int compareTo(Result other)
		{
			if  (Value > other.Value)
				return 1;
			else if (Value < other.Value)
				return -1;
			else
				return Key.compareTo(other.Key);
		}
	}

	void Run() {
		InputStream inStream = System.in;

		
		/*
		  try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\11308\\Test.txt"); } catch
		  (Exception e) {
		 
		  }
		  */
		 

		Scanner s = new Scanner(inStream);
		int t = Integer.parseInt(s.nextLine());

		for (int i = 0; i < t; i++) {
			String title = s.nextLine();
			StringTokenizer tokens = new StringTokenizer(s.nextLine());

			int m = Integer.parseInt(tokens.nextToken());
			int n = Integer.parseInt(tokens.nextToken());
			int b = Integer.parseInt(tokens.nextToken());

			Map<String, Long> costs = new HashMap<String, Long>();
			for (int j = 0; j < m; j++) {
				tokens = new StringTokenizer(s.nextLine());
				String name = tokens.nextToken();
				long cost = Long.parseLong(tokens.nextToken());
				costs.put(name, cost);
			}

			Map<String, Long> affordables = new HashMap<String, Long>();

			for (int j = 0; j < n; j++) {
				String name = s.nextLine();
				long k = Long.parseLong(s.nextLine());

				long totalCost = 0;
				for (int l = 0; l < k; l++) {
					tokens = new StringTokenizer(s.nextLine());
					String unitName = tokens.nextToken();
					int number = Integer.parseInt(tokens.nextToken());
					totalCost += costs.get(unitName) * number;
				}

				if (totalCost <= b)
					affordables.put(name, totalCost);
			}

			List<Result> results = new ArrayList<Result>();
			for (String key : affordables.keySet()) {
				results.add(new Result(key, affordables.get(key)));
			}

			Collections.sort(results);

			System.out.println(title.toUpperCase());

			if (results.size() == 0) {
				System.out.println("Too expensive!");
			} else {
				for (int j = 0; j < results.size(); j++)
					System.out.println(results.get(j).Key);
			}

			System.out.println();
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
