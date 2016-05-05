import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.Scanner;

/* UVA 836 Largest Submatrix
 * max sum
 */
class Main {

	int SingleRow(int[] bets, int s) {
		int[] endMaxSum = new int[s];
		endMaxSum[0] = bets[0];

		for (int i = 1; i < s; i++) {

			if (bets[i] == 0) {
				endMaxSum[i] = 0;
				continue;
			}

			int sumWithLast = endMaxSum[i - 1] + bets[i];

			if (bets[i] > 0 && sumWithLast >= bets[i]) {
				endMaxSum[i] = sumWithLast;
			} else {
				endMaxSum[i] = bets[i];
			}
		}

		int maxSum = Integer.MIN_VALUE;

		for (int i = 0; i < s; i++) {
			if (endMaxSum[i] > maxSum)
				maxSum = endMaxSum[i];
		}

		return maxSum;
	}

	void Calc(int[][] input, int size) {
		int[][] sumBase = new int[size][size];

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				sumBase[i][j] = input[i][j];
			}
		}

		int max = 0;

		for (int i = 0; i < size; i++) {
			int curVal = SingleRow(sumBase[i], size);

			if (curVal > max)
				max = curVal;
		}

		int[][] sumNext = new int[size][size];

		for (int i = 1; i < size; i++) {
			for (int j = 0; j + i < size; j++) {
				for (int k = 0; k < size; k++) {
					if (input[j + i][k] == 0 || sumBase[j + i - 1][k] == 0)// TODO:
																			// check
																			// this
					{
						sumNext[j + i][k] = 0;
					} else {
						sumNext[j + i][k] = sumBase[j + i - 1][k] + 1;
					}
				}

				int curVal = SingleRow(sumNext[j + i], size);

				if (curVal > max)
					max = curVal;

			}

			sumBase = sumNext;
			sumNext = new int[size][size];
		}

		System.out.println(max);
	}

	void Run() {
		InputStream inStream = System.in;

		try {
	//		inStream = new FileInputStream(
	//				"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\836\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			Scanner st = new Scanner(inStream);

			int numCase = Integer.parseInt(st.nextLine());

			for (int curCase = 0; curCase < numCase; curCase++) {
				if (curCase > 0)
					System.out.println();

				st.nextLine();
				String row = st.nextLine();
				int s = row.length();

				int[][] bets = new int[s][s];

				for (int i = 0; i < s; i++) {
					bets[0][i] = row.charAt(i) == '0' ? 0 : 1;
				}

				for (int i = 1; i < s; i++) {
					row = st.nextLine();
					for (int j = 0; j < s; j++) {
						bets[i][j] = row.charAt(j) == '0' ? 0 : 1;
					}
				}

				Calc(bets, s);
			}

		} catch (Exception e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
