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
import java.util.StringTokenizer;
import java.util.Vector;

/* UVA 10313 Pay the Price
 * Knapsack
 */

class Main {
	int p;
	int n;
	int[] coins;
	int[] last;

	int MaxP = 20000;

	void Process() {
		last = new int[MaxP + 1];
		last[0] = 0;

		for (int i = 1; i <= MaxP; i++)
			last[i] = -1;

		for (int i = 0; i < n; i++) {
			int[] next = new int[MaxP + 1];
			int curCoin = coins[i];

			for (int j = 0; j <= MaxP; j++) {
				next[j] = last[j];

				if (j < curCoin || last[j - curCoin] < 0)
					continue;

				int newChoice = last[j - curCoin] + 1;

				if (next[j] < 0 || newChoice < next[j])
					next[j] = newChoice;
			}

			last = next;
		}

		for (int i = p; i <= MaxP; i++) {
			if (last[i] >= 0) {
				System.out.println(String.format("%d %d", i, last[i]));
				return;
			}
		}
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();

			int numCase = (int) (st.nval);

			for (int i = 0; i < numCase; i++) {
				st.nextToken();
				p = (int) (st.nval);

				st.nextToken();
				n = (int) (st.nval);

				coins = new int[n];

				for (int j = 0; j < n; j++) {
					st.nextToken();
					coins[j] = (int) (st.nval);
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
