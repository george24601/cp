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

/* UVA 11658 Best Coalitions
 * Knapsack
 */

class Main {

	int n;
	int x;
	int[] ps;
	int Max = 10000;
	int HalfMax = 5000;

	void Process() {
		boolean[] last = new boolean[Max + 1];
		last[0] = true;

		for (int i = 0; i < n; i++) {
			if (i == (x - 1))
				continue;

			int curPrice = ps[i];

			boolean[] updated = new boolean[Max + 1];

			for (int j = 0; j <= Max; j++) {
				updated[j] = last[j];

				int lastIndex = j - curPrice;

				if (lastIndex >= 0 && last[lastIndex])
					updated[j] = true;
			}

			last = updated;
		}

		int useShare = ps[x - 1];

		for (int i = 0; i <= Max; i++) {
			int totalShare = i + useShare;
			if (i + useShare > HalfMax && last[i]) {
				double percent = ((double) (useShare * 100))
						/ ((double) totalShare);

				System.out.println(String.format("%.2f", percent));

				return;
			}
		}
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (true) {
				StringTokenizer strtok = new StringTokenizer(reader.readLine(), " ");
				n = Integer.parseInt(strtok.nextToken());
				x = Integer.parseInt(strtok.nextToken());

				if (n == 0 && x == 0)
					break;

				ps = new int[n];

				for (int i = 0; i < n; i++) {
					String s = reader.readLine();
					s = s.substring(0, s.indexOf('.'))
							+ s.substring(s.indexOf('.') + 1, s.length());
					ps[i] = Integer.parseInt(s);
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
