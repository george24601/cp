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

/* UVA 990 Diving for gold
 * Knapsack
 */

class Main {

	int t;
	int w;
	int n;
	int[] ds;
	int[] vs;

	int[] lastN;
	boolean[][] prevs;

	int cost(int d) {
		return 3 * d * w;
	}

	void Print_r(int index, int curT, int count) {
		if (index < 0) {
			System.out.println(count);
			return;
		}

		if (!prevs[index][curT]) {
			Print_r(index - 1, curT, count);
		} else {
			Print_r(index - 1, curT - cost(ds[index]), count + 1);
			System.out.println(String.format("%d %d", ds[index], vs[index]));
		}
	}

	void Process() {
		for (int i = 1; i < n; i++) {
			int[] next = new int[t + 1];
			int takeCost = cost(ds[i]);

			for (int j = 1; j <= t; j++) {
				next[j] = lastN[j];
				prevs[i][j] = false;

				if (takeCost <= j) {
					int yes = vs[i] + lastN[j - takeCost];

					if (yes > next[j]) {
						next[j] = yes;
						prevs[i][j] = true;
					}
				}
			}

			lastN = next;
		}

		System.out.println(lastN[t]);
		Print_r(n - 1, t, 0);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			boolean isFirst = true;
			while (st.nextToken() != st.TT_EOF) {
				
				if (isFirst)
					isFirst = false;
				else
					System.out.println();

				t = (int) st.nval;
				st.nextToken();
				w = (int) st.nval;
				st.nextToken();
				n = (int) st.nval;

				ds = new int[n];
				vs = new int[n];

				for (int i = 0; i < n; i++) {
					st.nextToken();
					ds[i] = (int) st.nval;
					st.nextToken();
					vs[i] = (int) st.nval;
				}

				lastN = new int[t + 1];
				prevs = new boolean[n][t + 1];

				for (int i = 1; i <= t; i++) {
					int cost = cost(ds[0]);

					if (cost <= i) {
						lastN[i] = vs[0];
						prevs[0][i] = true;
					} else {
						lastN[i] = 0;
						prevs[0][i] = false;
					}
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
