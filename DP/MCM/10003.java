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

/* UVA 10003 Cutting Sticks
 * DP
 */

class Main {

	int l;
	int n;
	int[] cuts;
	int[][] cost;

	void Process() {

		int totalSeg = n + 1;

		for (int i = 0; i < totalSeg; i++) {
			for (int j = 0; j < totalSeg; j++)
				cost[i][j] = Integer.MAX_VALUE;

			cost[i][i] = 0;
		}

		for (int size = 2; size <= totalSeg; size++) {
			for (int start = 0; start + size <= totalSeg; start++) {
				int endIndex = start + size - 1;
				int length = cuts[endIndex]
						- (start == 0 ? 0 : cuts[start - 1]);

				for (int mid = start + 1; mid <= endIndex; mid++) {
					int newCost = cost[start][mid - 1] + cost[mid][endIndex]
							+ length;

					if (newCost < cost[start][endIndex])
						cost[start][endIndex] = newCost;
				}
			}
		}

		System.out.println(String.format("The minimum cutting is %d.",
				cost[0][n]));
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			BufferedReader reader = new BufferedReader(new InputStreamReader(
					inStream));

			StreamTokenizer st = new StreamTokenizer(reader);
			while (true) {
				st.nextToken();
				l = (int) st.nval;

				if (l == 0)
					break;

				st.nextToken();
				n = (int) st.nval;

				cuts = new int[n + 1];
				cost = new int[n + 1][n + 1];

				for (int i = 0; i < n; i++) {
					st.nextToken();
					cuts[i] = (int) st.nval;
				}

				cuts[n] = l;

				Process();
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
