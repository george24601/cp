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

/* UVA 1196  Tiling up blocks
 * LIS
 */

class Main {

	class El {
		public int L;
		public int M;

		public El(int l, int m) {
			L = l;
			M = m;
		}
	}

	class ElComparator implements Comparator<El> {
		public int compare(El first, El second) {
			if (first.L > second.L)
				return 1;
			else if (first.L < second.L)
				return -1;

			if (first.M > second.M)
				return 1;
			else if (first.M < second.M)
				return -1;

			return 0;
		}
	}

	void LIS(int[] LIS, int[] input, int N) {
		int[] MVals = new int[N + 1];

		MVals[1] = input[0];
		int L = 1;
		LIS[0] = 1;

		for (int i = 1; i < N; i++) {
			int curNum = input[i];
			// binary search
			int index = Arrays.binarySearch(MVals, 1, L, curNum);

			if (index >= 1) {

				while ((index + 1) <= L && MVals[index + 1] == curNum)
					index++;

				if (index == L)
					L++;

				LIS[i] = index + 1;
				MVals[index + 1] = curNum;

			} else {
				int insertionPoint = -index - 1;

				if (insertionPoint == L) {
					if (MVals[insertionPoint] <= input[i]) {
						L++;
						MVals[L] = input[i];
						LIS[i] = L;
					} else {
						MVals[insertionPoint] = input[i];
						LIS[i] = insertionPoint;
					}
				} else {
					MVals[insertionPoint] = input[i];
					LIS[i] = insertionPoint;
				}
			}
		}
	}

	void Run() {
		InputStream inStream = System.in;

		try {
			//inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (true) {
				st.nextToken();
				int N = (int) st.nval;

				if (N == 0) {
					System.out.println("*");
					break;
				}

				El[] els = new El[N];
				for (int i = 0; i < N; i++) {
					st.nextToken();
					int l = (int) st.nval;
					st.nextToken();
					int m = (int) st.nval;
					els[i] = new El(l, m);
				}

				Arrays.sort(els, new ElComparator());
				int[] nums = new int[N];

				for (int i = 0; i < N; i++)
					nums[i] = els[i].M;

				int[] LIS = new int[N];
				LIS(LIS, nums, N);

				int curMax = 0;
				for (int i = 0; i < N; i++) {
					if (curMax < LIS[i])
						curMax = LIS[i];
				}

				System.out.println(curMax);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
