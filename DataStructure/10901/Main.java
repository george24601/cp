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

/* UVA 10901: Ferry Loading III 
 * use of queue
 */
class Main {

	void Load(Queue<Integer> sideToLoad, int currentTime, int n, int t, Dictionary<Integer, Integer> results) {

		int count = 0;

		while (sideToLoad.size() > 0 && sideToLoad.peek() <= currentTime
				&& count < n) {
			results.put(sideToLoad.poll(), currentTime + t);
			count++;
		}
	}

	void NextMoment_r(Queue<Integer> left, Queue<Integer> right, int n, int t, Dictionary<Integer, Integer> results) {
		boolean isAtLeft = true;
		int currentTime = 0;
		while (true) {
			if (left.size() + right.size() == 0)
				return;

			int leftHead = left.size() == 0 ? Integer.MAX_VALUE : left.peek();
			int rightHead = right.size() == 0 ? Integer.MAX_VALUE : right
					.peek();

			if (leftHead > currentTime && rightHead > currentTime) {
				if (leftHead > rightHead) {
					currentTime =  isAtLeft ? rightHead +  t: rightHead;
					isAtLeft = false;
				} else if (leftHead < rightHead) {
					currentTime = isAtLeft? leftHead: leftHead + t;
					isAtLeft = true;
				} else {
					currentTime = leftHead;
				}
			} else if (leftHead > currentTime && rightHead <= currentTime) {
				if (!isAtLeft)
					Load(right, currentTime, n, t, results);

				isAtLeft = !isAtLeft;
				currentTime = currentTime + t;
			} else if (leftHead <= currentTime && rightHead > currentTime) {
				if (isAtLeft)
					Load(left, currentTime, n, t, results);

				isAtLeft = !isAtLeft;
				currentTime = currentTime + t;
			} else if (leftHead <= currentTime && rightHead <= currentTime) {
				Queue<Integer> sideToLoad = isAtLeft ? left : right;

				Load(sideToLoad, currentTime, n, t, results);
				isAtLeft = !isAtLeft;
				currentTime = currentTime + t;
			}
		}
	}

	void Run() {
		InputStream inStream = System.in;

		
		/*
		  try { inStream = new FileInputStream(
		  "D:\\PersonalCode\\Algorithms\\UVA\\10901\\Test.txt"); } catch
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

			int n = Integer.parseInt(tokens.nextToken());
			int t = Integer.parseInt(tokens.nextToken());
			int m = Integer.parseInt(tokens.nextToken());

			Queue<Integer> leftQ = new LinkedList<Integer>();
			Queue<Integer> rightQ = new LinkedList<Integer>();

			int[] arrivals = new int[m];

			for (int j = 0; j < m; j++) {
				tokens = new StringTokenizer(s.nextLine());
				int arrival = Integer.parseInt(tokens.nextToken());
				arrivals[j] = arrival;
				boolean left = tokens.nextToken().equals("left");
				if (left)
					leftQ.add(arrival);
				else
					rightQ.add(arrival);

			}

			Dictionary<Integer, Integer> results = new Hashtable<Integer, Integer>();
			
			NextMoment_r(leftQ, rightQ, n, t, results);

			for (int j  =0; j < m; j++)
				System.out.println(results.get(arrivals[j]));

			if (i < c - 1)
				System.out.println();
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
