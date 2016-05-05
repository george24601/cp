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

/* UVA 10534 Wavio Sequence 
 * LIS
 */

class Main {
	int N;

	void LIS(int[] LIS, int[] input) {
		int[] MVals = new int[N + 1];

		MVals[1] = input[0];
		int L = 1;
		LIS[0] = 1;

		for (int i = 1; i < N; i++) {
			// binary search
			int index = Arrays.binarySearch(MVals, 1, L, input[i]);

			if (index >= 1) {
				LIS[i] = L;

			} else {
				int insertionPoint = - index - 1;

				if (insertionPoint == L) {
					if (MVals[insertionPoint] < input[i]) {
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

	void Process(int[] LIS, int[] LDS) {
		int curMax = 0;

		for (int i = 0; i < N; i++) {
			int val = Math.min(LIS[i], LDS[N - 1 - i]);

			if (val > curMax)
				curMax = val;
		}

		System.out.println(2 * curMax - 1);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			while (st.nextToken() != st.TT_EOF) {
				N = (int) st.nval;

				int[] input = new int[N];

				for (int i = 0; i < N; i++) {
					st.nextToken();
					input[i] = (int) st.nval;
				}

				int[] LIS = new int[N];
				LIS(LIS, input);
				int[] LDS = new int[N];

				int[] inputRev = new int[N];

				for (int i = 0; i < N; i++)
					inputRev[i] = input[N - 1 - i];

				LIS(LDS, inputRev);
				Process(LIS, LDS);
			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
