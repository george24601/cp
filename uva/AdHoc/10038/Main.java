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
import java.util.Stack;
import java.util.StringTokenizer;

/* UVA 10038: Jolly jumper 
 * simple problem
 */
class Main {

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\10038\\Test.txt");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		while (s.hasNextLine()) {
			StringTokenizer tokens = new StringTokenizer(s.nextLine());
			int max = Integer.MIN_VALUE;
			int min = Integer.MAX_VALUE;

			HashSet<Integer> setOfDiffs = new HashSet<Integer>();
			int n = Integer.parseInt(tokens.nextToken());

			int previous = Integer.parseInt(tokens.nextToken());
			if (n == 1)
			{
				max = 0;
				min = 1;
			}

			while (tokens.hasMoreTokens()) {
				int current = Integer.parseInt(tokens.nextToken());
				int currentDiff = current > previous ? current - previous
						: previous - current;

				setOfDiffs.add(currentDiff);

				if (max < currentDiff)
					max = currentDiff;

				if (min > currentDiff)
					min = currentDiff;

				previous = current;

			}

			if (max == n - 1 && min == 1 && setOfDiffs.size() == n - 1)
				System.out.println("Jolly");
			else
				System.out.println("Not jolly");
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
