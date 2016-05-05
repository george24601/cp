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

/* UVA 11003 Boxes
 * Knapsack
 */

class Main {

	int N;
	int[] ws;
	int[] mls;
	int MaxWeight = 6000;

	void Process() {
		int[] last = new int[MaxWeight + 1];

		if (N > 0) {
			int curWeight = ws[N - 1];

			for (int j = 1; j <= MaxWeight; j++) {
				if (j == curWeight)
					last[j] = 1;
				else
					last[j] = 0;
			}
		}

		for (int i = N - 2; i >= 0; i--) {
			int[] current = new int[MaxWeight + 1];
			int curWeight = ws[i];
			int curML = mls[i];

			for (int j = 1; j <= MaxWeight; j++) {
				current[j] = last[j];

				if (j < curWeight || j > curML + curWeight)
					continue;

				int useCount = last[j - curWeight] + 1;

				if (useCount > current[j])
					current[j] = useCount;
			}

			last = current;

		}

		int max = 0;
		for (int i = 0; i <= MaxWeight; i++) {
			int curVal = last[i];

			if (max < curVal)
				max = curVal;

		}

		System.out.println(max);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
	//		inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (true) {
				st.nextToken();
				N = (int) st.nval;

				if (N == 0)
					break;

				ws = new int[N];
				mls = new int[N];

				for (int i = 0; i < N; i++) {
					st.nextToken();
					ws[i] = (int) st.nval;
					st.nextToken();
					mls[i] = (int) st.nval;
				}

				Process();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
