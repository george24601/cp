import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StreamTokenizer;
import java.util.Arrays;

/* UVA 108 Maximum Sum
 * max sum
 */
class Main {

	long MaxSumSingle(long[] bets, int s) {
		long[] endMaxSum = new long[s];
		endMaxSum[0] = bets[0];

		for (int i = 1; i < s; i++) {
			long sumWithLast = endMaxSum[i - 1] + bets[i];

			if (sumWithLast >= bets[i]) {
				endMaxSum[i] = sumWithLast;
			} else {
				endMaxSum[i] = bets[i];
			}
		}

		long maxSum = Long.MIN_VALUE;

		for (int i = 0; i < s; i++) {
			if (endMaxSum[i] > maxSum)
				maxSum = endMaxSum[i];
		}

		return maxSum;
	}

	void Calc(long[][] sumM, int s) {
		long max = Long.MIN_VALUE;

		for (int i = 0; i < s; i++) {
			for (int j = i; j < s; j++) {

				long[] singleRow = new long[s];

				for (int k = 0; k < s; k++) {

					if (i > 0)
						singleRow[k] = sumM[j][k] - sumM[i - 1][k];
					else
						singleRow[k] = sumM[i][k];

					long tempVal = MaxSumSingle(singleRow, s);

					if (tempVal > max)
						max = tempVal;
				}

			}
		}

		System.out.println(max);

	}

	void Run() {
		InputStream inStream = System.in;

		try {
		//	inStream = new FileInputStream(
		//			"C:\\Users\\user\\PersonalCode\\Algorithms\\UVA\\108\\Test.txt");
			Reader reader = new BufferedReader(new InputStreamReader(inStream));
			StreamTokenizer st = new StreamTokenizer(reader);

			st.nextToken();
			int s = (int) st.nval;

			long[][] bets = new long[s][s];

			for (int i = 0; i < s; i++) {
				for (int j = 0; j < s; j++) {
					st.nextToken();

					bets[i][j] = (long) st.nval;
					if (i > 0)
						bets[i][j] += bets[i - 1][j];
				}
			}

			Calc(bets, s);

		} catch (IOException e) {

		}
	}

	public static void main(String args[]) {
		(new Main()).Run();
	}
}
