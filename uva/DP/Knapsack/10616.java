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

/* UVA 10616 Divisible Group Sums
 * Knapsack
 */

class Main {

	int N;
	int[] nums;
	long[][] ways;
	int D;
	int M;

	void PreProcess() {
		ways = new long[D][M + 1];

		for (int i = 0; i < N; i++) {
			long[][] newWays = new long[D][M + 1];
			int curNum = nums[i];

			int curMod = curNum % D;

			if (curMod < 0)
				curMod += D;
			
			for (int j = 0; j < D; j++) {

				newWays[j][1] = ways[j][1];

				if (curMod == j)
					newWays[j][1] += 1;

				for (int k = 2; k <= M; k++) {
					newWays[j][k] = ways[j][k];

					int baseIndex = j - curMod;
					if (j < curMod)
						baseIndex += D;

					newWays[j][k] += ways[baseIndex][k - 1];
				}
			}

			ways = newWays;
		}

	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream("C:\\Test\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			int numCase = 0;
			while (true) {
				st.nextToken();
				N = (int) st.nval;
				st.nextToken();
				int Q = (int) st.nval;

				if (N == 0 && Q == 0)
					break;

				numCase++;

				nums = new int[N];

				for (int i = 0; i < N; i++) {
					st.nextToken();
					nums[i] = (int) st.nval;
				}

				System.out.println(String.format("SET %d:", numCase));

				for (int i = 0; i < Q; i++) {
					st.nextToken();
					D = (int) st.nval;
					st.nextToken();
					M = (int) st.nval;
					PreProcess();

					System.out.println(String.format("QUERY %d: %d", i + 1,
							ways[0][M]));
				}

			}

		} catch (IOException e) {

		}

	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
