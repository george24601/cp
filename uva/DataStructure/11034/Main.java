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

/* UVA 11034: Ferry Loading IV 
 * use of queue
 */
class Main {

	void Load(Queue<Long> sideToLoad, long l) {

		long totalLength = 0;

		while (sideToLoad.size() > 0 && totalLength + sideToLoad.peek() <= l) {
			totalLength+= sideToLoad.poll();
		}
	}

	void NextMoment(Queue<Long> left, Queue<Long> right, long l) {
		boolean isAtLeft = true;
		int count = 0;
		while (true) {
			if (left.size() + right.size() == 0)
				break;
			
			Queue<Long> sideToLoad = isAtLeft? left : right;
			
			Load(sideToLoad, l);
			
			isAtLeft = !isAtLeft;
			count++;
		}

		System.out.println(count);
	}

	void Run() {
		InputStream inStream = System.in;

		
		/*
		  try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\11034\\Test.txt"); } catch
		  (Exception e) {
		  
		  }
		  */
		  
		 
/*
		try {
			inStream = new FileInputStream(
					"C:\\Users\\user\\Downloads\\B.1.dat");
		} catch (Exception e) {

		}
		*/

		Scanner s = new Scanner(inStream);

		int c;
		c = Integer.parseInt(s.nextLine());

		for (int i = 0; i < c; i++) {
			StringTokenizer tokens = new StringTokenizer(s.nextLine());

			long l = Long.parseLong(tokens.nextToken()) * 100;
			int m = Integer.parseInt(tokens.nextToken());

			Queue<Long> leftQ = new LinkedList<Long>();
			Queue<Long> rightQ = new LinkedList<Long>();


			for (int j = 0; j < m; j++) {
				tokens = new StringTokenizer(s.nextLine());
				Long arrival = Long.parseLong(tokens.nextToken());
				boolean left = tokens.nextToken().equals("left");
				if (left)
					leftQ.add(arrival);
				else
					rightQ.add(arrival);

			}

			
			NextMoment(leftQ, rightQ, l);
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
