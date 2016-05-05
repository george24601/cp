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

/* UVA 10819 Trouble of 13-Dots
 * Knapsack
 */

class Main {

	int m;
	int n;
	int[] ps;
	int[] fs;

	int Process(int min, int maxM) {
		int[] last = new int[maxM + 1];
		int[] lastP = new int[maxM + 1];

		if (n > 0) {
			for (int j = 1; j <= maxM; j++) {
				int curMin = min - maxM + j;
				int curP = ps[0];
				int curF = fs[0];

				if (curP > j) {
					last[j] = 0;
					lastP[j] = 0;
				} else if (curP < curMin) {
					last[j] = -1;
					lastP[j] = 0;
				} else {
					last[j] = curF;
					lastP[j] = curP;
				}
			}
		}

		for (int i = 1; i < n; i++) {
			int[] next = new int[maxM + 1];
			int[] nextP = new int[maxM + 1];

			int curP = ps[i];
			int curF = fs[i];

			for (int j = 1; j <= maxM; j++) {

				int curMin = min - maxM + j;

				next[j] = last[j];
				nextP[j] = lastP[j];

				if (j < curP)
					continue;

				int lastMaxP = j - curP;

				int curTotalP = lastP[lastMaxP] + curP;

				if (curTotalP < curMin || curTotalP > j || last[lastMaxP] < 0)
					continue;

				int totalFWithNew = last[lastMaxP] + curF;

				if (totalFWithNew > next[j]) {
					next[j] = totalFWithNew;
					nextP[j] = curTotalP;
				}
			}

			last = next;
			lastP = nextP;
		}

		return last[maxM];
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF) {
				m = (int) st.nval;

				st.nextToken();
				n = (int) st.nval;

				ps = new int[n];
				fs = new int[n];

				for (int i = 0; i < n; i++) {
					st.nextToken();
					ps[i] = (int) st.nval;

					st.nextToken();
					fs[i] = (int) st.nval;
				}

				int noRefund = Process(0, m >= 2000 ? 2000 : m);

				if (m >= 1801) {
					int refund = Process(2001, m + 200);

					if (refund > noRefund)
						noRefund = refund;
				}

				System.out.println(noRefund);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
