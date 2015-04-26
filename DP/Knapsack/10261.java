import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

/* UVA 10261 ferry loading
 * Knapsack
 */

class Main {

	int n;
	int length;
	ArrayList<Integer> cars;
	ArrayList<Integer> sums;
	boolean[][] left;

	void Process() {
		left[0][0] = true;

		for (int i = 1; i <= n; i++) {
			int curCarLength = cars.get(i - 1);
			int curSum = sums.get(i - 1);

			for (int j = 0; j <= length; j++) {
				left[i][j] = false;

				if (j >= curCarLength) {

					boolean baseVal = left[i - 1][j - curCarLength];

					if (baseVal)
						left[i][j] = baseVal;
				}

				boolean rbv = left[i - 1][j];

				if (rbv) {

					int totalRight = curSum - j;

					if (totalRight <= length)
						left[i][j] = true;
				}
			}
		}
	}

	void Print_r(int i, int j) {
		if (i == 0)
			return;

		int curCarLength = cars.get(i - 1);

		if (left[i][j] == left[i - 1][j]) {
			Print_r(i - 1, j);
			System.out.println("starboard");

		} else {
			Print_r(i - 1, j - curCarLength);
			System.out.println("port");
		}
	}

	void Print() {
		int i = n;
		int startJ = length;
		boolean end = false;

		for (; i >= 0; i--) {
			for (int j = length; j >= 0; j--) {
				if (left[i][j]) {
					startJ = j;
					end = true;
					break;
				}
			}

			if (end)
				break;
		}

		System.out.println(i);

		Print_r(i, startJ);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int numCases = (int) st.nval;

			for (int i = 0; i < numCases; i++) {

				if (i > 0)
					System.out.println();

				st.nextToken();
				length = ((int) st.nval) * 100;
				cars = new ArrayList<Integer>();
				sums = new ArrayList<Integer>();

				n = 0;

				boolean read = true;

				while (true) {
					st.nextToken();
					int val = (int) st.nval;

					if (val == 0)
						break;

					int nextSum = n == 0 ? val : sums.get(n - 1) + val;

					if (nextSum > 2 * length)
						read = false;

					if (read) {
						n++;
						cars.add(val);
						sums.add(nextSum);
					}
				}

				left = new boolean[n + 1][length + 1];
				Process();
				Print();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
