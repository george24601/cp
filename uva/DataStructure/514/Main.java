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
import java.util.Stack;
import java.util.StringTokenizer;

/* UVA 514: rails: use stack to simulate
 */
class Main {

	boolean Process_r(Stack<Integer> station, int[] target, int targetIndex,
			int[] source, int sourceIndex) {
		if (targetIndex == target.length)
			return true;

		int curTarget = target[targetIndex];

		if (station.size() > 0 && station.peek() == curTarget) {
			station.pop();
			return Process_r(station, target, targetIndex + 1, source,
					sourceIndex);
		}

		int finalSourceIndex = sourceIndex;

		for (;;) {
			if (finalSourceIndex >= source.length)
				return false;// looking for new one, but no one is available

			int currentSource = source[finalSourceIndex];
			station.push(currentSource);
			finalSourceIndex++;
			if (currentSource == curTarget)
				break;
		}

		return Process_r(station, target, targetIndex, source, finalSourceIndex);
	}

	void Run() {
		InputStream inStream = System.in;

		/*
		try {
			inStream = new FileInputStream(
					"D:\\PersonalCode\\Algorithms\\UVA\\514\\Test.txt");
		} catch (Exception e) {

		}*/

		Scanner s = new Scanner(inStream);
		while (s.hasNextLine()) {

			int N = Integer.parseInt(s.nextLine());

			if (N == 0)
				break;

			while (true) {
				String line = s.nextLine();

				if (line.equals("0"))
					break;

				StringTokenizer tokens = new StringTokenizer(line);

				int[] outside = new int[N];
				int[] source = new int[N];

				for (int i = 0; i < N; i++) {
					outside[i] = Integer.parseInt(tokens.nextToken()) - 1;
					source[i] = i;
				}

				Stack<Integer> station = new Stack<Integer>();

				if (Process_r(station, outside, 0, source, 0))
					System.out.println("Yes");
				else
					System.out.println("No");
			}

			System.out.println();
		}

		s.close();
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
