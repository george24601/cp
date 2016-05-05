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

/* UVA 11790  Murcia's Skyline
 * LIS
 */

class Main {
	int N;

	int[] hs;
	int[] ws;

	boolean Comp(int a, int b, boolean increasing) {
		return (increasing && a > b) || (!increasing && a < b);
	}

	int LXS(boolean increasing) {
		int[] LXS = new int[N];

		for (int i = 0; i < N; i++) {
			LXS[i] = ws[i];

			for (int j = 0; j < i; j++) {
				if (Comp(hs[i], hs[j], increasing)) {
					int newLength = LXS[j] + ws[i];

					if (newLength > LXS[i]) {
						LXS[i] = newLength;
					}
				}
			}
		}

		int curLongest = 0;
		for (int i = 0; i < N; i++) {
			if (LXS[i] > curLongest)
				curLongest = LXS[i];
		}

		return curLongest;
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			// inStream = new FileInputStream("C:\\Test\\A.3.dat");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int numCases = (int) st.nval;
			for (int j = 0; j < numCases; j++) {
				st.nextToken();
				N = (int) st.nval;

				hs = new int[N];

				for (int i = 0; i < N; i++) {
					st.nextToken();
					hs[i] = (int) st.nval;
				}

				ws = new int[N];

				for (int i = 0; i < N; i++) {
					st.nextToken();
					ws[i] = (int) st.nval;
				}

				int LIS = LXS(true);
				int LDS = LXS(false);

				if (LIS >= LDS)
					System.out.println(String.format(
							"Case %d. Increasing (%d). Decreasing (%d).",
							j + 1, LIS, LDS));
				else
					System.out.println(String.format(
							"Case %d. Decreasing (%d). Increasing (%d).",
							j + 1, LDS, LIS));
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
